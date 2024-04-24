#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "declaration.h"
#include "affichage.h"
#include "declaration_cartes.h"
#include "saisie.h"



int main()
{
    srand(time(NULL)); // permet d'initialsier le générateur pseudo aléatoire doit se faire qu'un seule fois au début d'un programme si vous utiliser la fonction rand()
    plein_ecran();

    // test paul

    /*
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
    */



    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    printf("kakoukakou");
    return 0;
}
