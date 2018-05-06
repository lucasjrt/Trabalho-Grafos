#include <stdlib.h>
#include <stdio.h>
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
    if(tam <= 0) printf("Erro, o grafo deve ter pelo menos um vertice.\n");
    else {
        int i;
        Grafo *g = (Grafo*) malloc(sizeof(Grafo));
        if(g != NULL) {
            g->vertice = (Vertice*) malloc(tam * sizeof(Vertice));
            if(g->vertice != NULL) {
                g->matAdjacencia = (int**) malloc(tam * sizeof(int*));
                if(g->matAdjacencia != NULL) {
                    for(i = 0; i < tam; i++) {
                        g->matAdjacencia[i] = (int*) malloc(tam * sizeof(int));
                        if(g->matAdjacencia[i] != NULL) continue;
                        else {
                            printf("Nao foi possivel alocar espaco na posicao %d, cancelando a alocacao das outras posicoes.\n", i);
                            break;
                        }
                    }
                } else {
                    printf("Nao foi possivel alocar espaco para o vetor de ponteiros da matriz de adjacencia.\n");
                }
            } else {
                printf("Nao foi possivel alocar espaco para o vetor de vertices.\n");
            }
            g->numVertices = tam;
        } else {
            printf("Nao foi possivel alocar espaco para o grafo.\n");
        }
    }
    return g;
}

int numVertices(Grafo *g) {
    //retorna -1 se for um grafo inválido
    if(g == NULL) {
        printf("Grafo invalido.\n");
        return -1;
    }
    return g->numVertices;
}
