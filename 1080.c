#include <stdio.h>

int main() {
    int valor, maior = 0, posicao = 0;

    for (int i = 1; i <= 100; i++) {
        scanf("%d", &valor);

        if (valor > maior) {
            maior = valor;
            posicao = i;
        }
    }

    printf("%d\n%d\n", maior, posicao);

    return 0;
}
