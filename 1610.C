/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 19/11/2026
Objetivo    : Utilizar DFS para documentos e suas demandas
Dificuldade : AJustar para não acontecer o run time error
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int dfs(char **grafo, int v, int visitado[], int n) {

    visitado[v] = 1;

    for (int i = 1; i <= n; i++) {

        if (grafo[v][i] == 1) {
            if (visitado[i] == 1) {
                return 1;
            }
            if (visitado[i] == 2) {
                continue;
            }
            if (visitado[i] == 0) {
                if (dfs(grafo, i, visitado, n) == 1) return 1;
            }
        }
    }

    visitado[v] = 2;
    return 0;
}

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        char **grafo = (char **)malloc((n + 1) * sizeof(char *));
        for (int i = 0; i <= n; i++) {
            grafo[i] = (char *)calloc(n + 1, sizeof(char));
        }
        int *visitado = (int *)calloc(n + 1, sizeof(int));

        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a][b] = 1;
        }

        int temp_loop = 0;

        for (int i = 1; i <= n; i++) {
            if (visitado[i] == 0) {
                if (dfs(grafo, i, visitado, n) == 1) {
                    temp_loop = 1;
                    break;
                }
            }
        }

        if (temp_loop == 0) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }

        for (int i = 0; i <= n; i++) {
            free(grafo[i]);
        }
        free(grafo);
        free(visitado);
    }

    return 0;
}
