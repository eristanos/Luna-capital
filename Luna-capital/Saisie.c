#include <stdio.h>
#include "declaration.h"
#include "saisie.h"

int  Saisie_Nb_Joueurs()
{
    int n;

    do
    {
    printf("Saisir le nombre de joueurs qui vont jouer : ");
    scanf("%d",&n);

    }while(1>n || n>5);
    return n;

}

void Saisie_Noms_Joueurs(S_joueur tab_joueur[] ,int nb_joueur)
{
    for(int i = 0; i < nb_joueur ; i++)
    {
        printf("Joueur %d , saisir votre nom : ", i+1);
        scanf("%s",tab_joueur[i].nom);
    }

}

void affectation_sponsor(S_joueur tab_joueur[] , int nb_joueur)
{
    for(int i = 0; i <nb_joueur ; i++)
    {
    printf("joueur %d, saisir votre sponsor (4.Rouge fonce 1.Bleu fonce 2.Vert fonce 14.Jaune) : ", i+1);
        scanf("%d", &tab_joueur[i].sponsor);
    }
}

int Saisie_coordonnees(int min , int max)
{
    int statut = 0;
    int i = -1;

    while(statut == 0)
     {
        scanf("%d", &i);
        if(i > min && i <= max)
            {
                statut = 1;
            }
     }
    return (i-1);
}
int verif_emplacement(int x, int y, S_carte_construction tab[][LONG_MAX_JEU])
{
    if(tab[x][y].type == 0)
    {
        return 1;
    }
    else
    {
        printf("case deja occupée");
        return 0;
    }
}
int verif_ordre_carte(int x, int y, S_carte_construction tab[][LONG_MAX_JEU], int valeur_carte)
{
    for(int i = 0; i < x ; i++)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur >= x)
            {
                printf("trop grand");
                return 0;
            }
        }
    }
    for(int i = LARG_MAX_JEU; i > x ; i--)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur <= x)
            {
                printf("trop petit");
                return 0;
            }
        }
    }
    return 1;
}


void placer_carte(S_joueur *joueur , S_carte_construction carte)
{
    int etat = 0;
    carte.type = 1;
    while(etat == 0)
    {
        printf("valeur = %d" , carte.valeur);
        printf("Saisir x : ");
        int x = Saisie_coordonnees(0,LARG_MAX_JEU);
        printf("Saisir y : ");
        int y = Saisie_coordonnees(0,LONG_MAX_JEU);
        if(verif_emplacement(x,y,joueur->jeu) == 1)
        {
            int n = 0;

            if(joueur->nb_selenite > 0)
            {
                printf("Voulez vous utilisez un selenite ?  ( 0 : NON, 1 : OUI )  : ");
                scanf("%d" ,&n);
                n = 1;
            }
            if(n == 1)
            {
                printf("nique le jeu");
                joueur->jeu[x][y] = carte;
                printf("joueur %d", joueur->jeu[x][y].valeur);
                joueur->nb_selenite --;
                etat = 1;
                printf("placeeeee");

            }
            else
            {
                printf("vive les juifs");
                if(verif_ordre_carte(x,y,joueur->jeu,carte.valeur) == 1)
                {
                    joueur->jeu[x][y] = carte;
                    etat = 1;
                    printf("placeeeee");

                }
            }
        }
    }
}
