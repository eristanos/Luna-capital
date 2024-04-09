#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "declaration.h"
#include "affichage.h"
#include "declaration_cartes.h"
#include "Saisie.h"



int main()
{
    srand(time(NULL)); // permet d'initialsier le générateur pseudo aléatoire doit se faire qu'un seule fois au début d'un programme si vous utiliser la fonction rand()
    plein_ecran();
    system("pause");

    // initialisation pour test
    int nb_joueur = Saisie_Nb_Joueur();
    S_joueur tab_joueur[nb_joueur];
    Saisie_Nom_joueur(tab_joueur , nb_joueur);
    for(int i = 0; i < nb_joueur; i++)
    {
        printf("%s\n", tab_joueur[i].nom);
    }

    // test


    // affichage du message de fermeture de fenêtre
    positionner_curseur(20,25);
    color(15,0);
    return 0;
}
