#ifndef _TABLA_HASH_H_
#define _TABLA_HASH_H_

#include "../lib/lista_encadenada.h"

typedef unsigned int CLAVE;

typedef struct {
    void *x;
    CLAVE clave;
}nodo_hash;

typedef struct {
    lista **buckets;
    int size_tabla;
    int size_elemento;
    int cuenta;
} tabla_hash;

/***********************************************************************************
valor X para la funcion K=h(X)
***********************************************************************************/
typedef CLAVE (*funcion_hash)(const void *x);
/**********************************************************************************/

/** Crea una nueva tabla hash */
extern tabla_hash *tabla_hash_crear(int _size_tabla, int _size_elemento);

/** Inserta un elemento a la tabla cuya clave debe ser especificada por el programador */
extern int tabla_hash_insertar (tabla_hash *tabla, CLAVE clave, void *x);

/** Devuelve 1 si tabla esta vacia, 0 en caso contrario */
extern int tabla_hash_esta_vacia (tabla_hash *tabla);

/** Elimina el elemento cuya clave se pasa como argumento y lo guarda en destino */
extern int tabla_hash_eliminar (tabla_hash *tabla, CLAVE clave, void *destino);

/** Busca el elemento cuya clave se pasa como argumento y lo guarda en destino
NULL si el elemento no esta en la tabla */
extern int tabla_hash_buscar(tabla_hash *tabla, CLAVE clave, void *destino);

#endif // _TABLA_HASH_H_
