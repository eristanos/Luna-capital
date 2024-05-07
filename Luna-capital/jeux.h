#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED
#include "declaration.h"

void initialiser_jeu(S_joueur tab_joueur[] , S_plateau *plateau , int nb_joueur);
void tour_jeu(S_joueur *joueur , S_plateau *plateau);
void jeu();

#endif // JEUX_H_INCLUDED
