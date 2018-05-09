#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no No;
typedef struct lista Lista;

Lista* cria_lista();
int insereNaLista(Lista *l, Vertice vertice);
int removeDaLista(Lista *l, Vertice vertice);
int destroiLista(Lista *l);
int tamLista(Lista *l);
No *getCabeca(Lista *l);
//void imprimeLista(Lista *l);

#endif // LISTA_H_INCLUDED
