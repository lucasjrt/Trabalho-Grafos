#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

struct fila {
    No *inicio, *fim;
    int tam;
};

struct no {
    int valor;
    struct no *prox;
};

//Retorna um ponteiro par auma fila alocada
Fila* cria_fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    return f;
}

//Insere um valor no fim da fila
int enfileira(Fila *f, int valor) {
    if(f == NULL) {
        printf("Fila invalida.\n");
        return -1;
    }
    No* n = (No*) malloc(sizeof(noSize()));
    n->valor = valor;
    if(tamFila(f) == 0) {
        f->inicio = n;
        f->fim = n;
    } else {
        n->prox = f->fim;
        f->fim = n;
    }
    f->tam++;
    return 1;
}

//Remove o primeiro valor da fila
int desenfileira(Fila *f) {
    int i;
    if(f == NULL) {
        printf("Lista invalida.\n");
        return -1;
    } else if (f->tam == 0) {
        printf("Impossivel desenfileirar uma fila vazia.\n");
        return -1;
    }
    int tam = tamFila(f);
    No *aux = f->fim;
    for(i = 0; i < tam - 2; i++)
        aux = aux->prox;
    free(aux->prox);
    f->inicio = aux->prox;
    f->tam--;
    return 1;
}

//Retorna o tamanho da fila (-1 se inv�lido)
int tamFila(Fila *f) {
    if(f == NULL) {
        printf("Fila invalida.\n");
        return -1;
    }
    else return f->tam;
}

//Imprime a fila f
void imprimeFila(Fila *f) {
    int i;
    No *aux = f->fim;
    int tam = tamFila(f);
    for(i = 0; i < tam; i++) {
        printf("%d", aux->valor);
        aux = aux->prox;
        if(i < tam - 1) printf(", ");
    }
}
