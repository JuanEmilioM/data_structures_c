#ifndef _COLA_ENCADENADA_H_
#define _COLA_ENCADENADA_H_

typedef struct _nodo {
    void *item;
    struct _nodo *siguiente;
}nodo;

typedef struct {
    int size_elemento;
    nodo *primero;
    nodo *ultimo;
}cola_encadenada;

/** Crea una cola y devuelve un puntero tipo cola_encadenada */
extern cola_encadenada *cola_encadenada_crear(int elem_size);

/** Devuelve 1 si cola esta vacia, 0 si no esta vacia */
extern int cola_encadenada_esta_vacia (const cola_encadenada *cola);

/** Inserta x al final de la cola */
extern int cola_encadenada_insertar (cola_encadenada *cola, void *x);

/** Quita el primer elemento de la cola y lo guarda en destino */
extern int cola_encadenada_quitar (cola_encadenada *cola, void *destino);

/** Devuelve el primer elemento sin quitarlo y lo guarda en destino */
extern int cola_encadenada_primer_elemento (cola_encadenada *cola, void *destino);

/** Destruye la cola y libera la memoria asociada */
extern void cola_encadenada_destruir(cola_encadenada *cola);

#endif // _COLA_ENCADENADA_H_
