#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "declaration.h"
#include "affichage.h"
#include "declaration_cartes.h"
#include "saisie.h"
#include "jeux.h"
#include "verification.h"


int main()
{
    srand(time(NULL)); // permet d'initialsier le générateur pseudo aléatoire doit se faire qu'un seule fois au début d'un programme si vous utiliser la fonction rand()
    plein_ecran();


    // test paul





    /*
    for(int i =0; i < 3; i++)
    {
        joueurs[0].deck_tuiles[i] = generateur_tuile();
        joueurs[0].nb_tuile_deck++;
    }
    for(int i = 3; i < 10 ; i++)
    {
        joueurs[0].deck_tuiles[i].type = 0;

    }


    for(int x = 0 ; x < LARG_MAX_JEU; x++)
        {
        for(int y = 0; y < LONG_MAX_JEU; y++)
        {
            joueurs[0].jeu[x][y] = generateur_carte();
        }
    }

    int esfdf = 0;
    joueurs[0].nb_tuile_deck = 3;
    while(esfdf == 0)
    {
        tour_jeu(&joueurs[0] , &plateau);
        esfdf = 1;
    }


    for(int i=0;i<5;i++)
    {
        plateau.tab_cartes_concession[i]=generateur_concession();
    }




    S_joueur joueur;
    joueur.nb_selenite = 2;
    joueur.nb_tour_joueur = 0;    S_plateau plateau;
    for(int i = 0; i < 4; i++)
    {
        joueur.deck_cartes[i].type = 0;
        joueur.deck_tuiles[i].type = 0;
        for(int y = 0; y < 4; y++)
        {
            joueur.deck_cartes[i].tuile[i].type = 0;
        }
    }
    for(int i=0;i<4;i++)
    {

        plateau.cartes[i]=generateur_carte();
        plateau.tuiles[i]=generateur_tuile();
        dessiner_carte_construction(0,i*LAR_CARTE + i, plateau.cartes[i]);
        dessiner_tuile(12,i*LAR_CARTE + i , plateau.tuiles[i]);

    }
    // test mathieu
    int dsfcf =0;
    while(dsfcf ==0)
    {






    piocher_carte( &plateau, &joueur);

    for(int i=0;i<4;i++)
    {

        dessiner_carte_construction(20,i*LAR_CARTE + i, joueur.deck_cartes[i]);
        dessiner_tuile(34,i*LAR_CARTE + i , joueur.deck_tuiles[i]);
        color(15,0);
        dessiner_carte_construction(0,i*LAR_CARTE + i, plateau.cartes[i]);
        dessiner_tuile(12,i*LAR_CARTE + i , plateau.tuiles[i]);

    }
    }



    // vrai programme NE JAMAIS SUPPRIMER OU TES UN HOMME MORT
    */

    jeu();

    /*
     S_joueur joueur[2];

     initialiser_jeu(&joueur, &plateau,2);
     for(int x = 0; x < LARG_MAX_JEU ; x++ )
        {
            for(int y = 0; y < LONG_MAX_JEU ; y++)
            {
                int temp = rand() % 2;
                if(temp==0)
                {
                    joueur[0].jeu[x][y] = generateur_carte();
                }

            }
    }
     afficher_jeu_joueur(joueur[0]);
     positionner_curseur(50,50);
     color(2,5);
     printf( "ici----------%d-----------------ici", calcul_nb_construction(joueur[0].jeu));

    */
    // vrai programme NE JAMAIS SUPPRIMER OU TES UN HOMME MORT
    /*

    int nb_joueur = Saisie_Nb_Joueurs();
    S_joueur joueurs[nb_joueur];
    S_plateau plateau;
    initialiser_jeu(joueurs , &plateau , nb_joueur);
    afficher_menu(joueurs[0]);
    */




    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    return 0;
}
