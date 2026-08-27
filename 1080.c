#include <stdio.h>

int main() {
    
    int valor, maior, posicao=1;
    
    scanf("%d", &valor);
    maior = valor;

    for (int i = 2; i <= 100; i++) {
        scanf("%d", &valor);
        
        if (valor > maior) {
            maior = valor;
            posicao = i;
        }
    }

    printf("%d\n%d\n", maior, posicao);

    return 0;
}
