#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "declaration.h"
#include "affichage.h"
#include "Saisie.h"

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
    color(15, 0);
}

void positionner_curseur(int ligne, int colonne)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de d�clarer la variable "hstdout" qui fait r�f�r�nce � la console
    COORD pos; // COORD est un type structur� d�fini dans la biblioth�que windows.h
    pos.X=colonne;// num�ro de la colonne
    pos.Y=ligne;// num�ro de la ligne
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
    dessiner_rectangle(ligne , colonne , 0 , LON_CARTE , LAR_CARTE);
    if(carte_construction.type != 0)
    {
        // affichage fond de carte
        dessiner_rectangle(ligne,colonne,8,LON_CARTE, LAR_CARTE);

        // affichage num�ro associ� � la carte
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
        color(15,0);
    }
}

void dessiner_tuile(int ligne, int colonne, S_tuile tuile)              // affichage des tuiles
{
    if(tuile.type != PAS_TUILE)
    {
        // on remet un fond pour supprimer les eventuels caracteres present
        dessiner_rectangle(ligne + 1, colonne , 8 , 4 , 7);

        // on affiche la ligne de d�limitation sup�rieur
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
          case VITAUX :
            dessiner_vitaux(ligne,colonne,tuile.sous_type);
            break;
          case METEORITE :
            dessiner_meteorite(ligne,colonne);
            break;
         case AGENCE :
            dessiner_agence_commercial(ligne,colonne);
            break;
          case MODULE :
            dessiner_module_habitation(ligne,colonne,tuile.sous_type);
            break;
          case ECHAFAUDAGE :
            dessiner_echafaudage(ligne,colonne);
            break;
          case  COMPLEXE :
            dessiner_complexe_residentiel(ligne,colonne);
            break;
          case TERRAIN :
            dessiner_terrain_alunissage(ligne,colonne);
            break;
          default :
            break;
        }
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
    // affichage de la tuile meteorite
    dessiner_rectangle(ligne + 2 , colonne + 2 , 0 , 1, 3);
    dessiner_rectangle(ligne + 3 , colonne + 1 , 0 , 1, 5);
    dessiner_rectangle(ligne + 4 , colonne + 2 , 0 , 1, 3);
}
void dessiner_agence_commercial(int ligne, int colonne)
{
    // affichage de la tuile agence commerciale
    dessiner_rectangle(ligne + 2, colonne +4 ,14 , 1, 1);
    dessiner_rectangle(ligne + 3, colonne +1 , 14, 1 ,4);
    dessiner_rectangle(ligne + 3, colonne +1 , 14, 1 ,4);
}

void dessiner_module_habitation(int ligne, int colonne, int sous_type)
{
    //affichage de la tuile module habitation
    dessiner_rectangle(ligne + 1, colonne +3 ,14 , 1, 1);
    dessiner_rectangle(ligne + 2, colonne +2 ,14 , 1, 3);
    dessiner_rectangle(ligne + 3, colonne +1 ,14 , 2, 5);
    dessiner_rectangle(ligne + 3, colonne +2 , sous_type, 1, 3);
}

void dessiner_echafaudage(int ligne, int colonne)
{
    //affichage de l'echafaudage lunaire
    dessiner_rectangle(ligne + 2, colonne + 2, 7, 1, 3);
    dessiner_rectangle(ligne + 3,colonne + 1,15, 2, 2);
    dessiner_rectangle(ligne + 3, colonne + 4, 0, 2,1);
}
void dessiner_complexe_residentiel(int ligne, int colonne)
{
    //affichage du complexe residentiel
    dessiner_rectangle(ligne +1,colonne + 3, 4, 1, 2);
    dessiner_rectangle(ligne +2,colonne + 3, 9, 3, 2);
    dessiner_rectangle(ligne +4,colonne + 2, 7, 1, 1);
    dessiner_rectangle(ligne +4, colonne + 5, 7 , 1, 1);
}
void dessiner_terrain_alunissage(int ligne, int colonne)
{
    //affichage du terrain d'alunissage
    dessiner_rectangle(ligne + 2, colonne + 1, 9, 1, 3);
    dessiner_rectangle(ligne + 3, colonne + 2, 3, 2, 1);
    dessiner_rectangle(ligne +4, colonne + 4, 0, 1, 1);
    dessiner_rectangle(ligne +2, colonne +6, 9, 3, 1);
}


void afficher_jeu_joueur(S_joueur joueur)
{
    dessiner_rectangle(0,0,0,LONG_MAX_JEU*LON_CARTE ,LARG_MAX_JEU*LAR_CARTE);
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


}


