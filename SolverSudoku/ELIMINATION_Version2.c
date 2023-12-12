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

typedef int tGrille[TAILLE][TAILLE];

void resultat();
void initTab(tCase2 Case);
void chargerGrille(tGrille grille);
bool estCandidats(tGrille grille, int valeur );
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
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            /* code */
        }
        
    }
    
    
    
    
    if ( Case.valeur == 0)
    {
        Case.candidats[valeur] = true;
    }else{
        printf("Case rempli d'une valeur\n");
    }
    
}

bool estCandidats(tGrille grille, int valeur ){
    estCandidats = false;
    for (int i = 0; i < TAILLE; i++)
    {
        if(grille[i][]){
            
        }
    }
    for (int j = 0; j < N; j++)
    {
        if (grille[][j])
        {
            /* code */
        }
        
    }
    
    
}

void resultat(){
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  %");
}

void chargerGrille(tGrille g) {
    char nomFichier[30];
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