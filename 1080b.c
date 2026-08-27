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
