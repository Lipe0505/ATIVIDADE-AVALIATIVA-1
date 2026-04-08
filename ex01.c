#include <stdio.h>

#define TAM 50

int main(void) {
    char p1[TAM], p2[TAM], p3[TAM];

    printf("Digite a primeira palavra: ");
    scanf("%49s", p1);
    printf("Digite a segunda palavra: ");
    scanf("%49s", p2);
    printf("Digite a terceira palavra: ");
    scanf("%49s", p3);

    printf("\nPalavras na ordem inversa:\n");
    printf("%s %s %s\n", p3, p2, p1);

    return 0;
}
