#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#define NB_CARTE_CONSTRUCTION_DECK 3
#define MAX_ELEMENT 8
#define NB_CHAR 30
#define NB_TUILE 4
#define VALEUR_NUM_MAX 10
#define NB_TYPE 2
#define NB_TYPE_TUILE 8
#define NB_TYPE_TUILE_CARTE 4
#define NB_SOUS_TYPE_TUILE 6
#define TYPE_CONCESSION 3

#define LARG_MAX_JEU 8
#define LONG_MAX_JEU 3

//indicatif SOUS TYPE
#define CONDENSEUR_EAU 1
#define COLLECTEUR_HYDROGENE 0
#define COLLECTEUR_OXYGENE 3
#define SERRE_1 4
#define SERRE_2 5
#define SERRE_3 6
#define TOUTE_SERRE 7
//indicatif tuile
#define VIDE 0
#define VITAUX 1
#define METEORITE 2
#define AGENCE 3
#define MODULE 4
#define COMPLEXE 5
#define TERRAIN 6
#define ECHAFAUDAGE 7
//indicatif type concession
#define C_ALIGNE 0
#define C_COLONNE 1
#define C_N_CARTE 2


#define LARG_WINDOWS 140
#define LONG_WINDOWS 45



//Constantes d'affichage
#define LAR_CARTE 15
#define LON_CARTE 11

#define MIL_CARTE_LAR 7
#define MIL_CARTE_LON 5



// pourcentage pour la génération des tuiles des cartes
#define PART_METEORITE_CARTE 8
#define PART_VITAUX_CARTE 15
#define PART_VIDE_CARTE 70
#define PART_ECHAFAUDAGE_CARTE 7


// pourcentage pour la génération des tuiles
#define PART_VITAUX_TUILE 30
#define PART_REDISTRIBUTION_LOGISTIQUE_TUILE 10
#define PART_METEORITE_TUILE 10
#define PART_DEMOLITION_TUILE 10
#define PART_AGENCE_COMMERCIALE_TUILE 10
#define PART_TERRAIN_ALUNISAGE_TUILE 10
#define PART_COMPLEXE_RESIDENTIEL_TUILE 10
#define PART_MODULE_HABITATION 10
#define CHANCE_ROBOT_SELENITE 10

// pourcentage pour la generation du deck concessions
#define PART_3_ALIGNE 40
#define PART_3_CARTE_COLONNE 30
#define PART_POSSEDER_n_CARTE 30

typedef struct tuile
{
     /*
    TYPE DE TUILE :
    0 : Vide / démolition
    1 : Vitaux
    2 : Météorite : que sur les cartes
    3 : Agence commerciale
    4 : module habitation
    5 : complexe résidentiel
    6 : terrain d'alunissage
    7 : échafaudage lunaire : que sur les cartes
    */

    int type;

    int sous_type;                  // l'indicatif sera celui d'une couleur pour eviter de mettre une variable redondante
}S_tuile;



typedef struct carte_construction
{
    int type;                        //0 : pas de carte
    S_tuile tuile[NB_TUILE];
    int valeur;                     // indice afficher indiquant ou ranger la carte dans l'ordre croissant
}S_carte_construction;


struct concession
{
    int type;
 /* 0: posseder horizontal ou vertical
    1: posseder 3 carte en colonne
    2: posseder au moins n cartes

 */
    int points;
    S_tuile tuile;
};
typedef struct concession S_concession;


typedef struct joueur
{
    S_carte_construction  deck_cartes[NB_CARTE_CONSTRUCTION_DECK];  // deck de cartes à poser du joueur
    S_tuile deck_tuiles[MAX_ELEMENT];                               // deck de tuile à poser du joueur
    int sponsor;                                                    // sponsor/ couleur du joueur
    char nom[NB_CHAR];                                              // nom équipe
    int nb_selenite;                                                // stock le nombre de bonus selenite du joueur
    S_carte_construction jeu[LARG_MAX_JEU][LONG_MAX_JEU];           // jeu de cartes positionnées
    int nb_carte_jeu;
    int nb_carte_deck;

}S_joueur;




#endif // DECLARATION_H_INCLUDED
