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
    progression : booléen;
    nbCasesVides : entier;
    nbCasesVides = chargerGrille(g);
    initialiserCandidats(g);
    progression = true;
    tant que (nbCaseVides <> 0 ET progression) faire
    progression = false;
    // technique du singleton nu
    pour chaque case libre de la grille faire
    si la case n'a qu'un seul candidat alors
    affecter ce candidat à la case
    nbCasesVides = nbCasesVides – 1;
    retirer ce candidat de toutes les cases de la
    même ligne, de la même colonne et du même bloc
    progression = true;
    finsi
    finfaire

    return EXIT_SUCCESS;
}

void ajouterCandidats(tCase1 *laCase, int val) {
    laCase->candidats[laCase->nbCandidats] = val;
    laCase->nbCandidats++;
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

}


