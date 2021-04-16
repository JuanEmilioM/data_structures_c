#include "lista_encadenada.h"
#include "funciones_nodo.h"

#include <stdlib.h>
#include <string.h>

extern lista *lista_crear (int size_elem) {
    lista *_lista=(lista*)malloc(sizeof(lista));

    if(_lista == NULL)
        return NULL;

    _lista->nodos=0;
    _lista->size_elemento=size_elem;
    _lista->head=NULL;

    return _lista;
}

extern int lista_esta_vacia(const lista *_lista) {
    if(_lista == NULL)
        return 1;

    if(_lista->nodos == 0)
        return 1;
    else
        return 0;
}

extern int lista_insertar(lista *_lista, void *item) {

    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    /**void *target=(char*)malloc(_lista->size_elemento);
    memcpy(target,item,_lista->size_elemento);
    nuevo->item=target;
    **/
    nuevo->item=malloc(_lista->size_elemento);
    memcpy(nuevo->item,item,_lista->size_elemento);
    nuevo->indice=1;
    _lista->nodos++;

    if(lista_esta_vacia(_lista)) { /** Caso trivial: lista vacia **/
        _lista->head=nuevo;
        return 1;
    }
    else {
        incrementar_indices(_lista->head);
        nuevo->siguiente=_lista->head;
        _lista->head=nuevo;
        return 1;
    }
}

extern int lista_insertar_posicion(lista *_lista, void *item, int _indice) {
    if(lista_esta_vacia(_lista))
        return lista_insertar(_lista,item);

    if(_indice < 1 || _indice > _lista->nodos+1) /** +1 porque puede querer ingresarse un elemento en el final de la lista **/
        return -1;

    nodo *cursor=_lista->head;

    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    void *target=malloc(_lista->size_elemento);
    memcpy(target,item,_lista->size_elemento);
    nuevo->item=target;

    _lista->nodos++;

    while(cursor->siguiente != NULL) {
        if(cursor->siguiente->indice == _indice) {
            nuevo->siguiente=cursor->siguiente;
            cursor->siguiente=nuevo;
            nuevo->indice=_indice;
            incrementar_indices(nuevo->siguiente);

            return 1;
        }
        cursor=cursor->siguiente;
    }

    if(cursor->siguiente == NULL) {
        nuevo->siguiente=NULL;
        nuevo->indice=_indice;
        cursor->siguiente=nuevo;

        return 1;
    }
    else
        return -1;
}

extern int lista_cantidad_elementos(const lista* _lista) {
    if(_lista == NULL)
        return 0;
    return _lista->nodos;
}

extern int lista_primer_elemento(const lista *_lista, void *destino) {
    if(lista_esta_vacia(_lista))
        return -1;

    memcpy(destino,_lista->head->item,_lista->size_elemento);
    return 0;
}

extern int lista_obtener_elemento(const lista *_lista, void *destino, int _indice) {
    if(lista_esta_vacia(_lista))
        return -1;

    if(_indice < 1 || _indice>_lista->nodos)
        return -1;

    nodo *cursor=_lista->head;
    while(cursor->indice != _indice)
        cursor=cursor->siguiente;

    memcpy(destino,cursor->item,_lista->size_elemento);
    return 0;
}

extern int lista_eliminar(lista *_lista, void *destino, int _indice) {
    if(lista_esta_vacia(_lista))
        return -1;

    if(_indice < 1 || _indice>_lista->nodos)
        return -1; /** Indice fuera de rango **/

    nodo *cursor=_lista->head;
    nodo *cursor_anterior;

    /** Supresión del primer elemento de la lista **/
    if(_indice == 1) {
        _lista->head=_lista->head->siguiente;
        _lista->nodos--;
        decrementar_indices(_lista->head);
        memcpy(destino,cursor->item,_lista->size_elemento);
        free(cursor);
        return 0;
    }

    while(cursor->indice != _indice) {
        cursor_anterior=cursor;
        cursor=cursor->siguiente;
    }

    cursor_anterior->siguiente=cursor->siguiente;
    _lista->nodos--;
    decrementar_indices(cursor_anterior->siguiente);
    memcpy(destino,cursor->item,_lista->size_elemento);
    free(cursor);

    return 0;
}

extern int lista_buscar(lista *_lista, void *item, lista_comparador comparador) {
    nodo *cursor=_lista->head;

    while(cursor != NULL)
        if(comparador(item,cursor->item) == 0)
            return cursor->indice;
        else
            cursor=cursor->siguiente;

    return -1;
}

extern int lista_ordenar(lista *_lista, int tipo_orden, lista_comparador comparador) {
    if(lista_esta_vacia(_lista))
        return -1;

    if(tipo_orden != ASCENDENTE && tipo_orden != DESCENDENTE)
        return -1;

    nodo *cursor;
    void *aux=(char*)malloc(_lista->size_elemento);
    int i=0;

    for(; i<_lista->nodos; i++) {
        cursor=_lista->head;
        while(cursor->siguiente != NULL) {
            switch(tipo_orden) {
            case ASCENDENTE:
                if(comparador(cursor->item,cursor->siguiente->item) > 0) {
                    memcpy(aux,cursor->item,_lista->size_elemento);
                    memcpy(cursor->item,cursor->siguiente->item,_lista->size_elemento);
                    memcpy(cursor->siguiente->item,aux,_lista->size_elemento);
                }
                break;
            case DESCENDENTE:
                if(comparador(cursor->item,cursor->siguiente->item) < 0) {
                    memcpy(aux,cursor->item,_lista->size_elemento);
                    memcpy(cursor->item,cursor->siguiente->item,_lista->size_elemento);
                    memcpy(cursor->siguiente->item,aux,_lista->size_elemento);
                }
                break;

            }
            cursor=cursor->siguiente;
        }
    }

    return 0;
}

void lista_imprimir(lista *_lista, lista_impresor impresor) {
    nodo *cursor=_lista->head;

    while(cursor != NULL) {
        impresor(cursor->item);
        cursor=cursor->siguiente;
    }
}

extern void lista_destruir(lista *_lista) {
    nodo_destruir(_lista->head);
    _lista->nodos=0;
    free(_lista);
    _lista=NULL;
}
