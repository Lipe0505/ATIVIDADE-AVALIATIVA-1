#include <stdio.h>

#define N 3

int main(void) {
    double v[N], m[N][N], resultado[N];

    printf("Digite os %d elementos do vetor:\n", N);
    for (int i = 0; i < N; i++) {
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
    }

    printf("\nDigite os elementos da matriz 3x3:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%lf", &m[i][j]);
        }
    }

    for (int j = 0; j < N; j++) {
        resultado[j] = 0;
        for (int i = 0; i < N; i++) {
            resultado[j] += v[i] * m[i][j];
        }
    }

    printf("\nResultado da multiplicação do vetor pelas colunas da matriz:\n");
    for (int j = 0; j < N; j++) {
        printf("resultado[%d] = %.2f\n", j, resultado[j]);
    }

    return 0;
}
