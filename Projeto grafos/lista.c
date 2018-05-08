#include <stdio.h>
#include "grafo.h"
#include "lista.h"

struct vertice {
    int id;
    char nome[20];
    float latitude, longitude;
};

struct no {
    Vertice v;
    struct no *prox;
};

struct lista {
    No *cabeca, *cauda;
    int tam;
};
