#ifndef PILA_SECUENCIAL_H_
#define PILA_SECUENCIAL_H_

typedef struct {
    void *items;
    int tope;
	int maximo;
	int size_elemento;
} pila_secuencial;

/** Crea una pila y devuelve un puntero tipo pila_secuencial */
extern pila_secuencial *pila_secuencial_crear(int num_elementos, int elem_size);

/** Devuelve 1 si pila esta vacia, 0 si no esta vacia */
extern int pila_secuencial_esta_vacia (const pila_secuencial *pila);

/** Inserta x al tope de la pila */
extern int pila_secuencial_insertar (pila_secuencial *pila, void *x);

/** Quita el elemento del tope y lo guarda en destino */
extern int pila_secuencial_quitar (pila_secuencial *pila, void *destino);

/** Devuelve el elemento del tope sin quitarlo y lo guarda en destino */
extern int pila_secuencial_ultimo_elemento (pila_secuencial *pila, void *destino);

/** Destruye la pila y libera la memoria asociada */
extern void pila_secuencial_destruir(pila_secuencial *pila);

#endif // PILA_SECUENCIAL_H_
