#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "declaration.h"

S_carte_construction generateur_carte()
{
    struct timeb t;
    ftime(&t);
    srand(1000. * t.time + t.millitm);

    S_carte_construction carte;
    carte.type = rand() % NB_TYPE;
    carte.valeur = (rand() % VALEUR_NUM_MAX) + 1;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        int stock1 = (rand() % (NB_TYPE_TUILE + 4));
        if(stock1 > NB_TYPE_TUILE)
        {
            stock1 = 0;
        }
        carte.tuile[i].type = stock1;
        int stock2 = (rand() % 12) + 1;
        if(stock2 == 8)
        {
            stock2 = 14;
        }

        carte.tuile[i].sous_type = stock2;

    }
    return carte;
}
