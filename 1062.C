/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 07/10/2026
Objetivo    : Verificar se os vagões podem ser empilhados em forma de pilha
Dificuldade : Na criação do while e não deixar algum if incompleto
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vagao;
    struct No *prox;
} No;

No* push(No* topo, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return topo;
    } else {
        novo->vagao = valor;
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

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {

        while (1) {
            int v2[n];

            scanf("%d", &v2[0]);
            
            if (v2[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &v2[i]);
            }

            No *topo = NULL;
            No *remover = NULL;
            int vagao_A = 1;
            int possivel = 1;

            for (int i = 0; i < n; i++) {
                while (vagao_A <= n && (topo == NULL || topo->vagao != v2[i])) {
                    topo = push(topo, vagao_A);
                    vagao_A++;
                }

                if (topo != NULL && topo->vagao == v2[i]) {
                    remover = pop(&topo);
                    free(remover);
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel && topo == NULL) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            while (topo != NULL) {
                remover = pop(&topo);
                free(remover);
            }
        }
    }

    return 0;
}
