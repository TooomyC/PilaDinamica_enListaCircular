#ifndef PILADINDOBLE_H_INCLUDED
#define PILADINDOBLE_H_INCLUDED


///Pila DINAMICA en LISTA CIRCULAR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ((X) <= (Y) ? (X) : (Y))
#define FALSO 0
#define VERDADERO 1

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;

} tNodo;

typedef tNodo* tPila;

void crearPila(tPila *p);
int pilaLlena(const tPila *p, unsigned cantBytes);
int ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int verTope(const tPila *p, void *d, unsigned cantBytes);
int pilaVacia(const tPila *p);
int sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);


#endif // PILADINDOBLE_H_INCLUDED
