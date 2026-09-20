/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Danilo Da Silva Cardoso
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 18/09/2026
Objetivo    : Checagem de parenteses
Dificuldade : Fazer a estrutura da pilha
Uso de IA   : Perguntei onde estava errando e fui pedindo atraves de perguntas sem ela me dar a resposta como me ajudar
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    char parenteses;
    struct pilha *proximo;
} pilha;


pilha* empilhar( pilha *topo, char valor) {
    
    pilha *novo = (pilha*) malloc(sizeof(pilha));

    if(novo == NULL) {
        return topo;
    }

    if(novo != NULL) {
        novo -> parenteses = valor;
        novo->proximo = topo;
        return novo;
    }

    return NULL;
}

pilha* desempilhar(pilha **topo){

    if(*topo != NULL) {
        pilha *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else {
        return NULL;
    }

}

int main() {
    pilha *topo = NULL;
    char expressao[1001];
    pilha *remover = NULL;

    while(fgets(expressao, sizeof(expressao), stdin) != NULL) {
        topo = NULL;
        int qtd_erro = 0;

        for(int i=0; expressao[i] != '\0'; i++) {

            if(expressao[i] == '(' ) {
                topo = empilhar(topo, expressao[i]);
            }
            
            if(expressao[i] == ')' ) {
                remover = desempilhar(&topo);
                if(remover == NULL){
                    qtd_erro += 1;
                    continue;
                }
                else {
                    free(remover);
                }
            }
        }

        if(qtd_erro == 0 && topo == NULL) {
            printf("correct\n");
        }

        else {
            printf("incorrect\n");
        }

        while ((remover = desempilhar(&topo)) != NULL) {
            free(remover);
        }
    }
}
