#include <stdlib.h>
#include "grafo.h"

struct vertice {
    char nome[20];
    double latitude, longitude;
};

struct grafo {
    Vertice *vertice;
    int numVertices;
    int **matAdjacencia;
};

Grafo* cria_grafo(int tam) {
    int i;
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->vertice = (Vertice*) malloc(tam * sizeof(Vertice));
    g->matAdjacencia = (int**) malloc(tam * sizeof(int*));
    for(i = 0; i < tam; i++) {
        g->matAdjacencia[i] = (int*) malloc(tam * sizeof(int));
    }
    g->numVertices = tam;
    return g;
}

