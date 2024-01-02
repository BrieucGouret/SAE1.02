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

void initTab(tCase2 *Case);

//prends la grille et regarde les différentas case vides
int initNbCaseVide(tGrille grille);

void chargerGrille(tGrille grille);

//estcandidats teste si une valeur est possible à mettre
bool estCandidats(tGrille grille, int valeur , int numLignes , int numColonne  );


//l'ajout du candidats au tablo booléen
void ajouterCandidats(tCase2 *Case, int valeur);


//retire le candidats du tablo
void retirerCandidats(tCase2 *Case , int valeur);

int main(){
    tGrille grille, g;
    tCase2 Case;
    bool progression = true;
    int nbCasesVides = initNbCaseVide(grille);
    int nbCaseRempli = 0 ;
    float tauxDeRemplissage;
    int candidatsElimine;
    float pourcentageElemination;

    chargerGrille(g);
    // se deplace dans le tableau jusuqu'à trouvé une case qui à la valeur 0 et après test les candidats possisble et ajoute cela au tableau de booléen 
    // après re tester pour savoir les valeurs à enlever les candidats savoir les candidats uniques

    //se deplace dans la grille et cherche les cases qui n'ont que un seul candidats 
    while (nbCasesVides == 0 && progression == true)
    {
        for (int i = 0; i < TAILLE; i++)
        {
            for (int j = 0; j < TAILLE; i++)
            {
                if (Case.nbCandidats == 1)
                {
                    grille[i][j] = Case.valeur;
                    nbCasesVides = nbCasesVides - 1;
                    //chercher toute les lignes et colonne et leurs enlever ce candidats
                    progression = true;
                }
                //boucle qui testera les valeurs de 1 à 9 dans 
                //le tablo candidats de estCandidats
                else
                {
                    for (int compt = 1; compt < TAILLE; compt++)
                    {
                        estCandidats(grille[i][j],compt, i , j);
                        if (/* condition */)
                        {
                            /* code */
                        }
                        
                    }
                    
                }
                
                
            }
            
        }
        
    }
    chargerGrille(g);
    afficherStats();
    
    

}
void initTab(tCase2 *Case){
    for (int i = 1; i <= TAILLE; i++)
    {
        Case->candidats[i] = false;
    }
    
}

void ajouterCandidats(tCase2 *Case, int valeur){
    Case->candidats[valeur] = true;
    
    
    
}

bool estCandidats(tGrille grille, int valeur, int numLignes , int numColonne  ){
    int i, j, coinLigne, coinColonne;
    bool possible = true;
    for (j = 0; j < TAILLE; j++) {
        if (grille[numLignes][j] == valeur && j != numColonne) {
            printf("Valeur impossible à placer, elle est déjà présente sur la ligne.\n");
            possible = false;
        }
    }

    j = numColonne;
    i = 0;

    for (i = 0; i < TAILLE; i++) {
        if (grille[i][numColonne] == valeur && i != numLignes) {
            printf("Valeur impossible à placer, elle est déjà présente sur la colonne.\n");
            possible = false;
        }
    }

    coinLigne = (numLignes / 3) * 3;
    coinColonne = (numColonne / 3) * 3;

    for (int i = coinLigne; i < coinLigne + 3; i++) {
        for (int j = coinColonne; j < coinColonne + 3; j++) {
            if (grille[i][j] == valeur && (i != numLignes || j != numColonne)) {
                printf("Valeur impossible à placer, elle est déjà présente dans le carré 3x3.\n");
                possible = false;
            }
        }
    }
    return possible;  
}

void afficherStats(){
    
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