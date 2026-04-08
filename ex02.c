#include <stdio.h>

#define TAM 5

int main(void) {
    int v[TAM];

    printf("Digite %d números inteiros:\n", TAM);
    for (int i = 0; i < TAM; i++) {
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nVetor na ordem inversa:\n");
    for (int i = TAM - 1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
