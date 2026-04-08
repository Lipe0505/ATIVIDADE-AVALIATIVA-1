# Atividade Avaliativa 1 — Estruturas de Dados em C

Repositório com os exercícios da Atividade Avaliativa 1 e os exemplos de código apresentados em aula, da disciplina de Estruturas de Dados.

---

## 📁 Estrutura do Repositório

```
.
├── exemplos/        # Códigos demonstrados em aula
├── ex01.c           # Palavras em ordem inversa
├── ex02.c           # Vetor invertido
├── ex03.c           # Matriz × 5
├── ex04.c           # Matriz identidade
├── ex05.c           # Vetor × colunas da matriz
├── ex06.c           # Alunos aprovados e reprovados (struct)
├── ex07.c           # Busca de livros por título (struct)
├── ex08.c           # Aritmética de ponteiros
├── ex09.c           # Ordenação por referência
├── ex10.c           # Alocação dinâmica e maiorNota
└── README.md
```

---

## ⚙️ Como Compilar e Executar

Qualquer exercício pode ser compilado com **GCC**:

```bash
gcc -Wall -o ex01 ex01.c && ./ex01
```

Substitua `ex01` pelo nome desejado (ex02, ex03, …, ex10).

---

## 📝 Exercícios

---

### Exercício 1 — Palavras em Ordem Inversa (`ex01.c`)

**Objetivo:** Ler três palavras e exibi-las na ordem inversa.

**Solução:** Três strings de até 50 caracteres são lidas com `scanf`. A impressão é feita simplesmente invertendo a ordem das variáveis na chamada de `printf`.

**Exemplo:**
```
Digite a primeira palavra: Estruturas
Digite a segunda palavra: de
Digite a terceira palavra: Dados

Palavras na ordem inversa:
Dados de Estruturas
```

---

### Exercício 2 — Vetor Invertido (`ex02.c`)

**Objetivo:** Armazenar 5 inteiros em um vetor e imprimir na ordem inversa.

**Solução:** O vetor é preenchido com índices `0..4` e impresso percorrendo-o de `4` até `0` com um `for` decrescente.

**Exemplo:**
```
Digite 5 números inteiros:
v[0]: 10  v[1]: 20  v[2]: 30  v[3]: 40  v[4]: 50

Vetor na ordem inversa:
50 40 30 20 10
```

---

### Exercício 3 — Matriz × 5 (`ex03.c`)

**Objetivo:** Ler uma matriz 3×3 e imprimir cada elemento multiplicado por 5.

**Solução:** Dois `for` aninhados leem a matriz. Na impressão, cada elemento é multiplicado por 5 diretamente na chamada de `printf`, sem necessidade de uma segunda matriz.

**Exemplo de saída (entrada: todos os elementos = 2):**
```
Matriz multiplicada por 5:
    10    10    10
    10    10    10
    10    10    10
```

---

### Exercício 4 — Matriz Identidade (`ex04.c`)

**Objetivo:** Exibir a matriz identidade e provar que `A × I = A`.

**Solução:**
- A matriz identidade `I` é gerada programaticamente: zeros em todo lugar, exceto na diagonal principal onde o valor é `1.0`.
- A função `multiplicar` implementa a multiplicação de matrizes clássica em O(n³).
- O resultado de `A × I` é impresso para comparação com a matriz `A` original.

**Conceito:** A matriz identidade é o elemento neutro da multiplicação de matrizes, assim como o número 1 é para a multiplicação escalar.

---

### Exercício 5 — Vetor × Colunas da Matriz (`ex05.c`)

**Objetivo:** Multiplicar um vetor linha (1×3) pelas colunas de uma matriz 3×3.

**Solução:** O resultado é um vetor de 3 elementos onde cada posição `j` é o produto interno entre o vetor `v` e a coluna `j` da matriz:

```
resultado[j] = Σ v[i] * m[i][j],  para i = 0..2
```

O laço externo percorre colunas e o interno percorre as linhas, acumulando o produto.

---

### Exercício 6 — Aprovados e Reprovados (`ex06.c`)

**Objetivo:** Ler dados de 10 alunos e separá-los em aprovados (média ≥ 5,0) e reprovados.

**Solução:**
- `struct Aluno` contém `nome` (string), `matricula` (string) e `media` (float).
- Após a leitura, um único `for` percorre o vetor principal e copia cada aluno para `aprovados[]` ou `reprovados[]` com base na comparação da média.
- A função `exibir_aluno` recebe um ponteiro constante para evitar cópia desnecessária.

---

### Exercício 7 — Busca de Livros por Título (`ex07.c`)

**Objetivo:** Cadastrar 5 livros e buscar por título exato.

**Solução:**
- `struct Livro` contém `titulo` (30 chars), `autor` (15 chars) e `ano` (int).
- A leitura usa `scanf(" %30[^\n]", ...)` para capturar títulos com espaços.
- A busca percorre o vetor comparando com `strcmp`. Todos os livros com título igual ao buscado são exibidos.
- A flag `encontrado` controla a mensagem de "não encontrado".

---

### Exercício 8 — Aritmética de Ponteiros (`ex08.c`)

**Objetivo:** Ler e imprimir o dobro de 5 inteiros usando **apenas** aritmética de ponteiros.

**Solução:**
- Um ponteiro `int *p` aponta para o início do array.
- Na leitura: `scanf("%d", p + i)` — o endereço é calculado por aritmética de ponteiros.
- Na impressão: `*(p + i)` acessa o valor sem usar o operador `[]`.

---

### Exercício 9 — Ordenação por Referência (`ex09.c`)

**Objetivo:** Ordenar três inteiros por referência e retornar `1` se todos forem iguais.

**Solução:**
- A função `ordenar(int *a, int *b, int *c)` implementa três comparações (bubble sort adaptado para 3 elementos) usando a função auxiliar `trocar`.
- A passagem por referência (ponteiros) garante que as variáveis originais do `main` sejam modificadas.
- O retorno é `1` se `*a == *b == *c`, e `0` caso contrário.

**Casos de teste:**

| Entrada   | Saída ordenada | Retorno |
|-----------|---------------|---------|
| 9, 3, 6   | 3, 6, 9       | 0       |
| 5, 5, 5   | 5, 5, 5       | 1       |
| -1, 0, -5 | -5, -1, 0     | 0       |

---

### Exercício 10 — Alocação Dinâmica e `maiorNota` (`ex10.c`)

**Objetivo:** Alocar dinamicamente `n` alunos e encontrar o de maior nota via ponteiro.

**Restrições atendidas:**
- ✅ Sem variáveis globais.
- ✅ Sem vetor estático (usa `malloc`).
- ✅ Elementos acessados somente por ponteiros (`alunos + i`, `->`, `&(alunos+i)->nota`).

**Solução:**
- `malloc(n * sizeof(Aluno))` aloca o bloco contíguo de memória.
- A leitura usa `(alunos + i)->campo` em vez de `alunos[i].campo`.
- `maiorNota(Aluno *alunos, int qtd)` itera com aritmética de ponteiros, mantendo um ponteiro `maior` que é atualizado sempre que um aluno com nota superior é encontrado.
- Ao final, `free(alunos)` libera a memória alocada.

**Diagrama de memória (exemplo com n=3):**
```
alunos ──► [ Aluno 0 | Aluno 1 | Aluno 2 ]
            ↑                   ↑
        alunos+0             alunos+2
```

---

| Nome Completo | Usuário GitHub |
|---------------|----------------|
|  André Felipe            |    Lipe0505    |
|  Erick Sartori           |                |

---
