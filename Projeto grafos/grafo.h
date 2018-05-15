#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct vertice Vertice;
typedef struct grafo Grafo;

Grafo* cria_grafo(int tam);
int numVertices(Grafo *g);
int leArestas(Grafo *g);
int insereAresta(Grafo *g, int v1, int v2, int peso);
int ehAdjacente(Grafo *g, int v1, int v2);
int grauVertice(Grafo *g, int v);
int pesoAresta(Grafo *g, int v1, int v2);
void busca_largura(Grafo *g, int v);
void dijkstra(Grafo *g, int po, int pd);
void imprimeVertices(Grafo *g);
void imprimeListaAdj(Grafo *g);
void imprimeListaAdjDet(Grafo *g);
int destroigrafo(Grafo *g);
int countlines(char *file);
int* ncharline(char *file);

#endif // GRAFO_H_INCLUDED
