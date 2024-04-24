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
    S_carte_construction tab[4];
    for(int i = 0; i < NB_TUILE; i++)
    {
        tab[i]= generateur_carte();
    }
    for(int i = 0; i < NB_TUILE; i++)
    {
        dessiner_carte_construction(0,i*LAR_CARTE + i, tab[i]);
    }
    system("pause");
    supprimer_carte(tab,2);
    supprimer_carte(tab , 0);

    for(int i = 0; i < NB_TUILE; i++)
    {
        dessiner_carte_construction(0,i*LAR_CARTE + i, tab[i]);
    }




    // test mathieu
    /*
    int i=0;
    while(i==0)
    {
        S_concession jeanne = generateur_concession();
        printf(" points : %d\n", jeanne.points);
        printf("type : %d\n", jeanne.type);
        printf("tuile : \n type : %d \n sous type : %d" , jeanne.tuile.type, jeanne.tuile.sous_type);
        system("pause");
    }
    */

    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    printf("kakoukakou");
    return 0;
}
