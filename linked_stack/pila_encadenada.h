#ifndef _PILA_ENCADENADA_H_
#define _PILA_ENCADENADA_H_

typedef struct _nodo {
    void *item;
    struct _nodo *siguiente;
}nodo;

typedef struct {
    int size_elemento;
    nodo *tope;
}pila_encadenada;

/** Crea una pila y devuelve un puntero tipo pila_encadenada **/
extern pila_encadenada *pila_encadenada_crear(int elem_size);

/** Devuelve 1 si pila esta vacia, 0 si no esta vacia **/
extern int pila_encadenada_esta_vacia (const pila_encadenada *pila);

/** Inserta x al tope de la pila **/
extern int pila_encadenada_insertar (pila_encadenada *pila, void *x);

/** Quita el elemento del tope y lo guarda en destino **/
extern int pila_encadenada_quitar (pila_encadenada *pila, void *destino);

/** Devuelve el elemento del tope sin quitarlo y lo guarda en destino **/
extern int pila_encadenada_ultimo_elemento (pila_encadenada *pila, void *destino);

/** Destruye la pila y libera la memoria asociada **/
extern void pila_encadenada_destruir(pila_encadenada *pila);

#endif // _PILA_ENCADENADA_H_
