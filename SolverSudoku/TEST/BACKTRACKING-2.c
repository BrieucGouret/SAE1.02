#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define N 4
#define TAILLE (N*N)

typedef struct {
    int valeur;
    int candidat[TAILLE];
    int nbcandidat;
} tCase1;


typedef int tGrille[TAILLE][TAILLE];
typedef tCase1 tGrilleCase[TAILLE][TAILLE];


void chargerGrille(tGrille grille, char *nomFichier);

void afficherGrille(tGrille grille);

bool backtracking(tGrille grille, int numeroCase);

bool absentSurLigne(int valeur, tGrille grille, int ligne);

bool absentSurColonne(int valeur, tGrille grille, int colonne);

bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne);

void initCase(tCase1 *Case);

int initNbCaseVide(tGrille grille);

int nombreDecandidat(tGrilleCase grilleCase);

void initcandidat(tGrilleCase grilleCase);

//estcandidat teste si une valeur est éligible à la case
bool estcandidat(tGrilleCase grilleCase, int valeur, int numLignes , int numColonne  );

void ajoutercandidat(tCase1 *Case, int valeur);

void ajouterValeur(tCase1 *Case, tGrilleCase grilleCase, int numLigne, int numColonne);

void retirercandidat(tCase1 *Case, int valeur);

void retirercandidatColonne(tGrilleCase grilleCase, int numColonne, int valeur);

void retirercandidatBloc(tGrilleCase grilleCase, int numLigne, int numColonne, int valeur);

void retirercandidatLigne(tGrilleCase grilleCase, int numLigne, int valeur);

void affecter(tGrille grille,tGrilleCase grilleCase);

void singletonCache(tGrille grille,tGrilleCase grilleCase, int numLigne, int numColonne, int valeur,int *nbCasesVides);

void singletonCacheLigne(tGrilleCase grilleCase, tCase1 *Case, int numLigne, int valeur);

void singletonCacheColonne(tGrilleCase grilleCase, tCase1 *Case, int numColonne, int valeur);

void singletonCacheBloc(tGrilleCase grilleCase, tCase1 *Case, int numLigne, int numColonne, int valeur);


int main() {
    clock_t begin = clock();
    tGrille grille;
    char nomgrille[30] = "";
    tGrilleCase grilleCase;
    bool progression = true;
    int nbCasesVidesAvant;
    int nombrescandidat = 0,nbcandidatAvantSolver;
    int nbCasesVides,nbCasesVidesAvantSolver;
    int nbCaseRempli = 0 ;
    int toursSansAvance = 0;


    chargerGrille(grille, nomgrille);
    nbCasesVides = initNbCaseVide(grille);
    nbCasesVidesAvantSolver = initNbCaseVide(grille);
    printf("Nombre de cases vides %d\n",nbCasesVides);
    printf("Grille initiale :\n");
    afficherGrille(grille);
    affecter(grille,grilleCase);
    initcandidat(grilleCase);

    nbcandidatAvantSolver = nombreDecandidat(grilleCase);


    while (nbCasesVides != 0 && progression == true && toursSansAvance < 82) {
        nbCasesVidesAvant = nbCasesVides;

        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {

                if (grilleCase[i][j].nbcandidat == 1) {
                    ajouterValeur(&grilleCase[i][j], grilleCase, i, j);
                    grille[i][j] = grilleCase[i][j].valeur;
                    retirercandidatLigne(grilleCase, i, grilleCase[i][j].valeur);
                    retirercandidatColonne(grilleCase, j, grilleCase[i][j].valeur);
                    retirercandidatBloc(grilleCase, i, j, grilleCase[i][j].valeur);
                    nbCasesVides--;
                    nombrescandidat++;
                    nbCaseRempli++;
                    progression = true;
                }
                if (grilleCase[i][j].valeur == 0 && grilleCase[i][j].nbcandidat != 1)
                {
                    for (int val = 1; val <= TAILLE; val++) {
                        if (grilleCase[i][j].candidat[val] == true) {
                            singletonCache(grille, grilleCase, i, j, val , &nbCasesVides);
                        }
                    }
                }

                if (nbCasesVidesAvant == nbCasesVides) {
                    toursSansAvance++;
                } else {
                    toursSansAvance = 0;
                }
                if (toursSansAvance == 82) {
                    progression = false;
                }
                
  
            }
        }
        
    }

    if(progression == false){
        if (backtracking(grille, 0)) {
            printf("\nGrille résolue :\n");
            afficherGrille(grille);
        } else {
            printf("\nLa grille ne peut pas être résolue.\n");
        }
    }
    clock_t end = clock();
    double tmpsCPU = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Temps CPU = %.6f secondes\n", tmpsCPU);

    return 0;
}

