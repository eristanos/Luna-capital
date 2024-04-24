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

    // initialisation pour test
    S_joueur joueur;
    joueur.nb_selenite = 2;
    joueur.nb_tour_joueur = 0;
    for(int i = 0 ; i < LARG_MAX_JEU; i++)
    {
        for(int y = 0; y < LONG_MAX_JEU; y++)
        {
           joueur.jeu[i][y].type=0;
        }
    }
    afficher_deck_joueurs(joueur);

    int wsh = 0;
    while(wsh == 0)
    {
       placer_carte(&joueur, generateur_carte());
    afficher_deck_joueurs(joueur);
    printf("%d",joueur.jeu[0][0].valeur);
    }


    system("pause");


    // test


    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    printf("kakoukakou");
    return 0;
}
