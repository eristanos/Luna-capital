#include <stdio.h>
#include "declaration.h"
#include "verification.h"



int calcul_point(S_joueur joueur)
{

}

int verif_concession(S_carte_construction jeu[LARG_MAX_JEU][LONG_MAX_JEU] ,S_concession concession)
{
    switch(concession.type)
    {
    case C_COLONNE :
        if(verif_carte_colonne(jeu , concession) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
    case C_ALIGNE :
        if(verif_tuile_aligne(jeu , concession.tuile) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
    case C_5_TUILE :
        break;
    }
    return 0;
}


int calcul_nb_construction(S_carte_construction tab[][LONG_MAX_JEU])
{
    int nb = 0;
    for(int i = 0; i < LARG_MAX_JEU ; i++)
    {
        for(int y=0; y<LONG_MAX_JEU;y++)
        {
            if(tab[i][y].type == 1)
            {
                nb++;

            }
        }
    }
    return nb;
}

int verif_carte_colonne(S_carte_construction jeu[][LONG_MAX_JEU] , S_concession concession)
{
    for(int x  = 0 ; x < LARG_MAX_JEU ; x++)
    {
        for(int pos = 0 ; pos < NB_TUILE ; pos++)
        {
           // cas des vitaux
            if(jeu[x][1].tuile [pos].type == concession.tuile.type && jeu[x][1].tuile[pos].sous_type == concession.tuile.sous_type)
            {
                for(int posh = 0 ; posh < NB_TUILE ; posh ++)
                {
                    if(jeu[x-1][1].tuile [posh].type == concession.tuile.type && jeu[x-1][1].tuile[posh].sous_type == concession.tuile.sous_type)
                    {
                        for(int posb = 0 ; posb < NB_TUILE ; posb ++)
                        {
                           if(jeu[x+1][1].tuile [posb].type == concession.tuile.type && jeu[x+1][1].tuile[posb].sous_type == concession.tuile.sous_type)
                            {
                            return 1;           // on vérifie seulement le milieu d'une colonne pour limiter le nombre d'itération du programme
                            }
                        }
                    }
                }

            }
            if(jeu[x][1].tuile [pos].type == concession.tuile.type && jeu[x][1].tuile[pos].type == METEORITE)
            {
                if(jeu[x-1][1].tuile [pos].type == concession.tuile.type)
                {
                    if(jeu[x+1][1].tuile [pos].type == concession.tuile.type)
                    {
                        return 1;           // on vérifie seulement le milieu d'une colonne pour limiter le nombre d'itération du programme
                    }
                }
            }
        }
    }
    return 0;
}

int verif_tuile_aligne(S_carte_construction tab_jeu[LARG_MAX_JEU][LONG_MAX_JEU] , S_tuile tuile)
{
    // on genere un tableau plus adpate au comptage
    S_verif tab_verif[LARG_MAX_JEU*2][LONG_MAX_JEU*2];

    for(int x = 0 ; x < LARG_MAX_JEU ; x++)
    {
        for(int y = 0 ; y < LONG_MAX_JEU ; y++)
        {
            if(tab_jeu[x][y].type == 1)
            {
                for(int pos = 0 ; pos < NB_TUILE ; pos ++)
                {
                    if(tab_jeu[x][y].tuile[pos].type == tuile.type && tab_jeu[x][y].tuile[pos].sous_type == tuile.sous_type)  // limitons seulement au tuile nous intéressant
                    {
                        switch(pos)
                        {
                            case 0:
                                tab_verif[x*2][y*2].valeur = 1;
                                tab_verif[x*2][y*2].etat = 0;

                                break;
                            case 1:
                                tab_verif[x*2+1][y*2].valeur = 1;
                                tab_verif[x*2+1][y*2].etat = 0;
                                break;
                            case 2:
                                tab_verif[x*2][y*2+1].valeur = 1;
                                tab_verif[x*2][y*2+1].etat = 0;
                                break;
                            case 3:
                                tab_verif[x*2+1][y*2+1].valeur = 1;
                                tab_verif[x*2+1][y*2+1].etat = 0;
                                break;
                        }
                    }
                    else
                    {
                        switch(pos)
                        {
                            case 0:
                                tab_verif[x*2][y*2].valeur = 0;
                                tab_verif[x*2][y*2].etat = 0;

                                break;
                            case 1:
                                tab_verif[x*2+1][y*2].valeur = 0;
                                tab_verif[x*2+1][y*2].etat = 0;
                                break;
                            case 2:
                                tab_verif[x*2][y*2+1].valeur = 0;
                                tab_verif[x*2][y*2+1].etat = 0;
                                break;
                            case 3:
                                tab_verif[x*2+1][y*2+1].valeur = 0;
                                tab_verif[x*2+1][y*2+1].etat = 0;
                                break;
                        }
                    }
                }
            }

            else
            {
                tab_verif[x*2][y*2].valeur = 0;
                tab_verif[x*2][y*2].etat = 0;

                tab_verif[x*2+1][y*2].valeur = 0;
                tab_verif[x*2+1][y*2].etat = 0;

                tab_verif[x*2][y*2+1].valeur = 0;
                tab_verif[x*2][y*2+1].etat = 0;

                tab_verif[x*2+1][y*2+1].valeur = 0;
                tab_verif[x*2+1][y*2+1].etat = 0;
            }
        }
    }

    // lisons maintenant le tableau juste crée

    for(int x = 0 ; x < LARG_MAX_JEU*2 ; x++)
    {
        for(int y = 0 ; y < LONG_MAX_JEU*2 ; y++)
        {
            if(x < 0 && x < LARG_MAX_JEU -1)        // On verifie à partir du centre pour les horizontales
            {
                if(tab_verif[x][y].valeur == 1 && tab_verif[x-1][y].valeur == 1 && tab_verif[x+1][y].valeur == 1)
                   {
                       return 1;
                   }
            }
            if(y < 0 && y < LONG_MAX_JEU -1)        // On verifie à partir du centre pour les horizontales
            {
                if(tab_verif[x][y].valeur == 1 && tab_verif[x][y-1].valeur == 1 && tab_verif[x][y+1].valeur == 1)
                   {
                       return 1;
                   }
            }
        }
    }
    return 0;
}


int place_tab(S_co tab[])
{
    for(int i =0 ; i < MAX_TUILE_VERIF; i++)
    {
        if(tab[i].x == -1)
        {
            return(i);

        }
    }
    return(-1);
}

int calcul_plus_grand_ensemble(S_carte_construction tab_jeu[][LONG_MAX_JEU] , int sous_type_r)
{
    // on crée un tableau plus adapté contenant seulement 1 quand on à la tuile recherché 0 sinon
    S_verif tab_verif[LARG_MAX_JEU*2][LONG_MAX_JEU*2];

    for(int x = 0 ; x < LARG_MAX_JEU ; x++)
    {
        for(int y = 0 ; y < LONG_MAX_JEU ; y++)
        {
            if(tab_jeu[x][y].type == 1)
            {
                for(int pos = 0 ; pos < NB_TUILE ; pos ++)
                {
                    if(tab_jeu[x][y].tuile[pos].type == VITAUX && tab_jeu[x][y].tuile[pos].sous_type == sous_type_r)  // limitons seulement au tuile nous intéressant
                    {
                        switch(pos)
                        {
                            case 0:
                                tab_verif[x*2][y*2].valeur = 1;
                                tab_verif[x*2][y*2].etat = 0;

                                break;
                            case 1:
                                tab_verif[x*2+1][y*2].valeur = 1;
                                tab_verif[x*2+1][y*2].etat = 0;
                                break;
                            case 2:
                                tab_verif[x*2][y*2+1].valeur = 1;
                                tab_verif[x*2][y*2+1].etat = 0;
                                break;
                            case 3:
                                tab_verif[x*2+1][y*2+1].valeur = 1;
                                tab_verif[x*2+1][y*2+1].etat = 0;
                                break;
                        }
                    }
                    else
                    {
                        switch(pos)
                        {
                            case 0:
                                tab_verif[x*2][y*2].valeur = 0;
                                tab_verif[x*2][y*2].etat = 0;

                                break;
                            case 1:
                                tab_verif[x*2+1][y*2].valeur = 0;
                                tab_verif[x*2+1][y*2].etat = 0;
                                break;
                            case 2:
                                tab_verif[x*2][y*2+1].valeur = 0;
                                tab_verif[x*2][y*2+1].etat = 0;
                                break;
                            case 3:
                                tab_verif[x*2+1][y*2+1].valeur = 0;
                                tab_verif[x*2+1][y*2+1].etat = 0;
                                break;
                        }
                    }
                }
            }

            else
            {
                tab_verif[x*2][y*2].valeur = 0;
                tab_verif[x*2][y*2].etat = 0;

                tab_verif[x*2+1][y*2].valeur = 0;
                tab_verif[x*2+1][y*2].etat = 0;

                tab_verif[x*2][y*2+1].valeur = 0;
                tab_verif[x*2][y*2+1].etat = 0;

                tab_verif[x*2+1][y*2+1].valeur = 0;
                tab_verif[x*2+1][y*2+1].etat = 0;
            }
        }
    }


    int taille_ensemble = 0;

    // parcourons le tableau pour trouver une carte du type recherché



    for(int x = 0 ; x < LARG_MAX_JEU * 2; x++)
    {
        for(int y = 0 ; y < LONG_MAX_JEU * 2; y++)
        {
            if(tab_verif[x][y].valeur == 1 && tab_verif[x][y].etat == 0)
            {
                // programme calculant la taille de l'ensemble de cette tuile

                int compteur_temp = 1; // au moin une tuile
                tab_verif[x][y].etat = 1;
                int fini = 1;


                // on initialise un tableau des coordonnéees à vérifier : -1 est un caractère de rupture
                S_co tab_co[MAX_TUILE_VERIF];
                for(int i = 0 ; i < MAX_TUILE_VERIF ; i++)
                {
                    tab_co[i].x = -1;
                    tab_co[i].y = -1;
                }

                // on met les coordonnées de notres première tuile dans le tableau
                tab_co[0].x = x;
                tab_co[0].y = y;


                // ajout des tuiles adjacente à la file d'attente si elles sont du même type
                while(fini == 1)
                {
                    //on va utiliser les  derniers coordonnées du tableau
                    // on considère que les -1 sont forcémments dans la dernière partie du tableau
                    int ya;
                    int xa;
                    int temp = -1;
                    for(int i = 0; i < MAX_TUILE_VERIF ; i++)
                    {
                        if(tab_co[i].x != -1)
                        {
                            xa = tab_co[i].x;
                            ya = tab_co[i].y;
                            temp = i; // on garde en mémoire l'emplacement de la dernière case pour supprimer les coordonnées
                        }
                        else
                        {
                            i = MAX_TUILE_VERIF;
                        }

                    }
                    if(temp == -1)
                    {
                        // on arrete quand le tableau est vide
                        fini = 0;
                    }
                    else
                    {
                        tab_co[temp].x = -1;
                        tab_co[temp].y = -1;
                        tab_verif[xa][ya].etat = 1;

                        // on a maintenant un coordonnée : vérifions les tuiles adjacentes
                        // haut
                        if(ya > 0)
                        {
                           if(tab_verif[xa][ya-1].valeur == 1 && tab_verif[xa][ya-1].etat == 0)
                           {
                               tab_verif[xa][ya-1].etat = -1;
                               compteur_temp ++;
                               int place  = place_tab(tab_co);
                               tab_co[place].x = xa;
                               tab_co[place].y = ya-1;

                           }
                        }

                        // bas
                        if(ya < (LONG_MAX_JEU*2)-1)
                        {
                            if(tab_verif[xa][ya+1].valeur == 1 && tab_verif[xa][ya+1].etat == 0)
                            {
                                tab_verif[xa][ya+1].etat = -1;
                                compteur_temp ++;
                                int place  = place_tab(tab_co);
                                tab_co[place].x = xa;
                                tab_co[place].y = ya+1;
                            }
                        }

                        // gauche

                        if(xa > 0)
                        {
                            if(tab_verif[xa-1][ya].valeur == 1 &&  tab_verif[xa-1][ya].etat == 0)
                            {
                                tab_verif[xa-1][ya].etat = -1;
                                compteur_temp ++;
                                int place  = place_tab(tab_co);
                                tab_co[place].x = xa-1;
                                tab_co[place].y = ya;
                            }
                        }

                        // droite

                        if(xa < (LARG_MAX_JEU*2)-1)
                        {
                            if(tab_verif[xa+1][ya].valeur == 1 && tab_verif[xa+1][ya].etat == 0)
                            {
                                tab_verif[xa+1][ya].etat = -1;
                                compteur_temp ++;
                                int place  = place_tab(tab_co);
                                tab_co[place].x = xa+1;
                                tab_co[place].y = ya;
                            }
                        }
                    }
                }
                printf("taille : %d\n" , compteur_temp);
                // comparons pour savoir si l'ensemble est le plus grand présent sur le jeu
                if(compteur_temp > taille_ensemble)
                {
                    taille_ensemble = compteur_temp;
                }
            }

        }
    }
return(taille_ensemble);
}