void initCase(tCase1 *Case) {
    for (int i = 0; i < TAILLE; i++) {
        Case->candidat[i] = 0;
    }
    Case->nbcandidat = 0;
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

void initcandidat(tGrilleCase grilleCase){
    bool nbEstcandidat;
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grilleCase[i][j].valeur == 0)
            {
                for (int compt = 1; compt <= TAILLE; compt++) {
                    nbEstcandidat = estcandidat(grilleCase, compt, i, j);
                    if (nbEstcandidat == true) {
                        ajoutercandidat(&grilleCase[i][j], compt);
                    }
                }
            }
            
            
        }
        
    }
     
}

int nombreDecandidat(tGrilleCase grilleCase) {
    int sommecandidat = 0;
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            sommecandidat += grilleCase[i][j].nbcandidat;
        }
    }
    return sommecandidat;
}

void ajoutercandidat(tCase1 *Case, int valeur) {
    Case->candidat[valeur - 1] = 1;  
    Case->nbcandidat++;
}

void retirercandidat(tCase1 *Case, int valeur) {
    if (Case->candidat[valeur - 1] == 1) {  
        Case->candidat[valeur - 1] = 0;
        Case->nbcandidat--;
    }
}


void retirercandidatColonne(tGrilleCase grilleCase, int numColonne, int valeur) {
    for (int i = 0; i < TAILLE; i++) {
        if (grilleCase[i][numColonne].valeur == 0) {
            retirercandidat(&grilleCase[i][numColonne], valeur);
        }
    }
}

void retirercandidatBloc(tGrilleCase grilleCase, int numLigne, int numColonne, int valeur) {
    int coinBlocLigne = (numLigne / N) * N;
    int coinBlocColonne = (numColonne / N) * N;

    for (int i = coinBlocLigne; i < coinBlocLigne + N; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + N; j++) {
            if (grilleCase[i][j].valeur == 0) {
                retirercandidat(&grilleCase[i][j], valeur);
            }
        }
    }
}


void retirercandidatLigne(tGrilleCase grilleCase, int numLigne, int valeur) {
    for (int j = 0; j < TAILLE; j++) {
        if (grilleCase[numLigne][j].valeur == 0) {
            retirercandidat(&grilleCase[numLigne][j], valeur);
        }
    }
}

bool estcandidat(tGrilleCase grilleCase, int valeur, int numLignes , int numColonne){
    int i, j, coinBlocLigne, coinBlocColonne;
    bool possible = true;
    for (j = 0; j < TAILLE; j++) {
        if (grilleCase[numLignes][j].valeur == valeur && j != numColonne) {
            possible = false;
        }
    }

    j = numColonne;
    i = 0;

    for (i = 0; i < TAILLE; i++) {
        if (grilleCase[i][numColonne].valeur == valeur && i != numLignes) {
            possible = false;
        }
    }

    coinBlocLigne = (numLignes / N) * N;
    coinBlocColonne = (numColonne / N) * N;

    for (int i = coinBlocLigne; i < coinBlocLigne + N; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + N; j++) {
            if (grilleCase[i][j].valeur == valeur && (i != numLignes || j != numColonne)) {
                possible = false;
            }
        }
    }
    return possible;  
}

void affecter(tGrille grille, tGrilleCase grilleCase) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] != 0) {
                grilleCase[i][j].valeur = grille[i][j];
                initCase(&grilleCase[i][j]);
            }else{
                grilleCase[i][j].valeur = 0;
                initCase(&grilleCase[i][j]);
            }
        }
    }

    
}

void ajouterValeur(tCase1 *Case, tGrilleCase grilleCase, int numLigne, int numColonne) {
    int i = 1;
    while (Case->candidat[i - 1] != 1 && i <= TAILLE) {

        i++;
    }
    Case->valeur = i;
    retirercandidat(Case, i);

    grilleCase[numLigne][numColonne].valeur = Case->valeur;
    retirercandidatLigne(grilleCase, numLigne, Case->valeur);
    retirercandidatColonne(grilleCase, numColonne, Case->valeur);
    retirercandidatBloc(grilleCase, numLigne, numColonne, Case->valeur);
}


