#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void enfileirar(Fila *f, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    if (f->inicio == NULL) return -1;

    No *temp = f->inicio;
    int valor = temp->valor;

    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;
    return valor;
}

void limparFila(Fila *f) {
    while (f->inicio != NULL) {
        desenfileirar(f);
    }
}

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Fila f;
        inicializarFila(&f);

        for (int i = 1; i <= n; i++) {
            enfileirar(&f, i);
        }

        printf("Discarded cards:");
        int primeiro = 1;

        while (f.tamanho >= 2) {
            int descartada = desenfileirar(&f);
            if (primeiro) {
                printf(" %d", descartada);
                primeiro = 0;
            } else {
                printf(", %d", descartada);
            }

            int movida = desenfileirar(&f);
            enfileirar(&f, movida);
        }
        printf("\n");

        if (f.inicio != NULL) {
            printf("Remaining card: %d\n", f.inicio->valor);
        }

        limparFila(&f);
    }

    return 0;
}
