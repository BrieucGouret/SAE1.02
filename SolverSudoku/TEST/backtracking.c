#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4
#define TAILLE (N*N)


typedef int tGrille[TAILLE][TAILLE];


void chargerGrille(tGrille grille,char *nomFichier);

void afficherGrille(tGrille grille);

bool backtracking(tGrille grille, int numeroCase);
    
bool absentSurLigne(int valeur, tGrille grille, int ligne);

bool absentSurColonne(int valeur, tGrille grille, int colonne);

bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne);

int main(){
    tGrille grille;
    char nomgrille[30] = "";
    
    
    chargerGrille(grille, nomgrille);
    
    printf("Grille initiale :\n");
    afficherGrille(grille);

    
    if (backtracking(grille, 0)) {
        printf("\nGrille résolue :\n");
        afficherGrille(grille);
    } else {
        printf("\nLa grille ne peut pas être résolue.\n");
    }

    return 0;
}


void backtracking(tGrille grille, int numeroCase){
    int ligne;
    int colonne;
    bool resultat = false;
    if (numeroCase = TAILLE * TAILLE){
        //toutes les cases sont traitées
        resultat = true;
    }
    else {
        ligne = numeroCase / TAILLE;
        colonne = numeroCase % TAILLE;
        if (grille[ligne][colonne]!=0){
            //si la case n'est pas vide, on passe à la suivante
            resultat = backtracking(grille, numeroCase+1);
        }
        else {
            for (int valeur=1; valeur < TAILLE; valeur++){
                if (absentSurLigne(int valeur,tGrille grille, int ligne) && absentSurColonne(int valeur, tGrille grille, int colonne) && absentSurBloc(int valeur, tGrille grille, int ligne, int colonne)){
                    grille[ligne][colonne] = valeur;
                }
                if (backtracking(tGrille, numeroCase+1) = true) {
                    resultat = true;
                }
                else {
                    grille[ligne][colonne] = 0;
                }
            }
        }

    }
    return resultat;
}

bool absentSurLigne(int valeur, tGrille grille, int ligne){
    int j;
    bool possible = true;
    for (j = 0; j < TAILLE; j++) {
        if (grille[ligne][j] == valeur && j != numColonne) {
            possible = false;
        }
    }
    return possible;
}

bool absentSurColonne(int valeur, tGrille grille, int colonne){
    int i;
    bool possible = true;
    for (i = 0; i < TAILLE; i++) {
        if (grille[i][colonne].valeur == valeur && i != numLignes) {
            possible = false;
        }
    }
    return possible;
}

bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne){
    int coinBlocColonne, coinBlocLigne;
    bool possible = true;
    coinBlocLigne = (numLignes / 3) * 3;
    coinBlocColonne = (numColonne / 3) * 3;
    for (int i = coinBlocLigne; i < coinBlocLigne + 3; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + 3; j++) {
            if (grilleCase[i][j].valeur == valeur && (i != numLignes || j != numColonne)) {
                possible = false;
            }
        }
    }
    return possible;
}

void chargerGrille(tGrille g,char *nomFichier) {
    FILE *f;
    printf("Nom du fichier ?\n");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");

    if (f == NULL) {
        printf("\nERREUR sur le fichier %s\n", nomFichier);
    } else {
        fread(g, sizeof(int), TAILLE * TAILLE, f);
    }
    fclose(f);
}

void afficherGrille(tGrille grille) {
    int i, j, compteur1, compteur2 = 1;
    printf("    ");
    for (compteur1 = 1; compteur1 < TAILLE + 1; compteur1++) {
        printf("%3d", compteur1);
        if (compteur1 == 8 || compteur1 == 4 || compteur1 == 12) {
            printf(" ");
        }
    }
    printf("\n    +------------+------------+------------+------------+\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%3d |", compteur2);
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j] == 0) {
                printf(" . ");
            } else {
                printf("%2d ", grille[i][j]);
            }
            if (j == 3 || j == 7 || j == 11) {
                printf("|");
            }
        }
        printf("|\n");
        compteur2++;
        if (compteur2 == 5 || compteur2 == 9 || compteur2 == 13) {
            printf("    +------------+------------+------------+------------+\n");

        }
    }
    printf("    +------------+------------+------------+------------+\n");

}