#ifndef _COLA_SECUENCIAL_H
#define _COLA_SECUENCIAL_H

typedef struct {
    void *items;
    int primero;
    int ultimo;
    int cantidad;
    int maximo;
    int size_elemento;
} cola_secuencial;

/** Crea una cola y devuelve un punter a tipo cola_secuencial
num_elementos: cantidad de elementos a almacenar
size_elementos: tamaño de los items a almacenar */
extern cola_secuencial *cola_secuencial_crear(int num_elementos, int size_elementos);

/** Devuelve 1 si la cola esta vacia, 0 si la cola no esta vacia */
extern int cola_secuencial_esta_vacia (const cola_secuencial *cola);

/** Inserta x al final de la cola */
extern int cola_secuencial_insertar (cola_secuencial *cola, void *x);

/** Devuelve el primer elemento de la cola y lo guarda en destino*/
extern int cola_secuencial_quitar (cola_secuencial *cola, void *destino);

/** Devuelve el primer elemento de la cola pero sin quitarlo y lo guarda en destino */
extern int cola_secuencial_primer_elemento(cola_secuencial *cola, void *destino);

/** Destruye cola eliminando todos sus elementos */
extern void cola_secuencial_destruir (cola_secuencial *cola);

#endif // _COLA_SECUNCIAL_H
