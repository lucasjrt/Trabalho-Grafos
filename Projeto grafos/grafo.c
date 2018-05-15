#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "lista.h"
#define MINFINITO INT_MIN

struct vertice {
    int id;
    char nome[30];
    float latitude, longitude;
};

struct grafo {
    int numVertices, numArestas;
    Vertice *vertice;
    Lista **arestas;
};

//Retorna um ponteiro pra uma grafo alocado
Grafo *cria_grafo(int tam) {
    int i;
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
                char **strings = (char**) malloc(tam* sizeof(char*));
                int *sizelines = ncharline("nos.txt");
                for(i = 0; i < tam; i++) {
                    strings[i] = (char*) malloc((sizelines[i] + 2) * sizeof(char));
                }
                FILE *f = fopen("nos.txt", "r");
                if(f == NULL) {
                    printf("Erro ao abrir o arquivo nos.txt.\n");
                } else {
                    for(i = 0; i < tam; i++) {
                        fgets(strings[i], sizelines[i] + 2, f);
                    }
                    fclose(f);
                    for(i = 0; i < tam; i++) {
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
                    for(i = 0; i < numVertices(g); i++)
                        g->arestas[i] = cria_lista();
            }
        }
        return g;
    }
    return NULL;
}

//Retorna o grau do v�rtice v
int grauVertice(Grafo *g, int v) {
    if (g == NULL) {
        printf("Grafo inconsistente.\n");
        return -1;
    } else if (v < 0 || v > numVertices(g)) {
        printf("Vertice invalido.\n");
        return -1;
    } else {
        return tamLista(g->arestas[v]);
    }
}

//Retorna o peso da aresta entre o v�rtice 1 e o v�rtice 2
int pesoAresta(Grafo *g, int v1, int v2) {
    return getPeso(g->arestas[v1], v2);
}


