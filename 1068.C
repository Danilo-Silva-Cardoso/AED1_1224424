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
