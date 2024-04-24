#include <stdio.h>
#include "declaration.h"
#include "saisie.h"
#include "declaration_cartes.h"

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


void placer_carte(S_carte_construction tab[][LONG_MAX_JEU] , S_carte_construction carte)
{
    printf("Saisir x : ");
    int x = Saisie_coordonnees(0,LARG_MAX_JEU);
    printf("Saisir y : ");
    int y = Saisie_coordonnees(0,LONG_MAX_JEU);
    tab[x][y] = carte;

}

void supprimer_carte(S_carte_construction tab[], int n)
{
    tab[n].type = 0;
    tab[n].valeur = 0 ;
    for(int i = 0; i < NB_TUILE ; i++)
    {
        tab[n].tuile[i].type = 0;
        tab[n].tuile[i].sous_type = 0;
    }
}

void piocher_carte(S_plateau *plateau , S_joueur *joueur)
{
    printf("Quelle carte voulez vous piocher : \n");
    int n = Saisie_coordonnees(0,NB_CARTE_JEU);
    int temp;
    int temp1;
    for(int i=0;i<NB_CARTE_CONSTRUCTION_DECK;i++)
    {
        if(joueur->deck_cartes[i].type == 0)
        {
            temp=i;
            i=NB_CARTE_CONSTRUCTION_DECK;
        }
    }
    joueur->deck_cartes[temp]=plateau->cartes[n];
      for(int j=0;j<NB_TUILE;j++)
    {
        if(joueur->deck_tuiles[j].type == 0)
        {
            temp1=j;
            j=NB_TUILE;
        }
    }
    joueur->deck_tuiles[temp1]=plateau->tuiles[n];
    plateau->tuiles[n] = generateur_tuile();
    plateau->cartes[n] = generateur_carte();
}


