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

    jeu();




    // affichage du message de fermeture de fenêtre
    positionner_curseur(40,0);
    color(15,0);
    return 0;
}