void singletonCache(tGrille grille, tGrilleCase grilleCase, int numLigne, int numColonne, int valeur, int *nbCasesVides) {
    int coinBlocColonne, coinBlocLigne;

    int nbcandidatTrouves = 0;

    //ligne
    for (int j = 0; j < TAILLE; j++) {
        if (j != numColonne && grilleCase[numLigne][j].candidat[valeur] == true) {
            nbcandidatTrouves++;
        }
    }
    //colonne
    for (int i = 0; i < TAILLE; i++) {
        if (i != numLigne && grilleCase[i][numColonne].candidat[valeur] == true) {
            nbcandidatTrouves++;
        }
    }

    coinBlocLigne = (numLigne / N) * N;
    coinBlocColonne = (numColonne / N) * N;

    //bloc
    for (int i = coinBlocLigne; i < coinBlocLigne + N; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + N; j++) {
            if ((i != numLigne || j != numColonne) && grilleCase[i][j].candidat[valeur] == true) {
                nbcandidatTrouves++;
            }
        }
    }

    if (nbcandidatTrouves == 1 ) {
        
        for (int val = 1; val <= TAILLE; val++) {
            if (val != valeur && grilleCase[numLigne][numColonne].candidat[val] == true) {
                retirercandidat(&grilleCase[numLigne][numColonne], val);
            }
        }
    }
}

void singletonCacheLigne(tGrilleCase grilleCase, tCase1 *Case, int numLigne, int valeur) {
    for (int j = 0; j < TAILLE; j++) {
        if (j != numLigne && grilleCase[numLigne][j].valeur == 0 && grilleCase[numLigne][j].candidat[valeur] == true) {
            retirercandidat(&grilleCase[numLigne][j], valeur);
        }
    }
}

void singletonCacheColonne(tGrilleCase grilleCase, tCase1 *Case, int numColonne, int valeur) {
    for (int i = 0; i < TAILLE; i++) {
        if (i != numColonne && grilleCase[i][numColonne].valeur == 0 && grilleCase[i][numColonne].candidat[valeur] == true) {
            retirercandidat(&grilleCase[i][numColonne], valeur);
        }
    }
}

void singletonCacheBloc(tGrilleCase grilleCase, tCase1 *Case, int numLigne, int numColonne, int valeur) {
    int coinBlocLigne = (numLigne / N) * N;
    int coinBlocColonne = (numColonne / N) * N;

    for (int i = coinBlocLigne; i < coinBlocLigne + N; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + N; j++) {
            if ((i != numLigne || j != numColonne) && grilleCase[i][j].valeur == 0 && grilleCase[i][j].candidat[valeur] == true) {
                retirercandidat(&grilleCase[i][j], valeur);
            }
        }
    }
}

bool backtracking(tGrille grille, int numeroCase) {
    int ligne, colonne;
    bool resultat = false;

    if (numeroCase == TAILLE * TAILLE) {
        // toutes les cases sont traitées
        resultat = true;
    } else {
        ligne = numeroCase / TAILLE;
        colonne = numeroCase % TAILLE;
        if (grille[ligne][colonne] != 0) {
            // si la case n'est pas vide, on passe à la suivante
            resultat = backtracking(grille, numeroCase + 1);
        } else {
            for (int valeur = 1; valeur <= TAILLE; valeur++) {
                if (absentSurLigne(valeur, grille, ligne) && absentSurColonne(valeur, grille, colonne) &&
                    absentSurBloc(valeur, grille, ligne, colonne)) {
                    grille[ligne][colonne] = valeur;

                    if (backtracking(grille, numeroCase + 1)) {
                        resultat = true;
                        break; 
                    } else {
                        grille[ligne][colonne] = 0;  
                    }
                }
            }
        }
    }
    return resultat;
}

bool absentSurLigne(int valeur, tGrille grille, int ligne) {
    int j;
    bool possible = true;
    for (j = 0; j < TAILLE; j++) {
        if (grille[ligne][j] == valeur) {
            possible = false;
            break;  // Pas besoin de vérifier le reste de la ligne
        }
    }
    return possible;
}

bool absentSurColonne(int valeur, tGrille grille, int colonne) {
    int i;
    bool possible = true;
    for (i = 0; i < TAILLE; i++) {
        if (grille[i][colonne] == valeur) {
            possible = false;
            break;  // Pas besoin de vérifier le reste de la colonne
        }
    }
    return possible;
}

bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne) {
    int coinBlocColonne, coinBlocLigne;
    bool possible = true;
    coinBlocLigne = (ligne / N) * N;
    coinBlocColonne = (colonne / N) * N;
    for (int i = coinBlocLigne; i < coinBlocLigne + N; i++) {
        for (int j = coinBlocColonne; j < coinBlocColonne + N; j++) {
            if (grille[i][j] == valeur) {
                possible = false;
                break;  // Pas besoin de vérifier le reste du bloc
            }
        }
    }
    return possible;
}

void chargerGrille(tGrille g, char *nomFichier) {
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