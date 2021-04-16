#ifndef _ARBOL_BINARIO_H
#define _ARBOL_BINARIO_H

typedef struct _nodo {
    void *item;
    struct _nodo *izquierdo;
    struct _nodo *derecho;
}nodo;

typedef struct {
    int size_elemento;
    nodo *raiz;
}arbol_binario;

/************************************************************************************
Retornos para arbol_comparador
typedef int (*arbol_comparador)(const void *x, const void *y);

1 si x > y
0 si x == y
-1 si x < y

***********************************************************************************/
typedef int (*arbol_binario_comparador)(const void *x, const void *y);

typedef void (*arbol_binario_impresor)(const void *x);

/** Crea un arbol binario y devuelve un puntero tipo arbol_binario */
extern arbol_binario *arbol_binario_crear (int elem_size);

/** Devuelve 1 si el arbol esta vacio, 0 en caso contrario; devuelve -1 si no existe el arbol */
extern int arbol_binario_esta_vacio (const arbol_binario *arbol);

/** Inserta item en el arbol siempre que este no este repetido */
extern int arbol_binario_insertar (arbol_binario *arbol, void *item, arbol_binario_comparador comparador);

/** Muestra los elementos en preorden */
extern void arbol_binario_preorden (const arbol_binario *arbol, arbol_binario_impresor impresor);

/** Muestra los elementos en inorden */
extern void arbol_binario_inorden(const arbol_binario *arbol, arbol_binario_impresor impresor);

/** Muestra los elementos en postorden */
extern void arbol_binario_postorden(const arbol_binario *arbol, arbol_binario_impresor impresor);

/** Devuelve 1 si el elemento esta en el arbol, 0 si el elemento no esta en el arbol */
extern int arbol_binario_buscar (const arbol_binario *arbol, void *item, arbol_binario_comparador comparador);

/** Devuelve el minimo valor en el arbol, NULL si el arbol esta vacio */
extern void *arbol_binario_minimo (const arbol_binario *arbol);

/** Devuelve el maximo valor en el arbol, NULL si el arbol esta vacio */
extern void *arbol_binario_maximo (const arbol_binario *arbol);

/** Devuelve -1 si el arbol esta vacio o item no se encuentra en este, 1 si la operacion fue exitosa */
extern int arbol_binario_eliminar (arbol_binario *arbol, void *item, arbol_binario_comparador comparador);

/** Elimina el elemento minimo del arbol */
extern int arbol_binario_eliminar_minimo (arbol_binario *arbol);

/** Elimina el elemento maximo del arbol */
extern int arbol_binario_eliminar_maximo (arbol_binario *arbol);

/** Devuelve la altura del arbol */
extern int arbol_binario_altura (const arbol_binario *arbol);

/** Destruye arbol y libera la memoria asociada a el */

extern void arbol_binario_destruir (arbol_binario *arbol);

#endif // _ARBOL_BINARIO_H
