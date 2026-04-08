#include <stdio.h>

#define TAM 5

int main(void) {
    int v[TAM];
    int *p = v;

    printf("Digite %d valores inteiros:\n", TAM);
    for (int i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%d", p + i);
    }

    printf("\nDobro de cada valor lido:\n");
    for (int i = 0; i < TAM; i++) {
        printf("2 * %d = %d\n", *(p + i), 2 * *(p + i));
    }

    return 0;
}
