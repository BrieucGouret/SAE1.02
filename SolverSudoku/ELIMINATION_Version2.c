#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define TAILLE (N*N)

typedef struct {
    int valeur;
    bool candidats[TAILLE + 1];
    int nbCandidats;
} tCase2;

typedef tCase2 tGrille[TAILLE];

void resultat();
void initTab(tCase2 Case);
void ajouterCandidats(tCase2 Case, int valeur);
void retirerCandidats();

int main(){
    tCase2 Case;
}
void initTab(tCase2 Case){
    for (int i = 1; i <= TAILLE; i++)
    {
        Case.candidats[i] = false;
    }
    
}

void ajouterCandidats(tCase2 Case, int valeur){
    if ( Case.valeur == 0)
    {
        Case.candidats[valeur] = true;
    }else{
        printf("Case rempli d'une valeur\n");
    }
    
}

void resultat(){
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  %");
}