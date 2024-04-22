#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "declaration.h"


typedef struct proba
{
    int type;
    int part;
} S_proba;

S_carte_construction generateur_carte()
{
    S_carte_construction carte;
    carte.type = (rand() % NB_TYPE) + 1;
    carte.valeur = (rand() % VALEUR_NUM_MAX) + 1;
    int temp = 0;
    int somme_ponderation;

    for (int i = 0; i < NB_TUILE; i++)
    {
        // definition de la pondération
        S_proba tab_pond[NB_TYPE_TUILE_CARTE] = {{0,PART_VIDE_CARTE},{1, PART_VITAUX_CARTE},{2, PART_METEORITE_CARTE},{7, PART_ECHAFAUDAGE_CARTE}};
        // Tirage aléatoire
        temp = rand() % 101;
        somme_ponderation = 0;

        for(int y = 0 ; y < NB_TYPE_TUILE_CARTE; y++)
        {
            if(somme_ponderation < temp && temp < somme_ponderation + tab_pond[y].part)
            {
                carte.tuile[i].type = tab_pond[y].type;
                y = NB_TYPE_TUILE_CARTE;
            }
            somme_ponderation += tab_pond[y].part;
        }

        // génération du sous type dans le cas des vitaux
        if (carte.tuile[i].type == 1)
        {
            carte.tuile[i].sous_type = (rand() % NB_SOUS_TYPE_TUILE);
        }
    }
    return carte;
}

S_tuile generateur_tuile()
{
    S_tuile latuile;

    // definition de la pondération

    S_proba tab_pond[NB_TYPE_TUILE] = {{0,PART_DEMOLITION_TUILE},{1, PART_VITAUX_TUILE},{2, PART_METEORITE_TUILE},{3,PART_AGENCE_COMMERCIALE_TUILE},{4,PART_MODULE_HABITATION},{5, PART_COMPLEXE_RESIDENTIEL_TUILE},{6, PART_TERRAIN_ALUNISAGE_TUILE},{7, PART_ECHAFAUDAGE_CARTE}};
    // Tirage aléatoire

    int temp = rand() % 101;
    int somme_ponderation = 0;

    for(int y = 0 ; y < NB_TYPE_TUILE; y++)
    {
        if(somme_ponderation < temp && temp < somme_ponderation + tab_pond[y].part)
        {
            latuile.type = tab_pond[y].type;
            y = NB_TYPE_TUILE;
        }
        somme_ponderation += tab_pond[y].part;
    }

    // génération du sous type dans le cas des vitaux
    if (latuile.type == 1)
    {
        latuile.sous_type = (rand() % NB_SOUS_TYPE_TUILE);
    }
    return latuile;
}

S_concession generateur_concession()
{
    S_concession laconcession;

    // definition de la pondération
    S_proba tab_pond[TYPE_CONCESSION] = {{0,PART_3_ALIGNE},{1, PART_3_CARTE_COLONNE},{2, PART_4_CARRE},{3,PART_FINIR_PHASE},{4,PART_POSSEDER_n_CARTE},{5, PART_5_RANGE},{6, PART_8_CONSTRUCTION},{7, PART_MOINS_RANGE}};
    // Tirage aleatoire

    int temp = rand() % 101;
    int somme_ponderation = 0;
    for(int y = 0 ; y < TYPE_CONCESSION; y++)
    {
        if(somme_ponderation < temp && temp < somme_ponderation + tab_pond[y].part)
        {
            laconcession.type = tab_pond[y].type;
            y = TYPE_CONCESSION;
        }
        somme_ponderation += tab_pond[y].part;
    }
    // génération du sous type dans le cas des système vitaux
    srand(time(NULL));
    int nb_aleatoire = rand() % 6;

    switch(nb_aleatoire)
    {
    case 0:
        laconcession.tuile.type=1;
        laconcession.tuile.sous_type = 0;       // 0 = collecteur d'hydrogene
        if(laconcession.type == 0)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 7;
        }
        else
        {
            laconcession.points = 9;
        }
        break;
    case 1:
        laconcession.tuile.type=1;
        laconcession.tuile.sous_type = 1;        //1 = condenseurs d'eau
        if(laconcession.type == 0)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 8;
        }
        else
        {
            laconcession.points = 10;
        }
        break;

    case 2:
        laconcession.tuile.type=1;
        laconcession.tuile.sous_type = 2;        //2 = agences commerciales
        if(laconcession.type == 0)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 6;
        }
        else
        {
            laconcession.points = 8;
        }
        break;
    case 3:
        laconcession.tuile.type=1;
        laconcession.tuile.sous_type = 3;        //3 = collecteur oxygene
        if(laconcession.type == 0)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 7;
        }
        else
        {
            laconcession.points = 9;
        }
        break;
    case 4:
        laconcession.tuile.type=1;
        laconcession.tuile.sous_type = 4;        //4 = serre
        if(laconcession.type == 0)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 6;
        }
        else
        {
            laconcession.points = 10;
        }
        break;
    case 5:
        laconcession.tuile.type = 5;                  //5 = météorite
        if(laconcession.type == 0)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == 1)
        {
            laconcession.points = 6;
        }
        else
        {
            laconcession.points = 9;
        }
        break;

    }


    return laconcession;
}



