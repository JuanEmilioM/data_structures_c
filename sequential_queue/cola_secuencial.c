#include "cola_secuencial.h"
#include <stdlib.h>
#include <string.h>

extern cola_secuencial *cola_secuencial_crear(int num_elementos, int size_elementos) {
    cola_secuencial *cola= (cola_secuencial*)malloc(sizeof(cola_secuencial));

    if(cola == NULL)
        return NULL;

    cola->items=malloc(num_elementos*size_elementos);

    if(cola->items == NULL)
        return NULL;

    cola->primero=0;
    cola->ultimo=0;
	cola->cantidad=0;
	cola->maximo=num_elementos;
    cola->size_elemento=size_elementos;

    return cola;
}

extern int cola_secuencial_insertar (cola_secuencial *cola, void *x) {
    if(cola->cantidad >= cola->maximo)
        return -1;

    void* target = (char*)cola->items + (cola->ultimo*cola->size_elemento);
    memcpy(target,x,cola->size_elemento);

    cola->ultimo = (cola->ultimo + 1) % cola->maximo;
    cola->cantidad++;

    return 0;
}

extern int cola_secuencial_esta_vacia (const cola_secuencial *cola) {
    if(cola->cantidad==0)
        return 1;
   else
        return 0;
}

extern int cola_secuencial_quitar (cola_secuencial *cola, void *destino) {
    if(cola_secuencial_esta_vacia(cola))
        return -1;

    void *source = (char*) cola->items + (cola->primero*cola->size_elemento);
    cola->primero = (cola->primero + 1) % cola->maximo;
    cola->cantidad--;

    memcpy(destino,source,cola->size_elemento);

    return 0;
}

 extern int cola_secuencial_primer_elemento (cola_secuencial *cola, void *destino) {
    if(cola_secuencial_esta_vacia(cola))
        return -1;

    void* source = (char*)cola->items + (cola->primero*cola->size_elemento);
    memcpy(destino, source, cola->size_elemento);

    return 0;
}

extern void cola_secuencial_destruir (cola_secuencial *cola) {
    free(cola->items);
    free(cola);
}
