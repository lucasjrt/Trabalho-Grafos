#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "grafo.h"

typedef struct no No;
typedef struct lista Lista;

Lista* cria_lista();
No* cria_no();
No* getCabeca(Lista *l);
No* elemPos(Lista *l, int pos);
int tamLista(Lista *l);
int insereNaLista(Lista *l, Vertice vertice, int peso);
int removeDaLista(Lista *l, Vertice vertice);
int destroiLista(Lista *l);
int contem(Lista *l, Vertice vertice);
int getPeso(Lista *l, int v);
int listaSize();
int noSize();
int peso(No *no);
No* getProx(No *no);
void setProx(No *n1, No *n2);
void imprimeLista(Lista *l);

#endif // LISTA_H_INCLUDED
