/*
 * Exercício 10
 * Struct Aluno (nome + nota), alocação dinâmica para n alunos.
 * Função maiorNota retorna ponteiro para o aluno com maior nota.
 *
 * Restrições atendidas:
 *  - Sem variáveis globais.
 *  - Sem vetor estático (memória alocada com malloc).
 *  - Elementos acessados apenas por ponteiros.
 */

#include <stdio.h>
#include <stdlib.h>

#define NOME_MAX 50

typedef struct {
    char  nome[NOME_MAX];
    float nota;
} Aluno;

/* Recebe ponteiro para o primeiro Aluno e a quantidade.
   Retorna ponteiro para o aluno com a maior nota. */
Aluno *maiorNota(Aluno *alunos, int qtd) {
    Aluno *maior = alunos;                 /* ponteiro para o primeiro */
    for (int i = 1; i < qtd; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = alunos + i;            /* atualiza sem usar índice [] */
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

    /* Alocação dinâmica – sem vetor estático */
    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (!alunos) {
        printf("Erro: memória insuficiente.\n");
        return 1;
    }

    /* Leitura via aritmética de ponteiros */
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome : ");
        scanf(" %49[^\n]", (alunos + i)->nome);
        printf("Nota : ");
        scanf("%f", &(alunos + i)->nota);
    }

    /* Busca o aluno com maior nota */
    Aluno *destaque = maiorNota(alunos, n);

    printf("\n========== MAIOR NOTA ==========\n");
    printf("Nome : %s\n", destaque->nome);
    printf("Nota : %.1f\n", destaque->nota);

    free(alunos);
    return 0;
}
