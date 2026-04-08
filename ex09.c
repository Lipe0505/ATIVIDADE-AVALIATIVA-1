/*
 * Exercício 9
 * Lê três inteiros. Chama função que os ordena por referência
 * (menor → meio → maior) e retorna 1 se todos forem iguais, 0 caso contrário.
 */

#include <stdio.h>

/* Troca os valores de dois inteiros via ponteiros */
void trocar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Ordena *a <= *b <= *c usando bubble sort de 3 elementos.
 * Retorna 1 se todos forem iguais, 0 caso contrário.
 */
int ordenar(int *a, int *b, int *c) {
    if (*a > *b) trocar(a, b);
    if (*b > *c) trocar(b, c);
    if (*a > *b) trocar(a, b);

    return (*a == *b && *b == *c) ? 1 : 0;
}

int main(void) {
    int x, y, z;

    printf("Digite três valores inteiros:\n");
    printf("Primeiro : "); scanf("%d", &x);
    printf("Segundo  : "); scanf("%d", &y);
    printf("Terceiro : "); scanf("%d", &z);

    int iguais = ordenar(&x, &y, &z);

    printf("\nValores ordenados:\n");
    printf("Primeira variável (menor)  : %d\n", x);
    printf("Segunda variável (meio)    : %d\n", y);
    printf("Terceira variável (maior)  : %d\n", z);

    if (iguais) {
        printf("\nOs três valores são iguais.\n");
    } else {
        printf("\nExistem valores diferentes.\n");
    }

    return 0;
}
