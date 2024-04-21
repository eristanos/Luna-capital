#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define NB_CARTE_CONSTRUCTION_DECK 3
#define MAX_ELEMENT 8
#define NB_CHAR 30
#define NB_TUILE 4
#define VALEUR_NUM_MAX 10
#define NB_TYPE 2
#define NB_TYPE_TUILE 8


typedef struct tuile
{
     /*
    TYPE DE TUILE :
    0 : Vide / d�molition
    1 : Vitaux
    2 : M�t�orite : que sur les cartes
    3 : Agence commerciale
    4 : module habitation
    5 : complexe r�sidentiel
    6 : terrain d'alunissage
    7 : �chafaudage lunaire : que sur les cartes
    */

    int type;

    int sous_type;                  // l'indicatif sera celui d'une couleur pour eviter de mettre une variable redondante
}S_tuile;

typedef struct carte_construction
{
    int type;
    S_tuile tuile[NB_TUILE];
    int valeur;                     // indice afficher indiquant ou ranger la carte dans l'ordre croissant
}S_carte_construction;


typedef struct joueur
{
    S_carte_construction  deck_cartes[NB_CARTE_CONSTRUCTION_DECK];  // deck de cartes � poser du joueur
    S_tuile deck_tuiles[MAX_ELEMENT];                               // deck de tuile � poser du joueur
    int sponsor;                                          // sponsor/ couleur du joueur
    char nom[NB_CHAR];                                              // nom �quipe
    int nb_selenite;                                                // stock le nombre de bonus selenite du joueur
}S_joueur;

#endif // DECLARATION_H_INCLUDED
