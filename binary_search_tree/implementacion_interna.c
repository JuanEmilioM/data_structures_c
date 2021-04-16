#include "arbol_binario.h"
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a) > (b) ? (a) : (b))

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Funciones de manipulación de nodos
    No visibles desde afuera del módulo
++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

nodo *insertar (nodo *_nodo, void *item, arbol_binario_comparador comparador, int size_elemento) {
    if(_nodo == NULL) {
       /*
        _nodo=(nodo *)malloc(sizeof(nodo)); Acá esta presente toda la magia del procedimiento
        _nodo->izquierdo=_nodo->derecho=NULL;
        _nodo->item=malloc(sizeof(size_elemento));
        memcpy(_nodo->item,item,size_elemento);
        */
        nodo *target=(nodo*)malloc(sizeof(nodo));
        target->item=malloc(size_elemento);
        memcpy(target->item,item,size_elemento);
        target->izquierdo=NULL;
        target->derecho=NULL;
        return target;

    }

    if(comparador(item,_nodo->item) > 0)
        _nodo->derecho=insertar(_nodo->derecho,item,comparador,size_elemento);
    else
        if(comparador(item,_nodo->item) < 0)
            _nodo->izquierdo=insertar(_nodo->izquierdo,item,comparador,size_elemento);
            else
                return NULL; /** Elemento duplicado **/
    return _nodo;
}

void preorden (const nodo *_nodo, arbol_binario_impresor impresor) {
    if(_nodo != NULL) {
        impresor(_nodo->item);
        preorden(_nodo->izquierdo,impresor);
        preorden(_nodo->derecho,impresor);
    }
}

void inorden (const nodo *_nodo, arbol_binario_impresor impresor) {
    if(_nodo != NULL) {
        inorden(_nodo->izquierdo,impresor);
        impresor(_nodo->item);
        inorden(_nodo->derecho,impresor);
    }
}

void postorden (const nodo *_nodo, arbol_binario_impresor impresor) {
    if(_nodo != NULL) {
        postorden(_nodo->izquierdo,impresor);
        postorden(_nodo->derecho,impresor);
        impresor(_nodo->item);
    }
}


int buscar (nodo *_nodo, void *item, arbol_binario_comparador comparador) {
    if(_nodo == NULL)
        return 0;

    if(comparador(item,_nodo->item) > 0) /** item > elemento del nodo **/
        return buscar(_nodo->derecho,item,comparador);

    if(comparador(item,_nodo->item) < 0) /** item < elemento del nodo **/
        return buscar(_nodo->izquierdo,item,comparador);

    if(comparador(item,_nodo->item) == 0) /** Elemento encontrado **/
        return 1;
}

int altura (nodo *_nodo) {
    if(_nodo != NULL)
        return 1 + max(altura(_nodo->izquierdo),altura(_nodo->derecho));
    else
        return 0;
}

void *buscar_minimo (nodo *_nodo) {
    if(_nodo->izquierdo != NULL)
        return buscar_minimo(_nodo->izquierdo);
    else
        return _nodo->item;
}

void *buscar_maximo (nodo *_nodo) {
    if(_nodo->derecho != NULL)
        return buscar_maximo(_nodo->derecho);
    else
        return _nodo->item;
}

nodo *eliminar_minimo(nodo *_nodo) {
    if(_nodo == NULL)
        return NULL;

    if(_nodo->izquierdo != NULL)
        _nodo->izquierdo=eliminar_minimo(_nodo->izquierdo);
    else
        _nodo=_nodo->derecho;

    return _nodo;
}

nodo *eliminar_maximo(nodo *_nodo) {
    if(_nodo == NULL)
        return NULL;

    if(_nodo->derecho != NULL)
        _nodo->derecho=eliminar_maximo(_nodo->derecho);
    else
        _nodo=_nodo->derecho;

    return _nodo;
}

nodo *eliminar (nodo *_nodo, void *item, arbol_binario_comparador comparador) {
    if(_nodo == NULL)
        return NULL; /* el elemento no se encuentra en el arbol **/

    if(comparador(item,_nodo->item) > 0) /* item > nodo.item */
        _nodo->derecho=eliminar(_nodo->derecho,item,comparador);
    else
        if(comparador(item,_nodo->item) < 0) /* item < nodo.item */
            _nodo->izquierdo=eliminar(_nodo->izquierdo,item,comparador);
        else
            if((_nodo->izquierdo != NULL) && (_nodo->derecho != NULL)) /* El nodo tiene dos hijos */
			{
			    _nodo->item=buscar_minimo(_nodo->derecho);
			    _nodo->derecho=eliminar_minimo(_nodo->derecho);
            }
            else /* cambio de raíz */
                _nodo=(_nodo->izquierdo != NULL)? _nodo->izquierdo : _nodo->derecho;


    return _nodo;
}

void destruir (nodo *_nodo) {
    if(_nodo == NULL)
        return;

    destruir(_nodo->izquierdo);
    destruir(_nodo->derecho);
    free(_nodo);
    _nodo=NULL;
}


