#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define INFINI  FLT_MAX

void initMat(int n, float* matrice) {

    printf("Veuillez saisire la matrice des poids : \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("mat(%d, %d) : ", i, j);
                scanf("%f", (matrice+i*n+j));
            } while (*(matrice+i*n+j) < 0);
        }
    }
}

int min(int n, float* distance, int* ensembleS) {

    float min = INFINI;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (min > *(distance+i) && *(ensembleS+i) == 0) {
            min = *(distance+i);
            index = i;
        }
    }
    return index;
}

int* dijkstra(int n, float* matrice) {
    int*  ensembleS = malloc(n*sizeof(int));
    int* pred = malloc(n*sizeof(int));
    float* distance = malloc(n*sizeof(float));

    int s, sortie = 1;

    printf("Veuillez saisire le sommet de depart : ");
    scanf("%d", &s);

    for (int i = 0; i < n; i++) {
        *(ensembleS+i) = 0;
        *(pred+i) = -1;
        *(distance+i) = INFINI;
    }

    *(distance+s) = 0;
    *(pred+s) = s;


    int x;

    while (sortie) {
        x = min(n, distance, ensembleS);
        for (int i = 0; i < n; i++) {
            if (*(matrice+x*n+i) >0) {
                if (*(distance+x) + *(matrice+x*n+i) < *(distance+i)) {
                    *(distance+i) = *(distance+x) + *(matrice+x*n+i);
                    *(pred+i) = x;
                }
            }
        }

        *(ensembleS+x) = 1;

        for (int i = 0; i < n; ++i) {
            if (*(ensembleS+i) == 0) break;
            if (i == n-1) sortie = 0;
        }
    }

    free(ensembleS);
    free(distance);

    return pred;
}


int main( )
{
    int n;
    float* matrice;
    int* pred;

    printf("Veuillez saisire le nombre de sommets : ");
    scanf("%d", &n);

    matrice = malloc(n*n*sizeof(float));

    float temp[6][6] = {{0,10,0,0,0,9},
                        {10,0,5,8,13,0},
                        {0,5,0,4,0,3},

                        {0,8,4,0,2,5},
                        {0,13,0,2,0,15},
                        {9,0,3,5,15,0}
                    };

    // initMat(n, matrice);





    pred = dijkstra(n, temp);

    printf("-----------------");
    for (int i = 0; i < n; ++i) {
        printf("%d\n", *(pred+i));
    }





    free(matrice);
    free(pred);
    return 0;
}
