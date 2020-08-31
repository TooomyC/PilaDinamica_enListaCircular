#include "pilaDinDoble.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(cantBytes));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int ponerEnPila(tPila *p, const void *d, unsigned cantBytes)
{
    tNodo *nue;
    unsigned nueMio;
    unsigned nueMioSig;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return FALSO;
    }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nueMio = (nue); ///WARNING: PIDE CAST
    //nueMioSig = nue->sig;

    if(*p == NULL)
    {
        nue->sig = nue;
        nueMioSig = nue->sig; ///WARNING: PIDE CAST
        *p = nue;
    }
    else
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
        nueMioSig = nue->sig; ///WARNING: PIDE CAST
    }

    printf("t: %p, p-sig: %p /nnue: %x nue-sig:%x \n", *p, (*p)->sig, nueMio, nueMioSig);
    return VERDADERO;
}

int verTope(const tPila *p, void *d, unsigned cantBytes)
{
        if(*p == NULL)
            return FALSO;

        memcpy(d, (*p)->sig->info, MINIMO(cantBytes, (*p)->sig->tamInfo));
        return VERDADERO;
}

int pilaVacia(const tPila *p)
{
    return *p == NULL;
}

int sacarDePila(tPila *p, void *d, unsigned cantBytes)
{
    tNodo *aux;

    if(*p == NULL)
        return FALSO;

    aux = (*p)->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));

    if(aux == *p)
        *p = NULL;
    else
        (*p)->sig = aux->sig;

    printf(" tope %p, p->sig: %p \n", *p, (*p)->sig);

    free(aux->info);
    free(aux);

    return VERDADERO;
}

void vaciarPila(tPila *p)
{
    while(*p)
    {
        tNodo *aux = (*p)->sig;

        if(*p == aux)
            *p = NULL;
        else
            (*p)->sig = aux->sig;

        free(aux->info);
        free(aux);
    }
}
