  #include <stdio.h>
#include <stdlib.h>
#include "jeux.h"
#include "declaration_cartes.h"
#include "Saisie.h"


void initialiser_jeu(S_joueur tab_joueur[] , S_plateau *plateau , int nb_joueur)
{
    printf("initialisation");
    // on demande les noms des différents joueurs : le premier à saisir commencera
    //Saisie_Noms_Joueurs(tab_joueur , nb_joueur);
    //affectation_sponsor(tab_joueur , nb_joueur);
    // on supprime les éventuels donnéees de la mémoire
    for(int i = 0; i < nb_joueur ; i++)
    {
        tab_joueur[i].nb_carte_jeu = 0;
        tab_joueur[i].nb_selenite = 0;
        tab_joueur[i].nb_tour_joueur = 0;

        // on vide son tableau de jeu
        for(int x = 0; x < LARG_MAX_JEU ; x++ )
        {
            for(int y = 0; y < LONG_MAX_JEU ; y++)
            {
                tab_joueur[i].jeu[x][y].type = 0;
                tab_joueur[i].jeu[x][y].valeur = 0;
                for(int pos =0 ; pos < NB_TUILE ; pos ++)
                {
                    tab_joueur[i].jeu[x][y].tuile[pos].type = 0;
                    tab_joueur[i].jeu[x][y].tuile[pos].sous_type = 0;
                }
            }
        }
        for(int n = 0 ; n < MAX_ELEMENT ; n++)
        {
            if(n < 3)
            {
                tab_joueur[i].deck_cartes[n] = generateur_carte();
                tab_joueur[i].nb_carte_deck ++;
            }
            else
            {
                tab_joueur[i].deck_cartes[n].type = 0;
                tab_joueur[i].deck_cartes[n].valeur = 0;

                for(int pos =0 ; pos < NB_TUILE ; pos ++)
                {
                    tab_joueur[i].deck_cartes[n].tuile[pos].type = 0;
                    tab_joueur[i].deck_cartes[n].tuile[pos].sous_type = 0;
                }
            }
            tab_joueur[i].deck_tuiles[n].type = 0;
            tab_joueur[i].deck_tuiles[n].sous_type = 0;

        }
        for(int i =0 ; i < NB_CARTE_JEU ; i++)
        {
            plateau->cartes[i] = generateur_carte();
            plateau->tuiles[i] = generateur_tuile();
        }
    }

}
