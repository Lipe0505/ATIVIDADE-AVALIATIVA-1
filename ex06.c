/*
 * Exercício 6
 * Lê dados de 10 alunos (nome, matrícula, média) via struct.
 * Divide em vetores de aprovados (média >= 5.0) e reprovados.
 */

#include <stdio.h>
#include <string.h>

#define TOTAL    10
#define NOME_MAX 50
#define MAT_MAX  15
#define MEDIA_MIN 5.0f

typedef struct {
    char  nome[NOME_MAX];
    char  matricula[MAT_MAX];
    float media;
} Aluno;

void exibir_aluno(const Aluno *a) {
    printf("  Nome: %-30s | Matrícula: %-12s | Média: %.1f\n",
           a->nome, a->matricula, a->media);
}

int main(void) {
    Aluno alunos[TOTAL];
    Aluno aprovados[TOTAL], reprovados[TOTAL];
    int n_apr = 0, n_rep = 0;

    for (int i = 0; i < TOTAL; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Matrícula: ");
        scanf(" %14s", alunos[i].matricula);
        printf("Média Final: ");
        scanf("%f", &alunos[i].media);
    }

    /* Separação */
    for (int i = 0; i < TOTAL; i++) {
        if (alunos[i].media >= MEDIA_MIN) {
            aprovados[n_apr++] = alunos[i];
        } else {
            reprovados[n_rep++] = alunos[i];
        }
    }

    /* Exibição */
    printf("\n========== APROVADOS (%d) ==========\n", n_apr);
    for (int i = 0; i < n_apr; i++) {
        exibir_aluno(&aprovados[i]);
    }

    printf("\n========== REPROVADOS (%d) ==========\n", n_rep);
    for (int i = 0; i < n_rep; i++) {
        exibir_aluno(&reprovados[i]);
    }

    return 0;
}
