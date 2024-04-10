#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "declaration.h"

#define PART_METEORITE 5
#define PART_VITAL 40
#define PART_VIDE 55

S_carte_construction generateur_carte()
{
    S_carte_construction carte;
    carte.type = rand() % NB_TYPE;
    carte.valeur = (rand() % VALEUR_NUM_MAX) + 1;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        // génération du type de tuile
        int stock1 = (rand() % (101));

        if(stock1 <= PART_METEORITE)
        {
            carte.tuile[i].type = 2;
        }
        else if(PART_METEORITE < stock1 && stock1 <= PART_VITAL+PART_METEORITE)
        {
            carte.tuile[i].type = 1;

            // génération du sous type de tuiles / couleur associée
            int stock2 = (rand() % 12) + 1;
            if(stock2 == 8)
            {
                stock2 = 14;
            }

            carte.tuile[i].sous_type = stock2;
        }
        else if(PART_VITAL + PART_METEORITE < stock1 && stock1<=PART_METEORITE + PART_VITAL + PART_VIDE)
        {
            carte.tuile[i].type = 0;
        }

    }
    return carte;
}
