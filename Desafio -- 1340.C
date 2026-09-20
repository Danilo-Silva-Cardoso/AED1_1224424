/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 20/09/2026
Objetivo    : Adivinhar a Estrutura de Dados!
Dificuldade : Fazer a estrutura do exercicio achei meio confuso o enunciado
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int pilha[1000];
        int tam_pilha = 0;

        int fila[1000];
        int inicio_fila = 0, fim_fila = 0;

        int fila_prio[1000];
        int tam_prio = 0;

        int e_pilha = 1;
        int e_fila = 1;
        int e_prio = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                if (e_pilha) {
                    pilha[tam_pilha++] = x;
                }
                if (e_fila) {
                    fila[fim_fila++] = x;
                }
                if (e_prio) {
                    fila_prio[tam_prio++] = x;
                }
            } else if (op == 2) {
                if (e_pilha) {
                    if (tam_pilha == 0 || pilha[--tam_pilha] != x) {
                        e_pilha = 0;
                    }
                }
                if (e_fila) {
                    if (inicio_fila == fim_fila || fila[inicio_fila++] != x) {
                        e_fila = 0;
                    }
                }
                if (e_prio) {
                    if (tam_prio == 0) {
                        e_prio = 0;
                    } else {
                        int idx_max = 0;
                        for (int j = 1; j < tam_prio; j++) {
                            if (fila_prio[j] > fila_prio[idx_max]) {
                                idx_max = j;
                            }
                        }
                        if (fila_prio[idx_max] != x) {
                            e_prio = 0;
                        }
                        fila_prio[idx_max] = fila_prio[--tam_prio];
                    }
                }
            }
        }

        int total_validos = e_pilha + e_fila + e_prio;

        if (total_validos == 0) {
            printf("impossible\n");
        } else if (total_validos > 1) {
            printf("not sure\n");
        } else if (e_pilha) {
            printf("stack\n");
        } else if (e_fila) {
            printf("queue\n");
        } else if (e_prio) {
            printf("priority queue\n");
        }
    }

    return 0;
}
