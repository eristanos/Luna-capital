#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#define LAR_CARTE 15
#define LON_CARTE 11

#define MIL_CARTE_LAR 7
#define MIL_CARTE_LON 5

void positionner_curseur(int ligne, int colonne);
void color (int couleurDuTexte, int couleurDuFond);
void plein_ecran();
void affichage_caractere_speciaux();
void dessiner_rectangle(int ligne,int colonne,int c,int lg, int la);

void dessiner_carte_construction(int ligne, int colonne, S_carte_construction carte_construction);
void dessiner_tuile(int ligne, int colonne, S_tuile tuile);

// design des tuiles
void dessiner_vitales(int ligne, int colonne , int sous_type);
void dessiner_meteorite(int ligne, int colonne);


#endif // AFFICHAGE_H_INCLUDED
