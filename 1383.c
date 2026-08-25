
int sudoku(int i , int j, int matriz[9][9]){

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

#include <stdio.h>

int main()
{
    int matriz[9][9];
    int i, j, n;
    int jogo;

    scanf("%d", &n);

    for (int k = 0; k < n ; k++ ) {
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
            
            jogo = sudoku(i, j, matriz);
        }

        printf("Instancia %d\n", k + 1);

        if(jogo == 1) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }
        printf("\n");
    }
}
