#include <stdio.h>
#include <stdlib.h>
#include "MatrizAdjacencia.h"

struct grafo{
    int qtd_vert, qtd_aresta;//qtd de vertices e arestas
    int *grau;//vetor com o grau dos vertices
    int **aresta;//matriz de adjacencia
};

Grafo *cria_grafo (int nro_vert){
    int i,k;
    if (nro_vert <= 0)//verifica se qtd é adequada
        return NULL;

    Grafo* G = (Grafo*) malloc(sizeof(Grafo));//aloca e verifica o grafo
    if (G == NULL)
        return NULL;

    G->qtd_vert = nro_vert;//preenche as qtd
    G->qtd_aresta = 0;

    G->grau = (int*) calloc(nro_vert, sizeof(int));//alooca e verifica o vetor grau
    if(G->grau == NULL){
        free(G);
        return NULL;
    }

    G->aresta = (int**) malloc(nro_vert *sizeof(int*));//aloca e verifica as linhas matriz aresta
    if(G->aresta == NULL){
        free(G->grau);
        free(G);
        return NULL;
    }

    for(i=0; i<nro_vert; i++){//aloca e verifica as colunas matriz aresta
        G->aresta[i] = (int*) calloc(nro_vert, sizeof(int));
        if(G->aresta[i] == NULL){
            for(k=0; k<i; k++){
                free(G->aresta);
                free(G->grau);
                return NULL;
            }
        }
    }
    return G;
}

int insere_aresta (Grafo* G, int V1, int V2, int P){
    if(G == NULL || V1 <= 0 || V2 <= 0)//verifica existencia do grafo, e validez dos vertices
        return -1

    if(G->aresta[V1][V2] != 0){//verrifica se n existe uma aresta
        return 0;
    }

    G->aresta[V1][V2] = P;//passa o peso pra matriz
    G->qtd_aresta++;//aumenta a qtd de arestas
    G->grau[V1] += 1;//aumenta o grau do determinado vertice
    G->gruas[V2] += 1//aumenta o grau do determinado vertice

    return 1;
}

int verifica_aresta(Grafo* G, int V1, int V2){
    if(G == NULL || V1 <= 0 || V2 <= 0)//verifica existencia do grafo, e validez dos vertices
        return -1

    if(G->aresta[V1][V2] == 0){//verrifica se existe uma aresta
        return 0;
    }else{
        return 1;
    }
}

int remove_aresta(Grafo* G, int V1, int V2){
    if(G == NULL || V1 <= 0 || V2 <= 0)//verifica existencia do grafo, e validez dos vertices
        return -1

    if(G->aresta[V1][V2] == 0){//verrifica se existe uma aresta
        return 0;
    }

    G->aresta[V1][V2] = 0;
    G->qtd_aresta--;
    G->grau[V1]--;
    G->grau[V2]--;

    return 1;
}

int consulta_aresta(Grafo* G, int V1, int V2, int *P){
    if(G == NULL || V1 <= 0 || V2 <= 0)//verifica existencia do grafo, e validez dos vertices
        return -1

    if(G->aresta[V1][V2] == 0)//verrifica se existe uma aresta
        return 0;

    P = G->aresta[V1][V2];//atribui o peso à variavel
    return 1;
}

void libera_grafo(Grafo** G){
    if(G == NULL)//verifica a existencia do grafo
        return NULL;

    for(i=0; i<qtd_vert; i++){//libera a memoria das colunas da matriz aresta
        free(G->aresta[i]);
    }

    free(G->aresta);//libera a memoria da matriz aresta
    free(G->grau);//libera a memoria do vetor grau
    free(G);//libera a memoria do grafo
    G* = NULL;//atribui NULL para o endereço do grafo
}

void mostra_adjacentes(Grafo* G, int V){
    int cont=0;
    if(G == NULL || V <= 0){//verifica a existencia do grafo e a invelidez do vertice
        printf("Grafo inexistente ou vértice inválido");
    }else{
        for(i=0; ; i++){//olha os vertices adjacentes
            if(G->aresta[V][i] != 0){
                printf("%d -> %d = %d",V,i,aresta[V][i])
                cont++;
            }
            if(cont == 0)
                printf("O vertice %d nao poossui adjacentes",V);
        }
    }
}

void mostra_grafo(Grafo* G){
    if(G == NULL)//verifica a existencia do grafo
        printf("Grafo inexistente");
    else{
        if(qtd_aresta == 0)//verifica se existe arestas
            printf("Grafo vazio");
        else{
            for(i=0; i<qtd_vert; i++){//printa o grafo
                printf("Vertice %d : ",i);
                mostra_adjacentes(G,i);
            }
        }
    }
}

