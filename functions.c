// functions.c


#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define nl 3
#define nc 10

// Déclaration d'une variable 'choix' (supposée être déclarée ailleurs dans le code)
int choix;

// Fonction qui remplit le tableau à trier en fonction de la valeur de 'choix'
void remplissage(int T[], int n) {
    // Utilisation de la valeur de 'choix' pour décider comment remplir le tableau
    switch (choix) {
        case 1:
            // Remplissage du tableau avec des valeurs croissantes de 0 à n-1
            for (int i = 0; i < n; i++)
                T[i] = i;
            break;
        case 2:
            // Remplissage du tableau avec des valeurs croissantes de n-1 à 0 (ordre inverse)
            for (int i = 0; i < n; i++)
                T[n - 1 - i] = i;
            break;
        case 3:
            // Remplissage du tableau avec des valeurs alternatives (positives/négatives)
            for (int i = 0; i < n; i++) {
                if (i % 2)
                    T[i] = i;   // Valeur positive pour les indices impairs (0 inclus)
                else
                    T[i] = -i;  // Valeur négative pour les indices pairs
            }
            break;
    }
}

// Fonction de tri à bulles
void tri_bulles(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Comparaison des éléments adjacents
            if (array[j] > array[j + 1]) {
                // Échange des éléments si l'élément actuel est plus grand
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Fonction de tri par insertion
void tri_insertion(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        // Déplace l'élément courant à sa position correcte dans le sous-tableau trié
        while (j > 0 && tab[j] < tab[j - 1]) {
            int temp = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = temp;
            j--;
        }
    }
}

// Fonction de tri par sélection
void tri_selection(int array[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        // Trouve l'indice de l'élément minimum non trié
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Échange l'élément minimum avec l'élément non trié actuel
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Fonction qui calcule le temps d'exécution pour un algorithme de tri donné
double CalculTemps(void (*trier)(int T[], int n), int taille) {
    int T[N];
    remplissage(T, N);
    clock_t start = clock();
    trier(T, taille);
    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    return executionTime;
}

// Fonction qui fait l'interpolation des points
void Interpolation(double Mat[nl][nc]) {
    for (int i = 0; i < nl; i++) {
        for (int j = 1; j < nc - 1; j++)
            Mat[i][j] = (Mat[i][j - 1] + Mat[i][j] + Mat[i][j + 1]) / 3;
    }
}

// Fonction pour tracer les courbes
void plot(double Mat[nl][nc]) {
    int i, j;
    FILE *gp = popen("gnuplot -presist", "w");
    if (gp == NULL) {
        printf("failed to run gnuplot pipe\n");
    }
    fprintf(gp, "set term qt presist\n");
    fprintf(gp, "set datafile separator ',' \n");

    for (i = 0; i < nl; i++) {
        fprintf(gp, "plot '-' using 1:2 title 'tri a bulle' with lp, '-' using 1:2 title 'tri par insertion' with lp, '-' using 1:2 title 'tri par selection' with lp\n");
        for (j = 0; j < nc; j++) {
            printf("%f ", Mat[i][j]);
            // Plot the file using gnuplot
            fprintf(gp, "%d,%f\n", ((j + 1) * 1000), Mat[i][j]);
        }
        fprintf(gp, "EOF \n");
        printf("\n");
    }
    // Close the gnuplot pipeline.
    pclose(gp);
}
