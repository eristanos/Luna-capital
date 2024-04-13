#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "declaration.h"

#define PART_METEORITE_CARTE 5
#define PART_VITAUX_CARTE 40
#define PART_VIDE_CARTE 50
#define PART_ECHAFAUDAGE_CARTE 5

#define PART_VITAUX_TUILE 30

S_carte_construction generateur_carte()
{
    S_carte_construction carte;
    carte.type = rand() % NB_TYPE;
    carte.valeur = (rand() % VALEUR_NUM_MAX) + 1;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        // génération du type de tuile
        int stock1 = (rand() % (101));

        if(stock1 <= PART_METEORITE_CARTE)
        {
            carte.tuile[i].type = 2;
        }
        else if(PART_METEORITE_CARTE < stock1 && stock1 <= PART_VITAUX_CARTE+PART_METEORITE_CARTE)
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
        else if(PART_VITAUX_CARTE + PART_METEORITE_CARTE < stock1 && stock1<=PART_METEORITE_CARTE + PART_VITAUX_CARTE + PART_VIDE_CARTE)
        {
            carte.tuile[i].type = 0;
        }
        else if(PART_VITAUX_CARTE + PART_METEORITE_CARTE + PART_VIDE_CARTE < stock1 && stock1<=PART_METEORITE_CARTE + PART_VITAUX_CARTE + PART_VIDE_CARTE + PART_ECHAFAUDAGE_CARTE)
        {
            carte.tuile[i].type = 0;
        }

    }
    return carte;
}



