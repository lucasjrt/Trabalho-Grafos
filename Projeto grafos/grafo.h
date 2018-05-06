#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
typedef struct vertice Vertice;
typedef struct grafo Grafo;

Grafo* cria_grafo(int tam);
int numVertices(Grafo *g);
void imprimeVertices(Grafo *g);

#endif // GRAFO_H_INCLUDED
