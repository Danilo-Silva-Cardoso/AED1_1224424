/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Maior e Posição, usando alocação dinâmica de vetores
Dificuldade : sintaxe do c com ponteiros
Uso de IA   : No maximo onde estava meus erros
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int maior, posicao=1, i , n = 100;
    int *valor;
    
    valor = (int *) malloc(n * sizeof(int));
    
    if ( valor == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }
    
    scanf("%d", &valor[0]);
    maior = valor[0];

    for (i = 1; i < n; i++) {
        scanf("%d", &valor[i]);
        
        if (valor[i] > maior) {
            maior = valor[i];
            posicao = i + 1;
        }
    }

    printf("%d\n%d\n", maior, posicao);
    
    free(valor);

    return 0;
}
