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
    srand(time(NULL)); // permet d'initialsier le g�n�rateur pseudo al�atoire doit se faire qu'un seule fois au d�but d'un programme si vous utiliser la fonction rand()
    plein_ecran();
    system("pause");

    S_carte_construction carte_test;

    strcpy(carte_test.nom,"jean");
    carte_test.valeur = 12;

    dessiner_carte_construction(5,5,carte_test);

    positionner_curseur(20,25);
    color(12,12);
    //printf(" ");
    color(15,0);
    return 0;
}