void afficher_menu(S_joueur joueur)
{

    color(15, 0);

    for(int i = 0; i < LONG_MAX_JEU * LON_CARTE + 4; i ++)
    {
        positionner_curseur(i,LARG_MAX_JEU*LAR_CARTE + 8);
        printf("%c" , 179);
    }


    dessiner_rectangle(0 , ZONE_ECRITURE_GAUCHE, 0 , LONG_MENU , LARG_MENU);
    positionner_curseur(0 ,ZONE_ECRITURE_GAUCHE);
    printf("    INFORMATION");
    positionner_curseur(2 ,ZONE_ECRITURE_GAUCHE);
    printf("Joueur : %s" , joueur.nom);
    positionner_curseur(3,ZONE_ECRITURE_GAUCHE);
    printf("Sponsor : %d " , joueur.sponsor);
    positionner_curseur(4,ZONE_ECRITURE_GAUCHE);
    printf("Tour de jeu : %d" , joueur.nb_tour_joueur);
    positionner_curseur(5 ,ZONE_ECRITURE_GAUCHE);
    printf("Selenites : %d" , joueur.nb_selenite);



}
void afficher_plateau(S_plateau plateau)
{
    dessiner_rectangle(0,0,0,LONG_MAX_JEU*LON_CARTE ,LARG_MAX_JEU*LAR_CARTE);
    for(int i = 0 ; i < NB_CARTE_JEU; i++)
    {
        dessiner_carte_construction( 0 , i * LAR_CARTE + i*2 + 1 , plateau.cartes[i]);
        for(int y = 0; y < NB_TUILE ; y++)
        {
            dessiner_tuile((LON_CARTE * y)/2 + LON_CARTE + 1+ y , i * LAR_CARTE + i*2 + 1 , plateau.tuiles[i][y]);
        }
        positionner_curseur(LON_CARTE +9 ,i * LAR_CARTE + i + 1);


    }


}

void afficher_deck_joueur(S_joueur joueur)
{
    dessiner_rectangle(0,0,0,LONG_MAX_JEU*LON_CARTE+8 ,LARG_MAX_JEU*LAR_CARTE+8);
    for(int i = 0 ; i < MAX_ELEMENT; i++)
    {
        if(joueur.deck_cartes[i].type == 1)
        {
            dessiner_carte_construction( 0 , i * LAR_CARTE + i + 1 , joueur.deck_cartes[i]);
            positionner_curseur(LON_CARTE +9 ,i * LAR_CARTE + i + 1);
            printf("%d" , i+1);
        }
        if(joueur.deck_tuiles[i].type != 0)
        {
            dessiner_tuile(LON_CARTE + 3 , i * LAR_CARTE + i + 1 , joueur.deck_tuiles[i]);
            positionner_curseur(LON_CARTE +9 ,i * LAR_CARTE + i + 1);
            printf("%d" , i+1);
        }
    }
}


void choix_actions(S_joueur *joueur, S_plateau *plateau)
{
    afficher_menu(*joueur);
    int etat = 0;
    do
    {
        //afficher_menu(*joueur)
        positionner_curseur(ZONE_ECRITURE_HAUT, ZONE_ECRITURE_GAUCHE);
        printf("ACTIONS : ");
        positionner_curseur(ZONE_ECRITURE_HAUT + 1,ZONE_ECRITURE_GAUCHE);
        printf("1 : Voir le jeu");
        positionner_curseur(ZONE_ECRITURE_HAUT + 2,ZONE_ECRITURE_GAUCHE);
        printf("2 : Voir les decks");
        positionner_curseur(ZONE_ECRITURE_HAUT + 3,ZONE_ECRITURE_GAUCHE);
        printf("3 : Voir les concessions");
        positionner_curseur(ZONE_ECRITURE_HAUT + 4,ZONE_ECRITURE_GAUCHE);
        printf("4 : glossaire tuile");
        positionner_curseur(ZONE_ECRITURE_HAUT + 5,ZONE_ECRITURE_GAUCHE);
        printf("5 : placer une tuile");
        positionner_curseur(ZONE_ECRITURE_HAUT + 6,ZONE_ECRITURE_GAUCHE);
        printf("6 : Fin du tour");
        positionner_curseur(ZONE_ECRITURE_HAUT + 7,ZONE_ECRITURE_GAUCHE);
        printf("CHOIX :");
        int choix;
        scanf("%d" ,&choix);
        positionner_curseur(ZONE_ECRITURE_HAUT + 8,ZONE_ECRITURE_GAUCHE);

        switch(choix)
        {
        case 1:
            afficher_jeu_joueur(*joueur);
            break;
        case 2:
            afficher_deck_joueur(*joueur);
            break;
        case 3:
            printf("TOUJOURS PAS IMPLEMENTER BANDE DE CHOMEUR FAUT SE BOUGER LE CUL");
            break;
        case 4:
            printf("TOUJOURS PAS IMPLEMENTER MEME MARWAN BENRAMEUR SAURAIT FAIRE CA");
            break;
        case 5:
            placer_tuile(joueur);
            break;
        case 6 :
            etat = 1;
            break;

        default :
            printf("valeur invalide");
            break;
        }
    }while(etat ==0);

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
