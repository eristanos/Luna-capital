#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "declaration.h"
#include "affichage.h"

#define NB_CARTE_CONSTRUCTION_DECK 3
#define MAX_ELEMENT 300
#define NB_CHAR 30

int main()
{
    srand(time(NULL)); // permet d'initialsier le générateur pseudo aléatoire doit se faire qu'un seule fois au début d'un programme si vous utiliser la fonction rand()
    plein_ecran();
    system("pause");

    // initialisation pour test
    S_carte_construction carte_test;

    strcpy(carte_test.nom,"jean");
    carte_test.valeur = 12;
    carte_test.tuile[0].type=1;
    carte_test.tuile[1].type=0;
    carte_test.tuile[1].sous_type = 5;
    carte_test.tuile[2].type=0;
    carte_test.tuile[2].sous_type = 6;
    carte_test.tuile[3].type=0;
    carte_test.tuile[3].sous_type = 4;

    // fin initialisation pour test

    dessiner_carte_construction(5,5,carte_test);
    positionner_curseur(20,25);
    color(12,12);
    //printf(" ");
    color(15,0);
    return 0;
}
