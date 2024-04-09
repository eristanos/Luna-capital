#include <stdio.h>
#include "declaration.h"
#include "Saisie.h"

int  Saisie_Nb_Joueur()
{
    int n = 15464645;

    do
    {
    printf("Saisir le nombre de joueurs qui vont jouer");
    scanf("%d",&n);



    }while(1>n || n>5);
    return n;

}
