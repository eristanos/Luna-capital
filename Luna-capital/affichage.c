#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "declaration.h"
#include "affichage.h"

#define LAR_CARTE 15
#define LON_CARTE 11

#define MIL_CARTE_LAR 7
#define MIL_CARTE_LON 5


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
    //7.Gris clair
    dessiner_rectangle(ligne,colonne,8,LON_CARTE, LAR_CARTE);
    positionner_curseur(ligne,colonne);
    color(15,8);
    printf("%d", carte_construction.valeur);
    for(int i =0; i < LON_CARTE; i++)
    {
        positionner_curseur(ligne + i, colonne+MIL_CARTE_LAR);
        color(7,8);
        printf("%c", 179);
    }
    for(int i =0; i < LAR_CARTE; i++)
    {
        positionner_curseur(ligne + MIL_CARTE_LON, colonne+i);
        color(7,8);
        printf("%c", 196);
    }
    positionner_curseur(ligne + MIL_CARTE_LON, colonne + MIL_CARTE_LAR);
    printf("%c", 197);


}

void dessiner_tuile(int ligne, int colonne, S_tuile tuile, int position)
{
    // affichage contour

    positionner_curseur(ligne + 1,colonne);
    printf("%c%c%c", 196,196,217);
    positionner_curseur(ligne,colonne +2);
    printf("%c" , 218);
    for(int i = 3; i < MIL_CARTE_LAR; i++)
    {
        printf("%c",196);
    }
    switch(tuile.type){

        case 0 :
            dessiner_vital(ligne,colonne,tuile.sous_type);
            break;
        case 1 :
            dessiner_vital(ligne,colonne,tuile.sous_type);
            break;

        default :
            break;
    }


}


void dessiner_vital(int ligne, int colonne, int sous_type)
{
    dessiner_rectangle(ligne + 2, colonne + 1, 12, 3 , 5);
    dessiner_rectangle(ligne + 3, colonne + 2, sous_type, 1,3);

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
