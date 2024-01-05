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
typedef tCase2 tGrilleCase[TAILLE][TAILLE];


void resultat();

void initCase(tCase2 *Case);

//prends la grille et regarde les différentas case vides
int initNbCaseVide(tGrille grille);

void chargerGrille(tGrille grille);

//estcandidats teste si une valeur est possible à mettre
bool estCandidats(tGrilleCase grilleCase, int valeur, int numLignes , int numColonne  );

//l'ajout du candidats au tablo booléen
void ajouterCandidats(tCase2 *Case, int valeur);

//retire le candidats du tablo
void retirerCandidats(tCase2 *Case, int valeur);

void affichageGrille(tGrille grille);

void affecterValeur(tGrille grille,tGrilleCase grilleCase);

void singletonCache(tCase2 *Case);

int main(){
    tGrille grille;
    tGrilleCase grilleCase;
    bool progression = true;
    bool nbEstCandidats;
    int nbCasesVides ;
    int nbCaseRempli = 0 ;
    float tauxDeRemplissage;
    int candidatsElimine;
    float pourcentageElemination;

    chargerGrille(grille);
    // se deplace dans le tableau jusuqu'à trouvé une case qui à la valeur 0 et après test les candidats possisble et ajoute cela au tableau de booléen 
    // après re tester pour savoir les valeurs à enlever les candidats savoir les candidats uniques
    nbCasesVides = initNbCaseVide(grille);
    printf(" nombre de case vides %d\n",nbCasesVides);
    printf("grille initial\n");
    affichageGrille(grille);
    affecterValeur(grille,grilleCase);
    //se deplace dans la grille et cherche les cases qui n'ont que un seul candidats 
    while (nbCasesVides == 0 && progression == true)
    {
        for (int i = 0; i < TAILLE; i++)
        {
            for (int j = 0; j < TAILLE; j++)
            {

                for (int compt = 1; compt <= TAILLE; compt++)
                    {
                        nbEstCandidats = estCandidats(grilleCase,compt, i , j);
                        if (nbEstCandidats == true)
                        {
                            ajouterCandidats(&grilleCase[i][j], compt);
                        }
                        
                    }
                if (grilleCase[i][j].nbCandidats == 1)
                {
                    
                    grille[i][j] = grilleCase[i][j].valeur;
                    nbCasesVides = nbCasesVides - 1;
                    nbCaseRempli =  nbCaseRempli + 1;
                    //chercher toute les lignes et colonne et leurs enlever ce candidats
                    progression = true;
                }
                printf("%d",nbCasesVides);
                
                
            }
            
        }
        
    }
    affichageGrille(grille);
    /// afficherStats();
    
}


void initCase(tCase2 *Case){
    for (int i = 1; i <= TAILLE; i++)
    {
        Case->candidats[i] = false;
    }
    Case->nbCandidats = 0;
    
}

int initNbCaseVide(tGrille grille){
    int nbCaseVide = 0;
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 0)
            {
                nbCaseVide++;
            }
            
        }
        
    }
    return nbCaseVide;
    
}

void ajouterCandidats(tCase2 *Case, int valeur){
    Case->candidats[valeur] = true;
    Case->nbCandidats++;
      
}


void retirerCandidats(tCase2 *Case, int valeur){
    Case->candidats[valeur] = false;
    Case->nbCandidats--;
}

bool estCandidats(tGrilleCase grilleCase, int valeur, int numLignes , int numColonne){
    int i, j, coinLigne, coinColonne;
    bool possible = true;
    for (j = 0; j < TAILLE; j++) {
        if (grilleCase[numLignes][j].valeur == valeur && j != numColonne) {
            printf("Valeur impossible à placer, elle est déjà présente sur la ligne.\n");
            possible = false;
        }
    }

    j = numColonne;
    i = 0;

    for (i = 0; i < TAILLE; i++) {
        if (grilleCase[i][numColonne].valeur == valeur && i != numLignes) {
            printf("Valeur impossible à placer, elle est déjà présente sur la colonne.\n");
            possible = false;
        }
    }

    coinLigne = (numLignes / 3) * 3;
    coinColonne = (numColonne / 3) * 3;

    for (int i = coinLigne; i < coinLigne + 3; i++) {
        for (int j = coinColonne; j < coinColonne + 3; j++) {
            if (grilleCase[i][j].valeur == valeur && (i != numLignes || j != numColonne)) {
                printf("Valeur impossible à placer, elle est déjà présente dans le carré 3x3.\n");
                possible = false;
            }
        }
    }
    return possible;  
}

void affecterValeur(tGrille grille,tGrilleCase grilleCase){
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] != 0 )
            {
                grilleCase[i][j].valeur = grille[i][j];
                initCase(&grilleCase[i][j]);
            }
            
        }
        
    }
    
    
}
// cherche si chaque candidats est present une seul fois en cherchant 
//si il peut etre place dans la grille car il n'est present qu'une seul fois en tant que candidats
void singletonCache(tCase2 *Case){
    bool singletonCacheTrouver;
    for (int i = 1; i < TAILLE; i++)
    {
        if (Case->candidats[i] == true)
        {
            // cherche si chaque candidats peut etre placer
            //****** est candidats a modifier je crois cela ne marche pas ????? *********//
            singletonCacheTrouver =  estCandidats(Case->candidats,i,numLignes,numColonne);
            if (singletonCacheTrouver == true)
            {
                Case->valeur = i;
            }
            
        }
        //boucle qui supprimme les valeurs
    }
    
}

void paireNues (tCase2 *Case){
    //regarde si il y a une paire
    int compt = 0;
    for (int i = 0; i < TAILLE; i++)
    {
        if (Case->candidats == true)
        {
            compt++;
        }
        
    }
    //rajouter le fait qu'il faut stocker qu'il y une 2 paire identiaues
    //rajouter que si compt > 2 ba on enleve du compteur de paire
    //supprimer cette paire du bloc, de la lignes ou de la colonne
    

}

/*

void afficherStats(){
    
    printf("*********   RESULTATS POUR  ***********");
    printf("nombres de cases remplies = sur     Taux de remplissage =  ");
    printf("nombres de candidats éliminé =      pourcentage de remplissage =  %");
}
*/
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

void affichageGrille(tGrille grille) {
    int i, j, compteur1, compteur2 = 1;
    printf("  ");
    for (compteur1 = 1; compteur1 < TAILLE + 1; compteur1++) {
        printf("%3d", compteur1);
        if (compteur1 == 6 || compteur1 == 3) {
            printf(" ");
        }
    }
    printf("\n  +---------+---------+---------+\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d |", compteur2);
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j] == 0) {
                printf(" . ");
            } else {
                printf("%2d ", grille[i][j]);
            }
            if (j == 2 || j == 5) {
                printf("|");
            }
        }
        printf("|\n");
        compteur2++;
        if (compteur2 == 4 || compteur2 == 7) {
            printf("  +---------+---------+---------+\n");
        }
    }
    printf("  +---------+---------+---------+\n");
}