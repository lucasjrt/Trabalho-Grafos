#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "lista.h"
#include "fila.h"

int main()
{
    Grafo *g = cria_grafo(27);
    leArestas(g);
    menu(g);
    return 0;
}

void menu(Grafo *g) {
    float bytes;
    int i = 1,opcao,v1,v2,qualquer,seg;
    while(i){
        printf("---------------------------------------------MENU----------------------------------------------\n");
        printf("Escolha uma das opcoes: \n");
        printf("1 - Imprime a lista de adjacencia.\n");
        printf("2 - Imprime cada um dos PoP e seu numero correspondente.\n");
        printf("3 - Numero de PoP do grafo.\n");
        printf("4 - O grau de um determinado PoP.\n");
        printf("5 - Ver se dois PoP sao adjacentes.\n");
        printf("6 - Caminho mais rapido para trafegar um determinada quantidade de carga apartir dum PoP.\n");
        printf("7 - Possiveis caminhos para um determinado PoP com um determinada quantidade de carga por n segundos.\n");
        printf("8 - Corbetura de envio de um PoP.\n");
        printf("9 - Sair \n\n");
        printf("Qual a sua escolha: ");
        scanf("%d",&opcao);
        printf("\n");
        switch(opcao){
            case 1:
                imprimeListaAdj(g);
                printf("\n");
                break;
            case 2:
                imprimeVertices(g);
                printf("\n");
                break;
            case 3:
                qualquer = numVertices(g);
                printf("O tamanho do grafo eh: %d\n\n",qualquer);
                break;
            case 4:
                printf("Qual vertice voce deseja pesquisar: ");
                scanf("%d",&v1);
                qualquer = grauVertice(g,v1);
                printf("\nO grau do vertice %d eh: %d\n\n",v1,qualquer);
                break;
            case 5:
                printf("Escolha o primeiro vertice: ");
                scanf("%d",&v1);
                printf("\nEscolha o segundo vertice: ");
                scanf("%d",&v2);
                qualquer = ehAdjacente(g,v1,v2);
                if (qualquer)
                    printf("Eles sao adjacentes!!!!!\n\n");
                else
                    printf("Eles nao sao adjacentes.\n\n");
                break;
            case 6:
                printf("Escolha o vertice de origem: ");
                scanf("%d",&v1);
                printf("\nEscolha o vertice de destino: ");
                scanf("%d",&v2);
                dijkstra(g,v1,v2);
                printf("\n");
                break;
            case 7:
                printf("Qual o vertice de origem: \n");
                scanf("%d",&v1);
                printf("Qual a carga: \n");
                scanf("%f",&bytes);
                printf("Qual o tempo para o envio: \n");
                scanf("%d",&seg);
                possiveis_caminhos(g,v1,bytes,seg);
                printf("\n");
                break;
            case 8:
                break;
            case 9:
                printf("Fim do programa.\n");
                i = 0;
                break;
        }
    }
}
