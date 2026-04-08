/*
 * Exercício 7
 * Lê dados de 5 livros (título, autor, ano) e busca por título.
 */

#include <stdio.h>
#include <string.h>

#define QTD_LIVROS  5
#define TITULO_MAX 31
#define AUTOR_MAX  16

typedef struct {
    char titulo[TITULO_MAX];
    char autor[AUTOR_MAX];
    int  ano;
} Livro;

int main(void) {
    Livro livros[QTD_LIVROS];
    char busca[TITULO_MAX];
    int encontrado = 0;

    for (int i = 0; i < QTD_LIVROS; i++) {
        printf("\n--- Livro %d ---\n", i + 1);
        printf("Título (máx 30 chars): ");
        scanf(" %30[^\n]", livros[i].titulo);
        printf("Autor  (máx 15 chars): ");
        scanf(" %15[^\n]", livros[i].autor);
        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }

    printf("\nDigite o título que deseja buscar: ");
    scanf(" %30[^\n]", busca);

    printf("\n========== RESULTADOS ==========\n");
    for (int i = 0; i < QTD_LIVROS; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("Título : %s\n", livros[i].titulo);
            printf("Autor  : %s\n", livros[i].autor);
            printf("Ano    : %d\n\n", livros[i].ano);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado com o título \"%s\".\n", busca);
    }

    return 0;
}
