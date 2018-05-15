#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "lista.h"

typedef struct fila Fila;
typedef struct no No;

Fila* cria_fila();
int enfileira(Fila *f, int valor);
int desenfileira(Fila *f);
int desaloca_fila(Fila *f);
int tamFila(Fila *f);
void imprimeFila(Fila *f);

#endif // FILA_H_INCLUDED
