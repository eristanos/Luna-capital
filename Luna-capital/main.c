#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "declaration.h"
#include "affichage.h"
#include "declaration_cartes.h"



int main()
{
    srand(time(NULL)); // permet d'initialsier le g�n�rateur pseudo al�atoire doit se faire qu'un seule fois au d�but d'un programme si vous utiliser la fonction rand()
    plein_ecran();
    system("pause");

    // initialisation pour test
    S_carte_construction carte_test[MAX_ELEMENT];
    for(int i = 0; i < MAX_ELEMENT ; i++)
    {
        carte_test[i] = generateur_carte();
        dessiner_carte_construction(5,1 + i*(LAR_CARTE+1),carte_test[i]);

    }

    // test


    // affichage du message de fermeture de fen�tre
    positionner_curseur(20,25);
    color(15,0);
    return 0;
}
