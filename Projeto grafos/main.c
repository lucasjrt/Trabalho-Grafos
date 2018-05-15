#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "lista.h"
#include "fila.h"

int main()
{
    Grafo *g = cria_grafo(27);
    //int nlinhas = countlines("nos.txt");
    //printf("Linhas: %d\n", nlinhas);
    //int *linhas = ncharline("nos.txt");
    //for(int i = 0; i < nlinhas; i++) {
        //printf("Linha %d: %d caracteres.\n", i, linhas[i]);
    //}
    //printf("%d", countlines("arestas.txt"));
    leArestas(g);
    //printf("%d\n", grauVertice(g,4));
    //printf("%d", ehAdjacente(g, 15, 1));
    imprimeVertices(g);
    imprimeListaAdjDet(g);
    //imprimeListaAdj(g);



    return 0;
}

void menu() {

}
