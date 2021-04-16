#include "tabla_hash.h"
#include "../lib/lista_encadenada.h"
#include <stdlib.h>
#include <string.h>

extern tabla_hash *tabla_hash_crear(int _size_tabla, int _size_elemento) {
    tabla_hash *tabla=(tabla_hash*)malloc(sizeof(tabla_hash));
    if(tabla==NULL)
        return NULL;

    tabla->buckets=(lista**)malloc(sizeof(lista)*_size_tabla);
    tabla->size_elemento=_size_elemento;
    tabla->size_tabla=_size_tabla;
    tabla->cuenta=0;
    int i=0;
    for(;i<_size_tabla;i++)
        tabla->buckets[i]=lista_crear(sizeof(nodo_hash));

    return tabla;
}

extern int tabla_hash_esta_vacia (tabla_hash *tabla) {return tabla->cuenta==0?1:0;}

extern int tabla_hash_insertar (tabla_hash *tabla, CLAVE _clave, void *x) {
    CLAVE indice=_clave % tabla->size_tabla;
    if(indice<0 || indice >= tabla->size_tabla)
        return -1;

    nodo_hash *nuevo=(nodo_hash*)malloc(sizeof(nodo_hash));
    nuevo->x=malloc(tabla->size_elemento);
    memcpy(nuevo->x,x,tabla->size_elemento);
    nuevo->clave=_clave;
    lista_insertar(tabla->buckets[indice],nuevo);
    tabla->cuenta++;

    return 1;
}

static int comparador (const void *x,const void *y){
    nodo_hash *px=(nodo_hash*)x;
    nodo_hash *py=(nodo_hash*)y;

    if(px->clave == py->clave)
        return 0;

    return 1;
}

extern int tabla_hash_eliminar (tabla_hash *tabla, CLAVE clave, void *destino) {
    CLAVE indice=clave % tabla->size_tabla;

    if(indice < 0 || indice >= tabla->size_tabla) {
        destino=NULL;
        return -1;
    }

    nodo_hash *target=(nodo_hash*)malloc(sizeof(nodo_hash));
    target->x=malloc(tabla->size_elemento);
    target->clave=clave;

    int i=lista_buscar(tabla->buckets[indice],target,&comparador);

    if(i==-1) {
        destino=NULL;
        return -1;
    }

    lista_obtener_elemento(tabla->buckets[indice],target,i);
    lista_eliminar(tabla->buckets[indice],NULL,i);
    memcpy(destino,target->x,tabla->size_elemento);
    tabla->cuenta--;
    return 1;
}

extern int tabla_hash_buscar(tabla_hash *tabla, CLAVE clave, void *destino) {
    CLAVE indice=clave % tabla->size_tabla;

    if(indice < 0 || indice >= tabla->size_tabla) {
        destino=NULL;
        return -1;
    }

    nodo_hash *target=(nodo_hash*)malloc(sizeof(nodo_hash));
    target->x=malloc(tabla->size_elemento);
    target->clave=clave;

    int i=lista_buscar(tabla->buckets[indice],target,&comparador);

    if(i==-1) {
        destino=NULL;
        return -1;
    }

    lista_obtener_elemento(tabla->buckets[indice],target,i);
    memcpy(destino,target->x,tabla->size_elemento);
    return 1;
}
