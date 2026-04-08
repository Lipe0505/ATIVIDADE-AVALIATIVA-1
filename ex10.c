#include <stdio.h>
#include <stdlib.h>

#define NOME_MAX 50

typedef struct {
    char  nome[NOME_MAX];
    float nota;
} Aluno;

Aluno *maiorNota(Aluno *alunos, int qtd) {
    Aluno *maior = alunos;
    for (int i = 1; i < qtd; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = alunos + i;
        }
    }
    return maior;
}

int main(void) {
    int n;

    printf("Quantos alunos? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Número de alunos inválido.\n");
        return 1;
    }

    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (!alunos) {
        printf("Erro: memória insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome : ");
        scanf(" %49[^\n]", (alunos + i)->nome);
        printf("Nota : ");
        scanf("%f", &(alunos + i)->nota);
    }

    Aluno *destaque = maiorNota(alunos, n);

    printf("\n========== MAIOR NOTA ==========\n");
    printf("Nome : %s\n", destaque->nome);
    printf("Nota : %.1f\n", destaque->nota);

    free(alunos);
    return 0;
}
