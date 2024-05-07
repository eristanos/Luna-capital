#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED



void positionner_curseur(int ligne, int colonne);
void color (int couleurDuTexte, int couleurDuFond);
void plein_ecran();
void affichage_caractere_speciaux();
void dessiner_rectangle(int ligne,int colonne,int c,int lg, int la);

void dessiner_carte_construction(int ligne, int colonne, S_carte_construction carte_construction);
void dessiner_tuile(int ligne, int colonne, S_tuile tuile);
void dessiner_jeton_construction(int ligne, int colonne);
void dessiner_carte_concession(S_concession carte_concession);

// design des tuiles
void dessiner_vitaux(int ligne, int colonne , int sous_type);
void dessiner_meteorite(int ligne, int colonne);
void dessiner_agence_commercial(int ligne, int colonne);
void dessiner_module_habitation(int ligne, int colonne, int sous_type);
void dessiner_echafaudage(int ligne, int colonne);
void dessiner_complexe_residentiel(int ligne, int colonne);
void dessiner_terrain_alunissage(int ligne, int colonne);

// affichages principaux
void afficher_jeu_joueur(S_joueur joueur);
void afficher_plateau(S_plateau plateau);
void afficher_menu(S_joueur joueur);
void choix_actions(S_joueur *joueur, S_plateau *plateau);
void afficher_deck_joueur(S_joueur joueur);



#endif // AFFICHAGE_H_INCLUDED
