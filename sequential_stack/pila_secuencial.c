#include "pila_secuencial.h"
#include <stdlib.h>
#include <string.h>

extern pila_secuencial *pila_secuencial_crear(int num_elementos, int elem_size) {
    pila_secuencial *pila= (pila_secuencial*)malloc(sizeof(pila_secuencial));

    if(pila == NULL)
        return NULL;

    pila->items=malloc(num_elementos*elem_size);

    if(pila->items == NULL)
        return NULL;

    pila->tope=-1;
    pila->maximo=num_elementos;
    pila->size_elemento=elem_size;

    return pila;
}

extern int pila_secuencial_esta_vacia (const pila_secuencial *pila) {
    if (pila->tope==-1)
        return 1;
    else
        return 0;
}

extern int pila_secuencial_insertar (pila_secuencial *pila, void *x) {
    if(pila->tope >= pila->maximo-1)
        return -1;

    pila->tope++;

    void* target = (char*)pila->items + (pila->tope*pila->size_elemento);
    memcpy(target,x,pila->size_elemento);

    return 0;
}

extern int pila_secuencial_quitar (pila_secuencial *pila, void *destino) {
    if(pila_secuencial_esta_vacia(pila))
        return -1;

    void* source = (char*)pila->items + (pila->tope*pila->size_elemento);
    pila->tope--;
    memcpy(destino, source, pila->size_elemento);

    return 0;
}

 extern int pila_secuencial_ultimo_elemento (pila_secuencial *pila, void *destino) {
    if(pila_secuencial_esta_vacia(pila))
        return -1;

    void* source = (char*)pila->items + (pila->tope*pila->size_elemento);
    memcpy(destino, source, pila->size_elemento);

    return 0;
}

extern void pila_secuencial_destruir (pila_secuencial *pila) {
    free(pila->items);
    free(pila);
}
