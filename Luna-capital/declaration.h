#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define NB_CARTE_CONSTRUCTION_DECK 3
#define MAX_ELEMENT 300
#define NB_CHAR 30


typedef struct tuile
{
    int type;
    char nom[MAX_ELEMENT];
}S_tuile;

typedef struct carte_construction
{
    int type;
    S_tuile tuile[MAX_ELEMENT];
    char nom[MAX_ELEMENT];
}S_carte_construction;


typedef struct joueur
{
    S_carte_construction  deck_cartes[NB_CARTE_CONSTRUCTION_DECK];
    S_tuile deck_tuiles[MAX_ELEMENT];
    char sponsor[NB_CHAR];
    int nb_selenite;
}S_joueur;

#endif // DECLARATION_H_INCLUDED
