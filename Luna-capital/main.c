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
    system("pause");

    // initialisation pour test
   /* S_joueur joueur;
    for(int i = 0 ; i < LARG_MAX_JEU; i++)
    {
        for(int y = 0; y < LONG_MAX_JEU; y++)
        {
            int temp = rand()%2;
            if(temp == 0)
            {
                joueur.jeu[i][y] = generateur_carte();
            }
            else
            {
                joueur.jeu[i][y].type = 0;
            }

        }
    }
    afficher_deck_joueurs(joueur);*/

    // test
    int i=0;
    while(i==0)
    {
        S_concession jeanne = generateur_concession();
        printf(" points : %d\n", jeanne.points);
        printf("type : %d\n", jeanne.type);
        printf("tuile : \n type : %d \n sous type : %d" , jeanne.tuile.type, jeanne.tuile.sous_type);
        system("pause");
    }

    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    printf("kakoukakou");
    return 0;
}
