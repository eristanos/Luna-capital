#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "declaration.h"
#include "saisie.h"
#include "declaration_cartes.h"
#include "affichage.h"


int  Saisie_Nb_Joueurs()
{
    int n;

    do
    {
    printf("Saisir le nombre de joueurs qui vont jouer : ");
    scanf("%d",&n);

    }while(1>n || n>5);
    return n;

}

void Saisie_Noms_Joueurs(S_joueur tab_joueur[] ,int nb_joueur)
{
    for(int i = 0; i < nb_joueur ; i++)
    {
        printf("Joueur %d , saisir votre nom : ", i+1);
        scanf("%s",tab_joueur[i].nom);
    }

}

void affectation_sponsor(S_joueur tab_joueur[] , int nb_joueur)
{
    for(int i = 0; i <nb_joueur ; i++)
    {
    printf("joueur %d, saisir votre sponsor (4.Rouge fonce 1.Bleu fonce 2.Vert fonce 14.Jaune) : ", i+1);
        scanf("%d", &tab_joueur[i].sponsor);
    }
}

int Saisie_coordonnees(int min , int max)
{
    int statut = 0;
    int i = -1;

    while(statut == 0)
     {
        positionner_curseur(ZONE_ECRITURE_HAUT + 5,ZONE_ECRITURE_GAUCHE);

        scanf("%d", &i);
        if(i > min && i <= max)
            {
                statut = 1;
            }
     }
     dessiner_rectangle(ZONE_ECRITURE_HAUT + 5,ZONE_ECRITURE_GAUCHE, 0 , LONG_MENU , 1);
    return (i-1);
}
int verif_emplacement(int x, int y, S_carte_construction tab[][LONG_MAX_JEU])
{
    if(tab[x][y].type == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int verif_ordre_carte(int x, int y, S_carte_construction tab[][LONG_MAX_JEU], int valeur_carte)
{
    for(int i = 0; i < x ; i++)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur != -1)
            {
                if(tab[i][y].valeur >= valeur_carte)
                {
                    positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);
                    printf("trop grand\n");
                    system("pause");
                    return 0;
                }
            }
        }
    }
    for(int i = LARG_MAX_JEU-1; i > x ; i--)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur != -1)
            {
                if(tab[i][y].valeur <= valeur_carte)
                {
                    positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);
                    printf("trop petit\n");
                    system("pause");
                    return 0;
                }
            }

        }
    }
    return 1;
}

int verif_adjacent(int x, int y, S_carte_construction tab[][LONG_MAX_JEU])
{
    int i =0;
    // verif haut

    if(y > 0)
    {
        if(tab[x][y-1].type == 1)
        {
            i = 1;
        }
    }

    // verif bas

    if(y < LONG_MAX_JEU-1)
    {
        if(tab[x][y+1].type == 1)
        {
            i = 1;
        }
    }

    // verif gauche

    if(x > 0)
    {
        if(tab[x - 1][y].type == 1)
        {
            i = 1;
        }
    }


    // verif droite
    if(x < LARG_MAX_JEU -1)
    {
        if(tab[x + 1][y].type == 1)
        {
            i = 1;
        }
    }
    if(i == 0)
    {

        positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);

        printf("non adjacent");

    }
    return(i);
}



void placer_carte(S_joueur *joueur)
{
    int etat = 0;
    // on choisit une carte
    afficher_menu(*joueur);
    afficher_deck_joueur(*joueur);
    color(15,0);
    positionner_curseur(ZONE_ECRITURE_HAUT, ZONE_ECRITURE_GAUCHE);
    printf("Prenez une carte :");
    int n;
    do
    {
        positionner_curseur(ZONE_ECRITURE_HAUT + 1,ZONE_ECRITURE_GAUCHE);
        scanf("%d" , &n);
    }while((n < 0) && (n > MAX_ELEMENT+1 && joueur->deck_cartes[n-1].type ==0 ));

    S_carte_construction carte = joueur->deck_cartes[n-1];
    joueur->deck_cartes[n-1].type = 0;
    afficher_menu(*joueur);

    // on place la carte
    while(etat == 0)
    {
        afficher_jeu_joueur(*joueur);
        positionner_curseur(ZONE_ECRITURE_HAUT + 1,ZONE_ECRITURE_GAUCHE);

        printf("valeur = %d" , carte.valeur);
        positionner_curseur(ZONE_ECRITURE_HAUT + 2,ZONE_ECRITURE_GAUCHE);

        printf("Saisir x : ");
        int x = Saisie_coordonnees(0,LARG_MAX_JEU);
        positionner_curseur(ZONE_ECRITURE_HAUT + 2,ZONE_ECRITURE_GAUCHE);
        printf("Saisir y : ");
        int y = Saisie_coordonnees(0,LONG_MAX_JEU);
        if(verif_emplacement(x,y,joueur->jeu) == 1 && (verif_adjacent(x,y,joueur->jeu) == 1 || joueur->carte_place == 0))
        {
            int n = 0;
            afficher_menu(*joueur);
            if(joueur->nb_selenite > 0)
            {
                positionner_curseur(ZONE_ECRITURE_HAUT + 2,ZONE_ECRITURE_GAUCHE);
                printf("utilisez un selenite ?");
                positionner_curseur(ZONE_ECRITURE_HAUT + 3,ZONE_ECRITURE_GAUCHE);
                printf("0 : NON , 1 : OUI");
                positionner_curseur(ZONE_ECRITURE_HAUT + 4,ZONE_ECRITURE_GAUCHE);
                scanf("%d" ,&n);

            }
            if(n == 1)
            {
                joueur->jeu[x][y] = carte;
                joueur->jeu[x][y].valeur = -1;
                printf("joueur %d", joueur->jeu[x][y].valeur);
                joueur->nb_selenite --;
                etat = 1;
                joueur->carte_place = joueur->carte_place -1;
            }
            else
            {
                if(verif_ordre_carte(x,y,joueur->jeu,carte.valeur) == 1)
                {
                    joueur->jeu[x][y] = carte;
                    joueur->carte_place = joueur->carte_place -1;
                    etat = 1;


                }
            }
        }
        else if(verif_emplacement(x,y,joueur->jeu) == 0)
        {
            positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);
            printf("case deja occupée");
            system("pause");

        }

    }
    afficher_jeu_joueur(*joueur);
}

