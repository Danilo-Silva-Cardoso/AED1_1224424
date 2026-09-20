/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Checagem de parenteses
Dificuldade : sintaxe do c
Uso de IA   : No maximo onde estava meus erros
-------------------------------------------------------------------------- */

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
