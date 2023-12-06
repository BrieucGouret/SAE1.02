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
void initTab(tCase2 case);
void ajouterCandidats(int valeur);
void retirerCandidats();

int main(){
    tCase2 case;
}
void initCandidats(tCase2 case){
    for (int i = 1; i <= TAILLE; i++)
    {
        case.candidats[i] = false;
    }
    
}

void ajouterCandidats(int valeur){
    if ( case.valeur == 0)
    {
        case.candidats[valeur] = true;
    }else{
        printf("Case rempli d'une vvaleur\n")
    }
    
}

void resultat(){
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  %");
}