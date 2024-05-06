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
    carte.type = 1;
    carte.valeur = (rand() % VALEUR_NUM_MAX) + 1;
    int temp = 0;
    int somme_ponderation;

    for (int i = 0; i < NB_TUILE; i++)
    {
        // definition de la pondération
        S_proba tab_pond[NB_TYPE_TUILE_CARTE] = {{VIDE,PART_VIDE_CARTE},{VITAUX, PART_VITAUX_CARTE},{METEORITE, PART_METEORITE_CARTE},{ECHAFAUDAGE, PART_ECHAFAUDAGE_CARTE}};
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
        if (carte.tuile[i].type == VITAUX)
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

    S_proba tab_pond[NB_TYPE_TUILE] = {{DEMOLITION,PART_DEMOLITION_TUILE},{VITAUX, PART_VITAUX_TUILE},{METEORITE, PART_METEORITE_TUILE},{AGENCE,PART_AGENCE_COMMERCIALE_TUILE},{MODULE,PART_MODULE_HABITATION},{COMPLEXE, PART_COMPLEXE_RESIDENTIEL_TUILE},{TERRAIN, PART_TERRAIN_ALUNISAGE_TUILE},{ECHAFAUDAGE, PART_ECHAFAUDAGE_CARTE}};
    // Tirage aléatoire

    int temp = rand() % 101;
    int somme_ponderation = 0;
    int aleatoire = rand() % 10;
    if(aleatoire == 0)
    {
        latuile.selenite = 1;
    }
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
    S_proba tab_pond[TYPE_CONCESSION] = {{C_ALIGNE,PART_3_ALIGNE},{C_COLONNE, PART_3_CARTE_COLONNE},{C_N_CARTE,PART_POSSEDER_n_CARTE}};
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
    int nb_aleatoire = rand() % 3;

    switch(nb_aleatoire)
    {
    case 0:
        laconcession.tuile.type=VITAUX;
        laconcession.tuile.sous_type = COLLECTEUR_HYDROGENE;       // 0 = collecteur d'hydrogene
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == C_COLONNE)
        {
            laconcession.points = 7;
        }
        else
        {
            laconcession.points = 9;
        }
        break;
    case 1:
        laconcession.tuile.type=VITAUX;
        laconcession.tuile.sous_type = CONDENSEUR_EAU;        //1 = condenseurs d'eau
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == C_COLONNE)
        {
            laconcession.points = 8;
        }
        else
        {
            laconcession.points = 10;
        }
        break;

    case 2:
        laconcession.tuile.type=AGENCE;
                                        //2 = agences commerciales
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == C_COLONNE)
        {
            laconcession.points = 6;
        }
        else
        {
            laconcession.points = 8;
        }
        break;
    case 3:
        laconcession.tuile.type=VITAUX;
        laconcession.tuile.sous_type = COLLECTEUR_OXYGENE;        //3 = collecteur oxygene
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 6;
        }
        else if(laconcession.type == C_COLONNE)
        {
            laconcession.points = 7;
        }
        else
        {
            laconcession.points = 9;
        }
        break;
    case 4:
        laconcession.tuile.type=VITAUX;
        laconcession.tuile.sous_type = SERRE_1;        //4 = serre
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == C_COLONNE)
        {
            laconcession.points = 6;
        }
        else
        {
            laconcession.points = 10;
        }
        break;
    case 5:
        laconcession.tuile.type = METEORITE;                  //2= météorite
        if(laconcession.type == C_ALIGNE)
        {
            laconcession.points = 7;
        }
        else if(laconcession.type == C_COLONNE)
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



