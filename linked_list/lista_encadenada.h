#ifndef _LISTA_ENCADENADA_H
#define _LISTA_ENCADENADA_H

#define ASCENDENTE 0
#define DESCENDENTE 1

typedef struct _nodo {
    int indice;
    void *item;
    struct _nodo *siguiente;
}nodo;

typedef struct {
    int nodos;
    int size_elemento;
    nodo *head;
}lista;

typedef int (*lista_comparador)(const void *x, const void *y);

typedef void (*lista_impresor)(const void *x);

extern lista *lista_crear (int elem_size);

/** devuleve 1 si la lista esta vacia o no ha sido creada o se destruyo
   devuelve 0 si la lista no esta vacia
*/
extern int lista_esta_vacia (const lista *_lista);

/** Devuelve la cantidad de elementos de la lista */
extern int lista_cantidad_elementos (const lista *_list);

/** Ingresa item al comienzo de _lista */
extern int lista_insertar (lista *_lista, void *item);

/** Inserta item en la posicion dada por indice */
extern int lista_insertar_posicion (lista *_lista, void *item, int _indice);

/** Devuelve el primer elemento de _lista y lo guarda en destino */
extern int lista_primer_elemento (const lista *_lista, void *destino);

/** Devuelve el elemento en la posicion dada por _indice y lo guarda en destino */
extern int lista_obtener_elemento (const lista *_lista, void *destino, int _indice);

/** Elimina el elemento en la posicion dada por _indice y lo guarda en destino */
extern int lista_eliminar (lista *_lista, void *destino, int _indice);

/** Retornos para lista_comparador typedef int (*lista_comparador)(const void *x, const void *y);

1 si x > y
0 si x == y
-1 si x < y

***********************************************************************************/

/** Devuelve el indice en donde se encontro por primera vez a item, devuelve -1 si item no esta en la lista */
extern int lista_buscar (lista *_lista, void *item, lista_comparador comparador);

/** Ordena _lista segun tipo_orden, 0: ascendente; 1: descendente */
extern int lista_ordenar (lista *_lista, int tipo_orden, lista_comparador comparador);

/** Imprime los elementos de _lista */
extern void lista_imprimir (lista *_lista, lista_impresor impresor);

/** Destruye _lista y libera  la memoria asociada a ella */
extern void lista_destruir (lista *_lista);

#endif // _LISTA_ENCADENADA_H

