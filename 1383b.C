/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 01/09/2026
Objetivo    : Jogo do sudoku usando locação dinamica
Dificuldade : A estrutura dos ponteiros
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int sudoku(int i , int j, int **matriz){

    for( i = 0; i < 9; i++) {
        for( j = 0; j < 9; j++) {
            int valor = matriz[i][j];

            if(valor == 0) continue;

            for(int l = 0; l < 9; l++) {
                if(valor == matriz[i][l] && l != j) {
                    return 1;
                }
            }
        }
    }

    for( j = 0; j < 9; j++) {
        for( i = 0; i < 9; i++) {
            int valor = matriz[i][j];

            if(valor == 0) continue;

            for(int l = 0; l < 9; l++) {
                if(valor == matriz[l][j] && l != i) {
                    return 1;
                }
            }
        }
    }

    for( i = 0; i < 9; i += 3) {
        for( j = 0; j < 9; j += 3) {
            int visitados[10] = {0};

            for(int l = 0 ; l < 3; l++) {
                for(int k = 0; k < 3; k++) {
                    int bloco = matriz[l + i][j + k];

                    if(bloco == 0) continue;

                    if(visitados[bloco] == 1) {
                        return 1;
                    }
                    visitados[bloco] = 1;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int **matriz;
    int i, j, n, linhas = 9, colunas = 9;
    int jogo;

    scanf("%d", &n);
    
    matriz = (int **) malloc(linhas * sizeof(int *));
    if(matriz == NULL) {
        printf("Erro de locação\n");
        return 1;
    }

    for(i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de locação\n");
            return 1;
        }
    }

    for (int k = 0; k < n ; k++ ) {
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        jogo = sudoku(i, j, matriz);

        printf("Instancia %d\n", k + 1);
        if(jogo == 1) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }
        printf("\n");

    }

    for(int p = 0; p < linhas; p++) {
        free(matriz[p]);
    }

    free(matriz);

    return 0;
}
