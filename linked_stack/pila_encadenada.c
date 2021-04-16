#include <stdlib.h>
#include <string.h>
#include "pila_encadenada.h"

extern pila_encadenada *pila_encadenada_crear(int elem_size) {
    pila_encadenada *pila=(pila_encadenada*)malloc(sizeof(pila_encadenada));

    if(pila == NULL)
        return NULL;

    pila->size_elemento=elem_size;
    pila->tope=NULL;
    return pila;

}

extern int pila_encadenada_esta_vacia(const pila_encadenada *pila) {
    if(pila==NULL)
        return 1;

    if(pila->tope == NULL)
        return 1;

    return 0;
}

extern int pila_encadenada_insertar(pila_encadenada *pila, void *x){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    //void *value=malloc(pila->size_elemento);
    nuevo->item=malloc(pila->size_elemento);
    //memcpy(value,x,pila->size_elemento);
    //nuevo->item=value;
    memcpy(nuevo->item,x,pila->size_elemento);
    nuevo->siguiente=pila->tope;
    pila->tope=nuevo;
    return 0;
}

extern int pila_encadenada_quitar(pila_encadenada *pila,void *destino) {
    if(pila_encadenada_esta_vacia(pila) == 1) { /* Pila vacia */
        destino=NULL;
        return -1;
    }

    nodo *target=pila->tope;
    memcpy(destino,pila->tope->item,pila->size_elemento);
    pila->tope=target->siguiente;
    free(target);
    target=NULL;

    return 1;
}

extern int pila_encadenada_ultimo_elemento(pila_encadenada *pila, void *destino) {
    if(pila_encadenada_esta_vacia(pila) == 1) {
        destino=NULL;
        return -1;
    }

    memcpy(destino,pila->tope->item,pila->size_elemento);
    return 1;
}

static void nodo_destruir(nodo *cursor) {
    if(cursor == NULL)
        return;

    nodo_destruir(cursor->siguiente);
    free(cursor);
}

extern void pila_encadenada_destruir(pila_encadenada *pila) {
    nodo_destruir(pila->tope);
    free(pila);
    pila=NULL;
}


