#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define TAILLE (N*N)
typedef tCase1 tGrille[TAILLE][TAILLE];

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
    tGrille grille;
    tCase1 laCase;
    
}

void ajouterCandidats(tCase1 *laCase, int val){
    int anticandidat = 0;
    if (grille[i][j].valeur == 0)
    {
        for (int i = 0; i < TAILLE; i++){
            for (int j = 0; j < TAILLE; j++)
            {
              if (grille[][].val )
              {

              }
                
            }
            
                
        }
        laCase.candidats[nbCandidats] = val;
        laCase.nbCandidats = nbCandidats +1; 
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