#include <stdio.h>
#include <stdlib.h>


void initMat(int n, float* matrice) {

    printf("Veuillez saisire la matrice des poids : \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("mat(%d, %d) : ", i+1, j+1);
                scanf("%f", (matrice+i*n+j));
            } while (*(matrice+i*n+j) < 0);
        }
    }
}

int main( )
{
    int n;
    float* matrice;

    printf("Veuillez saisire le nombre de sommets : ");
    scanf("%d", &n);

    matrice = malloc(n*n*sizeof(float));
    initMat(n, matrice);
    

    return 0;
}
