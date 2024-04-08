#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

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
