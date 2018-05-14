#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

void buscaProgundidade_aux(Grafo *g, int ini, int *visitado, int cont);
void buscaProfundidade(Grafo *g, int ini, int *visitado);

#endif // GRAFO_H_INCLUDED
