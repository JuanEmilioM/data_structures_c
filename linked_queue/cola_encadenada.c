#include "cola_encadenada.h"
#include <stdlib.h>
#include <string.h>

extern cola_encadenada *cola_encadenada_crear(int elem_size) {
    cola_encadenada *cola=(cola_encadenada*)malloc(sizeof(cola_encadenada));
    if(cola==NULL)
        return NULL;

    cola->size_elemento=elem_size;
    cola->primero=cola->ultimo=NULL;
    return cola;
}

extern int cola_encadenada_esta_vacia (const cola_encadenada *cola) {
    if(cola==NULL)
        return 1;

    if(cola->primero==NULL && cola->ultimo==NULL)
        return 1;
    else
        return 0;

}

extern int cola_encadenada_insertar (cola_encadenada *cola, void *x) {
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->item=malloc(cola->size_elemento);
    memcpy(nuevo->item,x,cola->size_elemento);
    nuevo->siguiente=NULL;

    if(cola_encadenada_esta_vacia(cola) == 1) {
        cola->primero=cola->ultimo=nuevo;
        return 1;
    }

    cola->ultimo->siguiente=nuevo;
    cola->ultimo=nuevo;

    return 1;
}

extern int cola_encadenada_quitar (cola_encadenada *cola, void *destino) {
    if(cola_encadenada_esta_vacia(cola) == 1) {
        destino=NULL;
        return -1;
    }

    nodo *target=cola->primero;
    memcpy(destino,cola->primero->item,cola->size_elemento);

    if(cola->primero== cola->ultimo) {
        free(cola->primero);
        cola->primero=cola->ultimo=NULL;
        return 1;
    }

    cola->primero=cola->primero->siguiente;
    free(target);
    target=NULL;
    return 1;
}

extern int cola_encadenada_primer_elemento (cola_encadenada *cola, void *destino) {
    if(cola_encadenada_esta_vacia(cola) == 1) {
        destino=NULL;
        return -1;
    }

    memcpy(destino,cola->primero->item,cola->size_elemento);
    return 1;
}

static void nodo_destruir(nodo *cursor) {
    if(cursor == NULL)
        return;
    nodo_destruir(cursor->siguiente);
    free(cursor);
}

extern void cola_encadenada_destruir(cola_encadenada *cola) {
    nodo_destruir(cola->primero);
    free(cola);
    cola=NULL;
}

