#include <stdio.h>
#include "declaration.h"


int calcul_nb_construction(S_carte_construction tab[][LONG_MAX_JEU])
{
    int nb;
    for(int i=0; i<LARG_MAX_JEU; i++)
    {
        for(int y=0; y<LONG_MAX_JEU;y++)
        {
            if(tab[i][y].type == 1)
            {
                nb++;

            }
            printf("x :%d , y : %d, etat : %d\n", i,y,tab[i][y].type);
        }

    }
    return nb;
}
