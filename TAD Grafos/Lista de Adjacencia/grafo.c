struct no{
    int vert;
    int peso;
    struct no *prox;
};
typedef struct no No;

struct grafo{
    int qtd_vert, qtd_aresta;
    int *grau;
    No **aresta;
};

Grafo cria_grafo(int nro_vert){
    if(nro_vert <= 0)
        return NULL;

}
