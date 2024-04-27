#include <stdio.h>
#include "declaration.h"
#include "saisie.h"
#include "declaration_cartes.h"
#include "affichage.h"

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
        return 0;
    }
}
int verif_ordre_carte(int x, int y, S_carte_construction tab[][LONG_MAX_JEU], int valeur_carte)
{
    for(int i = 0; i < x ; i++)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur >= valeur_carte)
            {
                printf("trop grand\n");
                return 0;
            }
        }
    }
    for(int i = LARG_MAX_JEU-1; i > x ; i--)
    {
        if(tab[i][y].type != 0)
        {
            if(tab[i][y].valeur <= valeur_carte)
            {
                printf("trop petit\n");
                return 0;
            }
        }
    }
    return 1;
}

int verif_adjacent(int x, int y, S_carte_construction tab[][LONG_MAX_JEU])
{
    int i =0;
    // verif haut
    if(y > 0)
    {
        if(tab[x][y-1].type == 1)
        {
            i = 1;
        }
    }

    // verif bas
    if(y < LONG_MAX_JEU-1)
    {
        if(tab[x][y+1].type == 1)
        {
            i = 1;
        }
    }

    // verif gauche
    if(x > 0)
    {
        if(tab[x - 1][y].type == 1)
        {
            i = 1;
        }
    }


    // verif droite
    if(x < LARG_MAX_JEU -1)
    {
        if(tab[x + 1][y].type == 1)
        {
            i = 1;
        }
    }
    if(i == 0)
    {
        printf("non adjacent");
    }
    return(i);
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
        if(verif_emplacement(x,y,joueur->jeu) == 1 && (verif_adjacent(x,y,joueur->jeu) == 1 || joueur->nb_tour_joueur == 0))
        {
            int n = 0;

            if(joueur->nb_selenite > 0)
            {
                printf("Voulez vous utilisez un selenite ?  ( 0 : NON, 1 : OUI )  : ");
                scanf("%d" ,&n);

            }
            if(n == 1)
            {
                joueur->jeu[x][y] = carte;
                printf("joueur %d", joueur->jeu[x][y].valeur);
                joueur->nb_selenite --;
                etat = 1;
                joueur->nb_tour_joueur++;

            }
            else
            {
                if(verif_ordre_carte(x,y,joueur->jeu,carte.valeur) == 1)
                {
                    joueur->jeu[x][y] = carte;
                    etat = 1;
                    joueur->nb_tour_joueur++;


                }
            }
        }
        else if(verif_emplacement(x,y,joueur->jeu) == 0)
        {
            printf("case deja occupée");

        }

    }
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
    for(int i=0;i<MAX_ELEMENT ;i++)
    {
        if(joueur->deck_cartes[i].type == VIDE)
        {
            temp=i;
            i=MAX_ELEMENT;
        }
    }
    joueur->deck_cartes[temp]=plateau->cartes[n];
      for(int j=0;j<NB_TUILE;j++)
    {
        if(joueur->deck_tuiles[j].type == VIDE)
        {
            temp1=j;
            j=NB_TUILE;
        }
    }
    joueur->deck_tuiles[temp1]=plateau->tuiles[n];
    plateau->tuiles[n] = generateur_tuile();
    plateau->cartes[n] = generateur_carte();
}
int verif_vide_tuile(S_carte_construction carte, int pos)
{
    if(carte.tuile[pos].type == VIDE)
    {
        return 1;
    }
    else if(carte.tuile[pos].type == DEMOLITION)
    {
        return 1;
    }
    else if(carte.tuile[pos].type == ECHAFAUDAGE)
    {
        return 2;
    }
    else{
        return 0;
    }
}


void placer_tuile(S_joueur *joueur)
{
    int n = joueur ->nb_tuile_deck;
    for(int i = 0; i < n; i++ )
    {
        int etat = 0;
        while(etat == 0)
        {
            printf("placer tuile %d" , i+1);
            printf("TYPE : %d\n" , joueur->deck_tuiles[i].type);
            printf("SOUS TYPE : %d" ,joueur->deck_tuiles[i].sous_type);


            // choix de la carte pour poser la tuile
            printf("Choississez une carte : ");

            printf("Saisir x : ");
            int x = Saisie_coordonnees(0,LARG_MAX_JEU);
            printf("Saisir y : ");
            int y = Saisie_coordonnees(0,LONG_MAX_JEU);
            if(verif_emplacement(x,y, joueur->jeu) == 0)
            {
                // choix de la tuile
                printf("Saisir position de la tuile : \n");
                int pos = Saisie_coordonnees(0 , NB_TUILE);

                // vérification d'emplacement disponible
                if (joueur->deck_tuiles[i].type == MODULE || joueur->deck_tuiles[i].type == COMPLEXE || joueur->deck_tuiles[i].type == TERRAIN)
                {
                    if(verif_vide_tuile(joueur->jeu[x][y] , pos) == 1 ||verif_vide_tuile(joueur->jeu[x][y] , pos) == 2)
                    {
                        printf("kim jong boum\n");
                        joueur->jeu[x][y].tuile[pos] = joueur ->deck_tuiles[i];
                        joueur ->deck_tuiles[i].type = 0;
                        afficher_jeu_joueur(*joueur);
                        etat = 1;
                    }
                    printf("jean paul franco\n");

                }
                else if(verif_vide_tuile(joueur->jeu[x][y] , pos) == 1)
                    {
                        printf("vive la shoah\n");
                        joueur->jeu[x][y].tuile[pos] = joueur ->deck_tuiles[i];
                        joueur ->deck_tuiles[i].type = 0;
                        afficher_jeu_joueur(*joueur);

                        etat = 1;
                    }
                else
                {
                    printf("case deja occupe\n");
                }

            }
            else
            {
                printf("pas de carte ici \n");
            }
        }

    }

}


