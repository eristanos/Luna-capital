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
    srand(time(NULL)); // permet d'initialsier le g�n�rateur pseudo al�atoire doit se faire qu'un seule fois au d�but d'un programme si vous utiliser la fonction rand()
    plein_ecran();
    system("pause");

    // initialisation pour test
    for(int i = 0; i < 500 ; i++)
    {

        positionner_curseur(20,25);
        color(15,0);
        system("pause");
    }

    // test


    // affichage du message de fermeture de fen�tre
    positionner_curseur(20,25);
    color(15,0);
    return 0;
}
