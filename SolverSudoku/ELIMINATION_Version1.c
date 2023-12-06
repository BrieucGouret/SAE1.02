#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define TAILLE (N*N)

typedef struct {
    int valeur;
    int candidats[TAILLE];
    int nbCandidats;
} tCase1;

typedef tCase1 tGrille[TAILLE][TAILLE];

void ajouterCandidats(tCase1 *laCase, int val);
void retirerCandidats(tCase1 *laCase, int val);
bool estCandidat(tCase1 laCase, int val); 
int nbCandidats(tCase1 laCase);
void resultats();

int main(){
    tCase1 case;
}

void ajouterCandidats(tCase1 case){
    if (case.valeur == 0)
    {
        /* code */
    }
     
}



void resultat(){
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  %");
}