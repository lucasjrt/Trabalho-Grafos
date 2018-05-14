#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "lista.h"

struct vertice {
    int id;
    char nome[30];
    float latitude, longitude;
};

struct no {
    Vertice vertice;
    int peso;
    struct no *prox;
};

struct lista {
    No *cabeca, *cauda;
    int tam;
};

Lista* cria_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tam = 0;
    return l;
}

No* cria_no() {
    No *n = (No*) malloc(sizeof(No));
    return n;
}

No* getCabeca(Lista *l) {
    if(l == NULL) {
        No *no = NULL;
        printf("Lista invalida.\n");
        return no;
    } else {
        return l->cabeca;
    }
}

int tamLista(Lista *l) {
    if(l == NULL) {
        printf("Lista invalida.\n");
        return -1;
    } else {
        return l->tam;
    }
}

int insereNaLista(Lista *l, Vertice vertice, int peso) {
    if(l == NULL) {
        printf("Lista invalida.\n");
        return -1;
    }
    No *n = (No*) malloc(sizeof(No));
    n->vertice = vertice;
    n->peso = peso;
    n->prox = NULL;
    if (tamLista(l) == 0) {
        l->cabeca = n;
    } else {
        l->cauda->prox = n;
    }
    l->cauda = n;
    l->tam++;
    return 1;
}

int removeDaLista(Lista *l, Vertice vertice) {
    if(l == NULL) {
        printf("Lista invalida.\n");
        return -1;
    }
    No *aux = l->cabeca;
    No *q;
    while(aux->prox->vertice.id != vertice.id) {
        aux = aux->prox;
    }
    q  = aux->prox;
    aux->prox = q->prox;
    free(q);
    l->tam--;
    return 1;
}

int destroiLista(Lista *l) {
    No *aux1, *aux2;
    aux1 = l->cabeca;
    aux2 = l->cabeca->prox;
    while(aux2->prox != NULL) {
        free(aux1);
        aux1 = aux2;
        aux2 = aux2->prox;
    }
    free(aux1);
    free(l);
    return 1;
}

int contem(Lista *l, Vertice vertice) {
    No *aux = l->cabeca;
    while(aux != NULL) {
        if(aux->vertice.id == vertice.id) {
            break;
        }
        else {
            aux = aux->prox;
        }
    }
    if(aux == NULL)
        return 0;
    return 1;
}

int listaSize() {
    return sizeof(Lista);
}

int noSize() {
    return sizeof(No);
}

No* getProx(No *no) {
    return no->prox;
}

void setProx(No *n1, No *n2) {
    n1->prox = n2;
}

void imprimeLista(Lista *l) {
    No *aux = l->cabeca;
    int tam = tamLista(l);
    for(int i = 0; i < tam; i++) {
        printf("|%3d|%5d|  | -> ", aux->vertice.id, aux->peso);
        if(i == tam - 1) printf("NULL");
        aux = aux->prox;
    }
    printf("\n");
}