void supprimer_carte(S_carte_construction tab[], int n)
{
    tab[n].type = 0;
    tab[n].valeur = 0 ;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        tab[n].tuile[i].type = 0;
        tab[n].tuile[i].sous_type = 0;
    }
}

void piocher_carte(S_plateau *plateau , S_joueur *joueur)
{
    positionner_curseur(ZONE_ECRITURE_HAUT + 1 ,ZONE_ECRITURE_GAUCHE);
    printf("Piochez une carte : ");
    positionner_curseur(ZONE_ECRITURE_HAUT + 2, ZONE_ECRITURE_GAUCHE);
    printf("Colonne : ");
    int n = Saisie_coordonnees(0,NB_CARTE_JEU);

    int temp;
    int temp1;
    for(int i=0;i<MAX_ELEMENT ;i++)
        {
            if(joueur->deck_cartes[i].type == VIDE)
            {
                temp=i;
                i=MAX_ELEMENT;
            }
        }
    joueur->deck_cartes[temp]=plateau->cartes[n];

    // on pioche les tuiles
    for(int t = 0; t < NB_TUILE ; t++)
    {
        if(plateau->tuiles[n][t].type != -1)
        {
            // on trouve une place
            for(int j=0;j<MAX_ELEMENT;j++)
            {
                if(joueur->deck_tuiles[j].type == VIDE)
                {
                    temp1=j;
                    j=MAX_ELEMENT;

                }
            }
            if(plateau->tuiles[n][t].selenite == 1)
            {
                joueur->nb_selenite++;
            }
            joueur->deck_tuiles[temp1] = plateau->tuiles[n][t];
            joueur->nb_tuile_deck++;
        }

    }
}


int verif_vide_tuile(S_carte_construction carte, int pos)
{
    if(carte.tuile[pos].type == VIDE)
    {
        return 1;
    }
    else if(carte.tuile[pos].type == DEMOLITION)
    {
        return 1;
    }
    else if(carte.tuile[pos].type == ECHAFAUDAGE)
    {
        return 2;
    }
    else{
        return 0;
    }
}


void placer_tuile(S_joueur *joueur)
{
    afficher_deck_joueur(*joueur);
    int n = joueur ->nb_tuile_deck;
    for(int i = 0; i < n; i++ )
    {
        int etat = 0;
        while(etat == 0)
        {
            afficher_menu(*joueur);
            positionner_curseur(ZONE_ECRITURE_HAUT,ZONE_ECRITURE_GAUCHE);
            printf("placer tuile %d" , i+1);

            positionner_curseur(ZONE_ECRITURE_HAUT + 1,ZONE_ECRITURE_GAUCHE);
            printf("Tuile : %s" , joueur->deck_tuiles[i].nom);




            // choix de la carte pour poser la tuile
            positionner_curseur(ZONE_ECRITURE_HAUT + 3,ZONE_ECRITURE_GAUCHE);
            printf("Choississez une carte : ");
            afficher_jeu_joueur(*joueur);

            positionner_curseur(ZONE_ECRITURE_HAUT + 4,ZONE_ECRITURE_GAUCHE);
            printf("Saisir x : ");
            int x = Saisie_coordonnees(0,LARG_MAX_JEU);

            positionner_curseur(ZONE_ECRITURE_HAUT + 4,ZONE_ECRITURE_GAUCHE);
            printf("Saisir y : ");
            int y = Saisie_coordonnees(0,LONG_MAX_JEU);


            if(verif_emplacement(x,y, joueur->jeu) == 0)
            {
                afficher_menu(*joueur);
                // choix de la tuile
                positionner_curseur(ZONE_ECRITURE_HAUT,ZONE_ECRITURE_GAUCHE);
                printf("Saisir position de la tuile");
                int pos = Saisie_coordonnees(0 , NB_TUILE);

                // vérification d'emplacement disponible
                if (joueur->deck_tuiles[i].type == MODULE || joueur->deck_tuiles[i].type == COMPLEXE || joueur->deck_tuiles[i].type == TERRAIN)
                {
                    if(verif_vide_tuile(joueur->jeu[x][y] , pos) == 1 ||verif_vide_tuile(joueur->jeu[x][y] , pos) == 2)
                    {
                        joueur->jeu[x][y].tuile[pos] = joueur ->deck_tuiles[i];
                        joueur ->deck_tuiles[i].type = 0;
                        afficher_jeu_joueur(*joueur);
                        etat = 1;
                    }

                }
                else if(verif_vide_tuile(joueur->jeu[x][y] , pos) == 1)
                    {
                        joueur->jeu[x][y].tuile[pos] = joueur ->deck_tuiles[i];
                        joueur ->deck_tuiles[i].type = 0;
                        afficher_jeu_joueur(*joueur);

                        etat = 1;
                    }
                else
                {
                    positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);
                    printf("case deja occupe");
                    system("pause");
                }

            }
            else
            {
                positionner_curseur(ZONE_ECRITURE_HAUT + 10,ZONE_ECRITURE_GAUCHE);
                printf("pas de carte ici ");
                system("pause");
            }
        }

    }
    joueur->nb_tuile_deck = 0;

}
