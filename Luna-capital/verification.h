#ifndef VERIFICATION_H_INCLUDED
#define VERIFICATION_H_INCLUDED
typedef struct verif
{
    int valeur;
    int etat;

}S_verif;
typedef struct co
{
    int x;
    int y;
}S_co;
int calcul_nb_construction(S_carte_construction tab[][LONG_MAX_JEU]);
int calcul_plus_grand_ensemble(S_carte_construction tab_jeu[][LONG_MAX_JEU] , int sous_type_r);
int place_tab(S_co tab[]);
int calcul_point(S_joueur joueur);
int verif_concession(S_carte_construction jeu[LARG_MAX_JEU][LONG_MAX_JEU] ,S_concession concession);
int verif_carte_colonne(S_carte_construction jeu[][LONG_MAX_JEU] , S_concession concession);
int verif_tuile_aligne(S_carte_construction jeu[LARG_MAX_JEU][LONG_MAX_JEU] , S_tuile tuile);




#endif // VERIFICATION_H_INCLUDED
