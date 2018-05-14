void buscaLargura(Grafo *g, int ini, int *visitado){
    int i, vert, NV, cont=1, *fila, IF=0, FF=0;//IF/FF = INICIO/FINAL DA FILA
    for(i=0 ; i<g->nro_vert ; i++)//marca tds os vert como n visitado
        visitado[i] = 0;
    NV = g->nro_vert;//NV = NUMERO DE VERTICES
    fila = (int*) malloc(NV*sizeof(int));//guarda a ordem q visitei os vertices
    FF++;
    fila[FF] = ini;//o final da fila é o vert inicial
    visitado[ini] = cont;//marca a ordem q visita o inicial
    while(IF != FF){//enquanto n estiver vazia
        IF = (IF + 1) % NV;/*pega o primei-*/
        vert = fila[IF];   /*ro da fila*/
        cont++;//define a ordem q foram visitados
        for(i=0 ; i<g->grau[vert] ; i++){//visita tds os vizinhos
            if(!visitado[g->aresta[vert][i]]){//verifica se foi visitado
                FF = (FF + 1) % NV;            /*põe o vert n visita-*/
                fila[FF] = g->arestas[vert][i];/*do no final da fila*/
                visitado[g->arestas[vert][i] = cont;//coloca ele cm visitado
            }
        }
    }
    free(fila);//libera a fila
}
