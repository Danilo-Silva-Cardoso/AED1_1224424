/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Carteiro e quanto tempo ele demora para entregar
Dificuldade : Logica de juntar a buscabinaria com vetor
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
Duvida : poderia usar o long long int com %lld ?
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int buscabinaria (int x, int n, int v[]) {

    int e, m, d;

    e = -1; 
    d = n;

    while (e < d - 1) {

        m = (e + d)/2;

        if (v[m] < x) e = m;

        else d = m;

    }
    return d;
}
 
int main() {
    
    int n, m;
    int tempo = 0;
    
    scanf("%d %d", &n, &m);

    int v[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int v2[m];

    int pos_ini = 0;

    for(int z = 0; z < m; z++) {
        scanf("%d", &v2[z]);

        int pos_prox = buscabinaria(v2[z], n, v);

        tempo += abs(pos_prox - pos_ini);

        pos_ini = pos_prox;

    }
    
    printf("%d\n", tempo);
 
    return 0;
}
