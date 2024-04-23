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
