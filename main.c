// main.c


#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000
#define PAS 1000
#define nl 3
#define nc 10

int choix;
int main() {
    printf("***********************************************\n");
    printf("*   Tests de la performance des tris en C   *\n");
    printf("***********************************************\n");
    do {
        printf("Choisissez le type de remplissage du tableau :\n");
        printf("1 - Trie\n");
        printf("2 - Trie a l'envers\n");
        printf("3 - Valeur positive apres valeur negative\n");

        printf("=> ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 3);

    double Mat[nl][nc];

    for (int i = 0; i < nc; i++) {
        Mat[0][i] = CalculTemps(tri_bulles, PAS * (i+1));
        Mat[1][i] = CalculTemps(tri_insertion,PAS * (i+1));
        Mat[2][i] = CalculTemps(tri_selection,PAS * (i+1));
    }

    Interpolation(Mat);
    plot(Mat);

    return 0;
}
