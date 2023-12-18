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

//prends la grille et regarde les différentas case vides
int initNbCaseVide(tGrille grille);

void chargerGrille(tGrille grille);

//estcandidats teste si une valeur est possible à mettre
bool estCandidats(tGrille grille, int valeur );


//l'ajout su candidatq au tablo booléen
void ajouterCandidats(tCase2 Case, int valeur);


//retire le candidats du tablo
void retirerCandidats(tCase2 Case , int valeur);

int main(){
    tGrille grille, g;
    tCase2 Case;
    bool progression = true;
    int nbCasesVides = initNbCaseVide(grille);

    chargerGrille(g);

    //se deplace dans la grille et cherche les cases qui n'ont que un seul candidats 
    while (nbCasesVides == 0 && progression == true)
    {
        for (int i = 0; i < TAILLE; i++)
        {
            for (int j = 0; j < TAILLE; i++)
            {
                if (Case.nbCandidats == 0)
                {
                    grille[i][j] = Case.valeur;
                    nbCasesVides = nbCasesVides - 1;
                }
                
            }
            
        }
        
    }
    
    // se deplace dans le tableau jusuqu'à trouvé une case qui à la valeur 0 et après test les candidats possisble et ajoute cela au tableau de booléen 
    // après re tester pour savoir les valeurs à enlever les candidats savoir les candidats uniques

    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j].valeur == 0)
            {
                for (int nb = 1; i < TAILLE; i++)
                {
                    
                   if ( estCandidats(grille[i][j]) == true)
                   {
                        ajouterCandidats( grille[i][j] ,nb);

                        
                   }
                     
                }
                
                
            }
            
        }
        
    }
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