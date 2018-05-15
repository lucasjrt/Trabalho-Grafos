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

//Retorna um ponteiro para uma lista alocada
Lista* cria_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tam = 0;
    return l;
}

//Retorna um ponteiro para um no alocado
No* cria_no() {
    No *n = (No*) malloc(sizeof(No));
    return n;
}

//Retorna a cabeça da lista
No* getCabeca(Lista *l) {
    if(l == NULL) {
        No *no = NULL;
        printf("Lista invalida.\n");
        return no;
    } else {
        return l->cabeca;
    }
}

//Retorna o tamanho da lista (-1 se inválida)
int tamLista(Lista *l) {
    if(l == NULL) {
        printf("Lista invalida.\n");
        return -1;
    } else {
        return l->tam;
    }
}

//Adiciona um vértice à lista de ajdacência com um peso
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

//Remove o vertice da lista l
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

//Desaloca todos os nos da lista e por fim, a lista
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

//Retorna 1 se a lista l contém o vértice ou 0 se a lista não contém o vértice
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

//Retorna o peso da aresta referente a lista l e o vertice com id v
int getPeso(Lista *l, int v) {
    int i;
    No *aux = l->cabeca;
    for(i = 0; i < l->tam; i++) {
        if(aux->vertice.id == v) {
            break;
        }
        else {
            aux = aux->prox;
        }
    }
    return aux->peso;
}

//Retorna o sizeof(Lista)
int listaSize() {
    return sizeof(Lista);
}

//Retorna o sizeof(No)
int noSize() {
    return sizeof(No);
}

//Retorna o prox do no
No* getProx(No *no) {
    return no->prox;
}

//Define o no n2 como prox do no n1
void setProx(No *n1, No *n2) {
    n1->prox = n2;
}

//Imprime a lista l
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
