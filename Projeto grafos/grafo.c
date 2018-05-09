#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"
#include "lista.h"

struct vertice {
    int id, grau;
    char nome[20];
    float latitude, longitude;
};

struct grafo {
    int numVertices, numArestas;
    Vertice *vertice;
    Lista **arestas;
};

Grafo *cria_grafo(int tam) {
    if(tam <= 0)
        printf("O grafo deve ter pelo menos um vertice.\n");
    else {
        Grafo *g = (Grafo*) malloc(tam * sizeof(Grafo));
        if(g == NULL)
            printf("Ocorreu um erro na alocacao do gafo.\n");
        else {
            g->vertice = (Vertice*) malloc(tam * sizeof(Vertice));
            if(g->vertice == NULL)
                printf("Ocorreu um erro na alocacao do vetor de vertices.\n");
            else {
                g->numVertices = tam;
                char strings[tam][50];
                FILE *f = fopen("nos.txt", "r");
                if(f == NULL) {
                    printf("Erro ao abrir o arquivo nos.txt.\n");
                } else {
                    for(int i = 0; i < tam; i++) {
                        fgets(strings[i], 50, f);
                    }
                    fclose(f);
                    for(int i = 0; i < tam; i++) {
                        g->vertice[i].id = atoi(strtok(strings[i], ";"));
                        strcpy(g->vertice[i].nome, strtok(NULL, ";"));
                        g->vertice[i].latitude = atof(strtok(NULL, ";"));
                        g->vertice[i].longitude = atof(strtok(NULL, ";"));
                    }
                }
                g->arestas = (Lista**) malloc(tam * sizeof(Lista*));
                if(g->arestas == NULL)
                    printf("Erro ao alocar o vetor de listas para representar as arestas.\n");
                else
                    for(int i = 0; i < numVertices(g); i++)
                        g->arestas[i] = cria_lista();
            }
        }
        return g;
    }
    return NULL;
}

int grauVertice(Grafo *g, int v) {
    if (g == NULL) {
        printf("Grafo inconsistente.\n");
        return -1;
    } else if (v < 0 || v > numVertices(g)) {
        printf("Vertice invalido.\n");
        return -1;
    } else {
        return g->vertice[v].grau;
    }
}

int ehAdjacente(Grafo *g, int v1, int v2) {
    if (g == NULL) {
        printf("Grafo inconsistente.\n");
        return -1;
    } else if(v1 < 0 || v1 > numVertices(g) || v2 < 0 || v2 > numVertices(g) || g->arestas[v1] == NULL) {
        printf("Vertice invalido.\n");
        return -1;
    } else {
        if (contem(g->arestas[v1], g->vertice[v2]))
            return 1;
        else
            return 0;
    }
}

void imprimeVertices(Grafo *g) {
    for(int i = 0; i < numVertices(g); i++)
        printf("id: %d\nnome: %s\nlatitude: %f\nlongitude: %f\n", g->vertice[i].id, g->vertice[i].nome, g->vertice[i].latitude, g->vertice[i].longitude);
}

int numVertices(Grafo *g) {
    //retorna -1 se for um grafo inválido
    if(g == NULL) {
        printf("Grafo invalido.\n");
        return -1;
    }
    return g->numVertices;
}

int insereAresta(Grafo *g, int v1, int v2, int peso) {
    if (g == NULL) {
        printf("Grafo invalido.\n");
        return -1;
    } else if (v1 < 0 || v1 > numVertices(g) || v2 < 0 || v2 > numVertices(g)){
        printf("Aresta invalida.\n");
        return -1;
    } else {
        if(contem(g->arestas[v2], g->vertice[v1])) {
            //return 1;
        }
        insereNaLista(g->arestas[v1], g->vertice[v2], peso);
        g->numArestas++;
    }
    return 1;
}

int leArestas(Grafo *g) {
    int nlinhas = countlines("arestas.txt");
    char strings[nlinhas][20];
    FILE *f = fopen("arestas.txt", "r");
    if(f == NULL)
        printf("Erro ao abrir o arquivo arestas.txt.\n");
    else {
        for(int i = 0; i <= nlinhas; i++) {
            fgets(strings[i], 20, f);
        }
        fclose(f);
        for(int i = 0; i <= nlinhas; i++) {
            int v1 = atoi(strtok(strings[i], ";"));
            int v2 = atoi(strtok(NULL, ";"));
            int peso = atoi(strtok(NULL, ";"));
            insereAresta(g, v1, v2, peso);
        }
    }
    return 1;
}

void imprimeListaAdj(Grafo *g) {
    for(int i = 0; i < numVertices(g); i++) {
        printf("Vertice %d: ", i);
        imprimeLista(g->arestas[i]);
        printf("\n");
    }
}

int countlines(char *file) {
    int lines = 0;
    FILE *f = fopen(file, "r+");
    if(f == NULL)
        printf("Erro ao abrir o arquivo %s.\n", file);
    else {
        char ch;
        while(!feof(f)) {
            ch = fgetc(f);
            if(ch == '\n') {
                lines++;
            }
        }
        fclose(f);
    }
    return lines;
}