void busca_largura(Grafo *g, int v){
    int i;
    int tam = numVertices(g);
    int *visitados = (int*) malloc(tam * sizeof(int));
    for (i = 0; i < tam; i++)
        visitados[i] = 0;
    visitados[0] = 1;

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

//Imprime os v�rtices do grafo
void imprimeVertices(Grafo *g) {
    int i;
    for(i = 0; i < numVertices(g); i++)
        printf("id: %d\nnome: %s\nlatitude: %f\nlongitude: %f\n", g->vertice[i].id, g->vertice[i].nome, g->vertice[i].latitude, g->vertice[i].longitude);
}

void dijkstra(Grafo *g, int po, int pd) {
    int i, vert,k, NovaDist, min;
    int *m, *l, *a, *caminho;
    m = (int*)malloc(g->numVertices*sizeof(int));
    l = (int*)malloc(g->numVertices*sizeof(int));
    a = (int*)malloc(g->numVertices*sizeof(int));
    caminho = (int *)malloc(g->numVertices*3*sizeof(int));
    for (i=0; i < g->numVertices; i++)
    {
        m[i] = 0;
        a[i] = -1;
        l[i] = 2147483647;
    }
    vert = po;
    l[vert] = 0;
    No *no;
    no = getCabeca(g->arestas[po]);
    while (vert != pd && vert != -1) {
        for(i=0;i<g->numVertices; i++){
            if (no != NULL && m[i]==0) {
                NovaDist = l[vert] + peso(no);

                if (NovaDist < l[i]) {
                    l[i] = NovaDist;
                    a[i] = vert;
                }
            }
            if (getProx(no)!= NULL) no = getProx(no);
        }
        m[vert] = 1;
        min = 300000;
        vert = -1;
        for (i=0; i<g->numVertices; i++)
            if (m[i]==0 && l[i] < min) {
                min = l[i];
                vert = i;
            }
    }
    if (vert == pd) {
        printf("Caminho mais curto entre %d e %d tem comprimento %d: ",po, pd, l[pd]);
        caminho[0] = pd;
        k = 1;
        while (vert != po) {
            caminho[k]= a[vert];
            vert = a[vert];
            k++;
        }
    }
    else
        printf("nao exite caminho entre %d e %d", po, pd);
}

//Retorna o n�mero de v�rtices do grafo
int numVertices(Grafo *g) {
    //retorna -1 se for um grafo inv�lido
    if(g == NULL) {
        printf("Grafo invalido.\n");
        return -1;
    }
    return g->numVertices;
}

//Insere uma aresta entre o v�rtice v1 e o v�rtice v2 com um determinado peso
int insereAresta(Grafo *g, int v1, int v2, int peso) {
    if (g == NULL) {
        printf("Grafo invalido.\n");
        return -1;
    } else if(v1 < 0) {
        printf("O v1 (%d) deve ser maior do que 0.\n", v1);
        return -1;
    } else if(v1 > numVertices(g)) {
        printf("O v1 (%d) deve ser menor do que %d.\n", v1, numVertices(g));
        return -1;
    } else if(v2 < 0) {
        printf("O v2 (%d) deve ser maior do que 0.\n", v2);
        return -1;
    } else if (v2 > numVertices(g)){
        printf("O v2 (%d) deve ser menor do que %d.\n", v2, numVertices(g));
        return -1;
    } else {
        insereNaLista(g->arestas[v1], g->vertice[v2], peso);
        g->numArestas++;
    }
    return 1;
}

//L� as arestas do arquivo aresta.txt
int leArestas(Grafo *g) {
    int i;
    int nlinhas = countlines("arestas.txt");
    char **strings = (char**) malloc(nlinhas * sizeof(char*));
    int *tamlinhas = ncharline("arestas.txt");
    for(i = 0; i < nlinhas; i++) {
        strings[i] = (char*) malloc((tamlinhas[i] + 2) * sizeof(char));
    }
    FILE *f = fopen("arestas.txt", "r");
    if(f == NULL)
        printf("Erro ao abrir o arquivo arestas.txt.\n");
    else {
        for(i = 0; i < nlinhas; i++) {
            fgets(strings[i], tamlinhas[i]+2, f);
        }
        fclose(f);
        for(i = 0; i < nlinhas; i++) {
            int v1 = atoi(strtok(strings[i], ";"));
            int v2 = atoi(strtok(NULL, ";"));
            int peso = atoi(strtok(NULL, ";"));
            insereAresta(g, v1, v2, peso);
        }
    }
    return 1;
}

//Imprime a lista de adjac�ncia do grafo g
void imprimeListaAdj(Grafo *g) {
    int i;
    for(i = 0; i < numVertices(g); i++) {
        printf("Vertice %d: ", i);
        imprimeLista(g->arestas[i]);
        printf("\n");
    }
}

//Imprime a lista de adjac�ncia do grafo g com detalhes
void imprimeListaAdjDet(Grafo *g) {
    int i, j;
    printf("(Para visualizar o grafo com detalhes na lista de adjacencia, e' recomendado visualizar o grafo com o console em tela cheia)\n");
    int tam = numVertices(g);
    printf(" __ \n|  |");
    for (j = 0; j < grauVertice(g, 0); j++)
        printf("      ____________");
    printf("\n");
    for(i = 0; i < tam; i++) {
        printf("|%2d| ->  ", i);
        imprimeLista(g->arestas[i]);
        printf("|__| ");
        for(j = 0; j < grauVertice(g, i); j++)
            printf("    |___|_____|__|");
        printf("\n");
        if(i < tam - 1)
            printf("|  |");
        if(i + 1 < tam) {
        for(j = 0; j < grauVertice(g, i+1); j++)
            printf("      ____________");
        }
        printf("\n");
    }
    printf("(Para visualizar o grafo com detalhes na lista de adjacencia, e' recomendado visualizar o grafo com o console em tela cheia)\n");
}

//Retorna o n�mero de linhas do arquivo file
int countlines(char *file) {
    int lines = 0;
    FILE *f = fopen(file, "r");
    if(f == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", file);
        return -1;
    }
    else {
        char ch;
        do {
            ch = fgetc(f);
            if(ch == '\n') {
                lines++;
            }
        } while(!feof(f));
        fclose(f);
    }
    return lines + 1;
}

//Retorna um vetor de inteiros com cada posi��o sendo o n�mero de caracteres na linha i
int* ncharline(char *file) {
    int i;
    int nlines = countlines(file);
    int *line = (int*) malloc(nlines * sizeof(int));
    for(i = 0; i < nlines; i++) {
        line[i] = 0;
    }
    FILE *f = fopen(file, "r");
    if(f == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", file);
        return NULL;
    } else {
         for (i = 0; i < nlines; i++) {
            char ch = fgetc(f);
            while(!feof(f)) {
                ch = fgetc(f);
                line[i]++;
                if (ch == '\n')
                    break;
            }
        }
    }
    return line;
}

void possiveis_caminhos(Grafo *g, int v, float bytes, int seg){
    float temp;
    int i,peso,cont=0,vet[27];
    for(i=0 ; i<numVertices(g) ; i++){
        if(i != v){
            if(ehAdjacente(g,v,i)){
                peso = pesoAresta(g,v,i);
                temp = (bytes/peso);
                if(temp <= seg){
                    vet[cont] = i;
                    cont++;
                }
            }
        }
    }
    if(cont == 0)
        printf("Nenhum ponto eh possivel.");
    else{
        printf("Os pontos possiveis sao: ");
        for(i=0 ; i<cont ; i++){
            printf("%d",vet[i]);
            if(i != (cont-1))
                printf(", ");
        }
    }
    printf("\n");
}

void corbertura_envio(Grafo *g, int v){

}

int posMenor(int *vetor, int tam) {
    int i, pos = vetor[0], menor = 0;
    for(i = 0; i < tam; i++) {
        if (vetor[i] < menor) {
            pos = i;
            menor = vetor[i];
        }
    }
    return pos;
}
