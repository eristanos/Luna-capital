#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"
#include "declaration_cartes.h"
#include "Saisie.h"
#include "affichage.h"
#include "declaration_cartes.h"
#include "verification.h"



void jeu()
{
    int nb_joueur = Saisie_Nb_Joueurs();
    S_joueur joueurs[nb_joueur];
    S_plateau plateau;
    initialiser_jeu(joueurs , &plateau , nb_joueur);
    // phase de jeu
    for(int phase = 0 ; phase < NB_PHASE ; phase ++)
    {
        for(int tour = 0 ; tour < NB_TOUR; tour ++)
        {

            for(int joueur_joue = 0 ;joueur_joue <nb_joueur; joueur_joue++)
            {
                generer_plateau(&plateau , tour);
                tour_jeu(&joueurs[joueur_joue], &plateau);
            }

        }
        for(int joueur_joue = 0 ;joueur_joue <nb_joueur; joueur_joue++)
        {
            afficher_menu(joueurs[joueur_joue]);
            positionner_curseur(ZONE_ECRITURE_HAUT , ZONE_ECRITURE_GAUCHE);
            printf("Voulez vous revendiquez une concession ? ");
            positionner_curseur(ZONE_ECRITURE_HAUT + 3,ZONE_ECRITURE_GAUCHE);
            int n;
            printf("0 : NON , 1 : OUI");
            positionner_curseur(ZONE_ECRITURE_HAUT + 4,ZONE_ECRITURE_GAUCHE);
            scanf("%d" ,&n);
            if(n == 1)
            {
                int etat = 0;
                do
                {

                    afficher_carte_concession(plateau.tab_cartes_concession);
                    afficher_menu(joueurs[joueur_joue]);

                    positionner_curseur(ZONE_ECRITURE_HAUT , ZONE_ECRITURE_GAUCHE);
                    printf("choisir une concession : ");
                    positionner_curseur(ZONE_ECRITURE_HAUT+1 , ZONE_ECRITURE_GAUCHE);
                    printf("Saisir 4 pour sortir");
                    int choix = Saisie_coordonnees(0 , NB_CONCESSION+1);
                    if(choix == 3)
                    {
                        etat = 1;
                    }
                    else
                    {
                        if(verif_concession(joueurs[joueur_joue].jeu ,plateau.tab_cartes_concession[choix])== 1)
                        {
                            joueurs[joueur_joue].point += plateau.tab_cartes_concession[choix].points;
                            plateau.tab_cartes_concession[choix].etat = 1;
                        }
                        else
                        {
                            positionner_curseur(ZONE_ECRITURE_HAUT + 2 , ZONE_ECRITURE_GAUCHE);
                            printf("Vous n'avez pas valide cette concession");
                        }
                    }
                }while(etat == 0);
            }
        }


    }
    for(int joueur_joue = 0 ;joueur_joue <nb_joueur; joueur_joue++)
        {
            joueurs[joueur_joue].point += calcul_point(joueurs[joueur_joue]);
        }

    // comparaison météorite : On donne 10 au joueurs avec le plus de météorite
    S_tuile meteorite;
    meteorite.type = METEORITE;
    meteorite.sous_type = 0;
    int tempm = 0;
    for(int i = 0 ; i < nb_joueur ; i++)
    {
        if(calcul_nb_tuile(joueurs[i].jeu , meteorite) > calcul_nb_tuile(joueurs[tempm].jeu , meteorite))
        {
            tempm = i;
        }
    }
    joueurs[tempm].point += 10;


    int temp = 0;
    int temp_j;
    for(int joueur_joue = 0 ;joueur_joue <nb_joueur; joueur_joue++)
    {
        if(joueurs[joueur_joue].point > temp)
        {
            temp = joueurs[joueur_joue].point;
            temp_j = joueur_joue;
        }
    }
    dessiner_rectangle(0,0,0,LONG_WINDOWS , LARG_WINDOWS);
    positionner_curseur(0,0);
    printf("Le gagnant est : %s avec %d points" , joueurs[temp_j].nom , joueurs[temp_j].point);
}

void initialiser_jeu(S_joueur tab_joueur[] , S_plateau *plateau , int nb_joueur)
{
    printf("initialisation\n");

    // on demande les noms des différents joueurs : le premier à saisir commencera
    Saisie_Noms_Joueurs(tab_joueur , nb_joueur);
    affectation_sponsor(tab_joueur , nb_joueur);
    // on genère le tableau de concessions
    for(int i = 0 ; i < NB_CONCESSION ; i++)
    {
        plateau->tab_cartes_concession[i] = generateur_concession();
    }



    // on supprime les éventuels donnéees de la mémoire
    for(int i = 0; i < nb_joueur ; i++)
    {
        tab_joueur[i].nb_selenite = 0;
        tab_joueur[i].nb_tuile_deck = 0;
        tab_joueur[i].carte_place = 0;

        // on vide son tableau de jeu
        for(int x = 0; x < LARG_MAX_JEU ; x++ )
        {
            for(int y = 0; y < LONG_MAX_JEU ; y++)
            {
                tab_joueur[i].jeu[x][y].type = 0;
                tab_joueur[i].jeu[x][y].valeur = 0;
                for(int pos =0 ; pos < NB_TUILE ; pos ++)
                {
                    tab_joueur[i].jeu[x][y].tuile[pos].type = 0;
                    tab_joueur[i].jeu[x][y].tuile[pos].sous_type = 0;
                }
            }
        }

        for(int n = 0 ; n < MAX_ELEMENT ; n++)
        {
            if(n < 3)
            {
                tab_joueur[i].deck_cartes[n] = generateur_carte();

            }
            else
            {
                tab_joueur[i].deck_cartes[n].type = 0;
                tab_joueur[i].deck_cartes[n].valeur = 0;

                for(int pos =0 ; pos < NB_TUILE ; pos ++)
                {
                    tab_joueur[i].deck_cartes[n].tuile[pos].type = 0;
                    tab_joueur[i].deck_cartes[n].tuile[pos].sous_type = 0;
                }
            }
            tab_joueur[i].deck_tuiles[n].type = 0;
            tab_joueur[i].deck_tuiles[n].sous_type = 0;

        }
        for(int i =0 ; i < NB_CARTE_JEU ; i++)
        {
            plateau->cartes[i] = generateur_carte();
            for(int y = 0 ; y < NB_TUILE ; y++)
            {

                plateau->tuiles[i][y].type = PAS_TUILE;

            }
        }
    }
}

void tour_jeu(S_joueur *joueur , S_plateau *plateau)
{
    afficher_plateau(*plateau);
    afficher_menu(*joueur);
    piocher_carte(plateau , joueur);
    placer_carte(joueur);
    choix_actions(joueur , plateau);
}
