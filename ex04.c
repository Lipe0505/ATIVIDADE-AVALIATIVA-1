/*
 * Exercício 4
 * Imprime a matriz identidade 3x3 e prova que A * I = A.
 */

#include <stdio.h>

#define N 3

void imprimir_matriz(double m[N][N], const char *titulo) {
    printf("%s\n", titulo);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.2f", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicar(double a[N][N], double b[N][N], double res[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    double A[N][N], I[N][N] = {{0}}, resultado[N][N];

    printf("Digite os elementos da matriz A (3x3):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    /* Monta a matriz identidade */
    for (int i = 0; i < N; i++) {
        I[i][i] = 1.0;
    }

    imprimir_matriz(A, "\nMatriz A:");
    imprimir_matriz(I, "Matriz Identidade (I):");

    multiplicar(A, I, resultado);
    imprimir_matriz(resultado, "Resultado de A * I (deve ser igual a A):");

    return 0;
}
