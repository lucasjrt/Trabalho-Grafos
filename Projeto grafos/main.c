#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "lista.h"

int main()
{
    Grafo *g = cria_grafo(27);
    //printf("%d", countlines("arestas.txt"));
    leArestas(g);
    //printf("%d\n", grauVertice(g,4));
    //printf("%d", ehAdjacente(g, 15, 1));
    imprimeVertices(g);
    imprimeListaAdj(g);
    return 0;
}
