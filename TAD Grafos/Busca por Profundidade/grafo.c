//função auxiliar: realiza o calculo
void buscaProgundidade_aux(Grafo *g, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;//marca o vert como visitado e tb a sua profundidade
    for(i=0 ; i<g->grau[ini] ; i++){//pecorre tds os vert adjacentes
        if(!visitado[g->arestas[ini][i]])//verifica se o vertice foi visitado
            buscaProfundidade_aux(g,g->arestas[ini][i],visitado,cont+1);//faz a recursão
    }
}

//função principal: faz a interface com o usuario
void buscaProfundidade(Grafo *g, int ini, int *visitado){
    int i, cont=1;
    for(i=0 ; i<g->nro_vert ; i++)
        visitado[i] = 0;//inicializa e marca tds os vert como n visitado
    buscaProfundidade_aux(g,ini,visitado,cont);
}
