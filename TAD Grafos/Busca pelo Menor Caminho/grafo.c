/*os vetores dist diz qual a dist de cada vert pro
inicial e o ant me diz o anterior daquele vert*/

//função auxiliar
int procuraMenorDistancia(float *dist, int *visitado, int NV){
    int i, menor=-1, primeiro=1;
    for(i=0 ; i<NV ; i++){//visitar tds os vertices
        if(dis[i] >= 0 && visitado[i] == 0){//verifica a dist e se ele ja foi visitado
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dis[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;//retorna o com a menor dist
}

void menorCaminho(Grafo *g, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, u;
    cont = NV = gr->nro_vert;
    visitado = (int*) malloc((NV*sizeof(int));//vetor aux
    for(i=- ; i<NV ; i++){//inicializei os meu dados
        ant[i] = -1;//n tem ant
        dis[i] = -1;//n tem dist
        visitado[i] = 0;//nenhum foi visitado
    }
    dist[ini] = 0;//dist do ini pro ini é 0
    while(cont>0){//enquanto houver vert para ser visitado
        u = procuraMenorCaminho(dist, visitado, NV);
        if(u == -1)
            break;
        visitado[u] = 1;
    }
    free(visitado);
    for(i=0 ; i<g->grau[u] ; i++){
        ind = g->arestas[u][i];
        if(dis[ind] < 0){
            dis[ind] = dist[u]+1;
            ant[ind] = u;
        }else{
            if(dist[ind] > dist[u] + 1){
                dist[ind] = dist[u] + 1;
                ant[ind] = u;
            }
        }
    }
}
