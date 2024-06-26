#ifndef SAISIE_H_INCLUDED
#define SAISIE_H_INCLUDED

int Saisie_Nb_Joueurs();
void Saisie_Noms_Joueurs(S_joueur tab_joueur[] ,int nb_joueur);
void affectation_sponsor(S_joueur tab_joueur[] , int nb_joueur);
void placer_carte(S_joueur *joueur);
int Saisie_coordonnees(int min , int max);
void supprimer_carte( S_carte_construction tab[] , int n);
void piocher_carte(S_plateau *plateau , S_joueur *joueur);


int verif_emplacement(int x, int y, S_carte_construction tab[][LONG_MAX_JEU]);
int verif_ordre_carte(int x, int y, S_carte_construction tab[][LONG_MAX_JEU], int valeur_carte);
int verif_adjacent(int x, int y, S_carte_construction tab[][LONG_MAX_JEU]);

void placer_tuile(S_joueur *joueur);
int verif_vide_tuile(S_carte_construction carte , int pos);

#endif // SAISIE_H_INCLUDED
