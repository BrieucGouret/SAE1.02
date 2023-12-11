#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define TAILLE (N*N)
typedef tCase tGrille[TAILLE][TAILLE];

typedef struct {
    int valeur;
    int candidats[TAILLE];
    int nbCandidats;
} tCase1;



void ajouterCandidats(tCase1 *laCase, int val);
void retirerCandidats(tCase1 *laCase, int val);
bool estCandidat(tCase1 laCase, int val); 
int nbCandidats(tCase1 laCase);
void resultats();

int main(){
    g tGrille;

}

void ajouterCandidats(tCase1 *laCase, int val){
    if (val == 0)
    {
        tCase1.candidats[nbCandidats] = val;
        tCase1.nbCandidats = nbCandidats +1; 
    }   
    else{
        printf("La case n'est pas vide")
    }
}



void resultat(){
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  ");
}