#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3
#define TAILLE (N * N)

typedef struct {
    int valeur;
    int candidats[TAILLE];
    int nbCandidats;
} tCase1;

typedef tCase1 tGrille[TAILLE][TAILLE];

void ajouterCandidats(tCase1 *laCase, tGrille grille, int lig, int col);
void retirerCandidats(tCase1 *laCase, int val);
bool estCandidat(tCase1 laCase, int val);
int nbCandidats(tCase1 laCase);
void afficherGrille(tGrille g);
bool resoudreSudoku(tGrille grille);

int main() {
    tGrille grille;
    
    // Charger la grille à résoudre
    // (ajoutez votre code pour charger la grille ici)

    // Afficher la grille avant résolution
    printf("Grille avant résolution :\n");
    afficherGrille(grille);

    // Résoudre le sudoku
    if (resoudreSudoku(grille)) {
        printf("\nGrille résolue :\n");
        afficherGrille(grille);
    } else {
        printf("\nLa grille n'a pas de solution.\n");
    }

    return EXIT_SUCCESS;
}

void ajouterCandidats(tCase1 *laCase, tGrille grille, int lig, int col) {
    if (grille[lig][col].valeur == 0) {
        for (int val = 1; val <= TAILLE; val++) {
            if (estCandidat(grille[lig][col], val) &&
                estCandidat(grille[lig][col], val) &&
                estCandidat(grille[lig][col], val)) {
                laCase->candidats[laCase->nbCandidats] = val;
                laCase->nbCandidats++;
            }
        }
    }
}

void retirerCandidats(tCase1 *laCase, int val) {
    for (int i = 0; i < laCase->nbCandidats; i++) {
        if (laCase->candidats[i] == val) {
            for (int j = i; j < laCase->nbCandidats - 1; j++) {
                laCase->candidats[j] = laCase->candidats[j + 1];
            }
            laCase->nbCandidats--;
            break;
        }
    }
}

bool estCandidat(tCase1 laCase, int val) {
    for (int i = 0; i < laCase.nbCandidats; i++) {
        if (laCase.candidats[i] == val) {
            return true;
        }
    }
    return false;
}

int nbCandidats(tCase1 laCase) {
    return laCase.nbCandidats;
}

void afficherGrille(tGrille g) {
    // ... (reprendre votre fonction afficherGrille ici)
}

bool resoudreSudoku(tGrille grille) {
    int lig, col;

    // Recherche d'une case vide
    for (lig = 0; lig < TAILLE; lig++) {
        for (col = 0; col < TAILLE; col++) {
            if (grille[lig][col].valeur == 0) {
                // Tenter chaque candidat dans la case
                for (int val = 1; val <= TAILLE; val++) {
                    if (estCandidat(grille[lig][col], val)) {
                        grille[lig][col].valeur = val;

                        // Résoudre récursivement le reste du sudoku
                        if (resoudreSudoku(grille)) {
                            return true;
                        }

                        // Si la valeur ne fonctionne pas, annuler le choix
                        grille[lig][col].valeur = 0;
                    }
                }

                // Si aucun candidat ne fonctionne, revenir en arrière
                return false;
            }
        }
    }

    // Si toutes les cases sont remplies, la grille est résolue
    return true;
}
