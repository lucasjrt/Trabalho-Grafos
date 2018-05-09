#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no No;
typedef struct lista Lista;

Lista* cria_lista();
No *getCabeca(Lista *l);
int tamLista(Lista *l);
int insereNaLista(Lista *l, Vertice vertice, int peso);
int removeDaLista(Lista *l, Vertice vertice);
int destroiLista(Lista *l);
int contem(Lista *l, Vertice vertice);
int listaSize();
void imprimeLista(Lista *l);

//void imprimeLista(Lista *l);

#endif // LISTA_H_INCLUDED
