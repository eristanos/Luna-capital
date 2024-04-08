#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "declaration.h"

S_carte_construction generateur_carte()
{
    srand(time(NULL));
    S_carte_construction carte;
    carte.type = rand() % NB_TYPE;
    carte.valeur = rand() % VALEUR_NUM_MAX;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        carte.tuile[i].type = rand() % NB_TYPE_TUILE;
        int stock = (rand() % 12) + 1;
        if(stock == 8)
        {
            stock = 14;
        }
        carte.tuile[i].sous_type = stock;

    }
    return carte;
}
