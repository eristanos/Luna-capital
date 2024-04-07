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

    dessiner_rectangle(10,10,12,10,10);
    color(15,0);
    return 0;
}
