/*
 * Exercício 3
 * Lê uma matriz 3x3, multiplica cada elemento por 5 e imprime o resultado.
 */

#include <stdio.h>

#define N 3

int main(void) {
    int m[N][N];

    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("\nMatriz multiplicada por 5:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", m[i][j] * 5);
        }
        printf("\n");
    }

    return 0;
}
