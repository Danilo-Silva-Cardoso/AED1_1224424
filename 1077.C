/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 24/09/2026
Objetivo    : expressão Infixa para Posfixa
Dificuldade : Checar os valores do topo da pilha
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct No {
    char op;
    struct No *prox;
} No;

No* push(No *topo, char valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        return topo;
    } else {
        novo->op = valor;
        novo->prox = topo;
        return novo;
    }
}

No* pop(No **topo) {
    if (*topo != NULL) {
        No *remover = *topo;
        *topo = remover->prox;
        return remover;
    } else {
        return NULL;
    }
}

int precedencia(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    No *topo = NULL;
    No *remover = NULL;

    scanf("%d", &n);
    getchar();

    while (n--) {
        char expressao[301];

        fgets(expressao, sizeof(expressao), stdin);

        topo = NULL;

        for (int i = 0; expressao[i] != '\0'; i++) {

            if (expressao[i] == '(') {
                topo = push(topo, expressao[i]);
            }

            if (expressao[i] == ')') {
                while (topo != NULL && topo->op != '(') {
                    remover = pop(&topo);
                    printf("%c", remover->op);
                    free(remover);
                }
                remover = pop(&topo);
                free(remover);
            }

            if (isalpha(expressao[i]) || isdigit(expressao[i])) {
                printf("%c", expressao[i]);
            }

            if (expressao[i] == '^' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '+' || expressao[i] == '-') {
                while (topo != NULL && precedencia(topo->op) >= precedencia(expressao[i]) && topo->op != '(') {
                    remover = pop(&topo);
                    printf("%c", remover->op);
                    free(remover);
                }
                topo = push(topo, expressao[i]);
            }
        }

        while (topo != NULL) {
            remover = pop(&topo);
            printf("%c", remover->op);
            free(remover);
        }

        printf("\n");
    }

    return 0;
}
