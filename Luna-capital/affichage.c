#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "declaration.h"
#include "affichage.h"

void dessiner_rectangle(int ligne,int colonne,int c,int lg, int la)
{
    color(c,c);
    for(int x = 0; x < la; x++)
    {
        for(int y = 0; y < lg; y++)
        {
         positionner_curseur(ligne + y, colonne + x);
         printf("W");
        }
    }
}

void positionner_curseur(int ligne, int colonne)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de déclarer la variable "hstdout" qui fait référénce à la console
    COORD pos; // COORD est un type structuré défini dans la bibliothèque windows.h
    pos.X=colonne;// numéro de la colonne
    pos.Y=ligne;// numéro de la ligne
    SetConsoleCursorPosition(hStdout, pos);
}

void plein_ecran()
{
    keybd_event(VK_MENU,0x38,0,0); //Appuie sur ALT
    keybd_event(VK_RETURN,0x1c,0,0); //Appuie ENTREE
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); // Relache ENTREE
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); //Relache ALT
}

void affichage_caractere_speciaux()
{
     printf("%c\n\n",218);
     printf("%c\n\n",196);
     printf("%c\n\n",191);
     printf("%c\n\n",179);
     printf("%c\n\n",195);
     printf("%c\n\n",180);
     printf("%c\n\n",192);
     printf("%c\n\n",217);
}

void color (int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}

void dessiner_carte_construction(int ligne, int colonne, S_carte_construction carte_construction)
{
    if(carte_construction.type != 0)
    {
    // affichage fond de carte
    dessiner_rectangle(ligne,colonne,8,LON_CARTE, LAR_CARTE);

    // affichage numéro associé à la carte
    positionner_curseur(ligne,colonne);
    color(15,8);
    printf("%d", carte_construction.valeur);

    // affichage ligne centrale verticale
    for(int i =0; i < LON_CARTE; i++)
    {
        positionner_curseur(ligne + i, colonne+MIL_CARTE_LAR);
        color(7,8);
        printf("%c", 179);
    }

    // affichage ligne centrale horizontale
    for(int i =0; i < LAR_CARTE; i++)
    {
        positionner_curseur(ligne + MIL_CARTE_LON, colonne+i);
        color(7,8);
        printf("%c", 196);
    }

    // affichage point centrale
    positionner_curseur(ligne + MIL_CARTE_LON, colonne + MIL_CARTE_LAR);
    printf("%c", 197);

    // affichage de chacune des tuiles de la carte
    dessiner_tuile(ligne,colonne,carte_construction.tuile[0]);
    dessiner_tuile(ligne,colonne + MIL_CARTE_LAR + 1,carte_construction.tuile[1]);
    dessiner_tuile(ligne + MIL_CARTE_LON ,colonne,carte_construction.tuile[2]);
    dessiner_tuile(ligne + MIL_CARTE_LON ,colonne + MIL_CARTE_LAR + 1,carte_construction.tuile[3]);
    }
}

void dessiner_tuile(int ligne, int colonne, S_tuile tuile)              // affichage des tuiles
{
    // on remet un fond pour supprimer les éventuels caractères présent
    dessiner_rectangle(ligne + 1, colonne , 8 , 4 , 7);

    // on affiche la ligne de délimitation supérieur
    color(15,8);
    positionner_curseur(ligne + 1,colonne);
    printf("%c%c%c", 196,196,217);
    positionner_curseur(ligne,colonne +2);
    printf("%c" , 218);
    for(int i = 3; i < MIL_CARTE_LAR; i++)
    {
        printf("%c",196);
    }

    // on affiche le design de la tuile selon son type
    switch(tuile.type){
        case 0:
            break;

        case 1 :
            dessiner_vitaux(ligne,colonne,tuile.sous_type);
            break;
        case 2 :
            dessiner_meteorite(ligne,colonne);
            break;
        default :
            break;
    }
}

void dessiner_vitaux(int ligne, int colonne, int sous_type)
{
    // affichage des tuiles de type vitales selon leur sous type
    dessiner_rectangle(ligne + 2, colonne + 1, 4, 3 , 5);
    dessiner_rectangle(ligne + 3, colonne + 2, sous_type, 1,3);
}

void dessiner_meteorite(int ligne, int colonne)
{
    // affichage de la tuile météorite
    dessiner_rectangle(ligne + 2 , colonne + 2 , 0 , 1, 3);
    dessiner_rectangle(ligne + 3 , colonne + 1 , 0 , 1, 5);
    dessiner_rectangle(ligne + 4 , colonne + 2 , 0 , 1, 3);

}


void afficher_deck_joueurs(S_joueur joueur)
{
    for(int i = 0 ; i < LARG_MAX_JEU; i++)
    {
        for(int y = 0; y < LONG_MAX_JEU; y++)
        {
            if(joueur.jeu[i][y].type != 0)
            {
                dessiner_carte_construction( y * LON_CARTE + y + 1, i * LAR_CARTE + i ,joueur.jeu[i][y]);

            }
        }
    }
    color(15, 0);

    for(int i = 0; i < LONG_MAX_JEU * LON_CARTE + 4; i ++)
    {
        positionner_curseur(i,LARG_MAX_JEU*LAR_CARTE + 8);
        printf("%c" , 179);
    }

}


/*
0.Noir
1.Bleu fonce
2.Vert fonce
3.Turquoise
4.Rouge fonce
5.Violet
6.Vert caca d'oie
7.Gris clair
8.Gris fonce
9.Bleu fluo
11.Turquoise
12.Rouge fluo
13.Violet 2
14.Jaune
15.Blanc

*/
