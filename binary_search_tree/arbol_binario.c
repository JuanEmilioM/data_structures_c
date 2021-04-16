#include "arbol_binario.h"
#include "implementacion_interna.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern arbol_binario *arbol_binario_crear(int elem_size) {
    arbol_binario *arbol=malloc(sizeof(arbol_binario));

    if(arbol == NULL)
        return NULL;

    arbol->size_elemento=elem_size;
    arbol->raiz=NULL;

    return arbol;
}

/********************************************************************/

extern void arbol_binario_destruir(arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return;
    destruir(arbol->raiz);
    free(arbol);
    arbol=NULL;
}

/********************************************************************/

extern int arbol_binario_esta_vacio(const arbol_binario *arbol) {
    if(arbol == NULL)
        return -1;

    if(arbol->raiz == NULL)
        return 1;
    else
        return 0;
}

/********************************************************************/

extern int arbol_binario_insertar(arbol_binario *arbol, void *item, arbol_binario_comparador comparador) {
    nodo *target=NULL;
    target=insertar(arbol->raiz,item,comparador,arbol->size_elemento);

    if(target == NULL)
        return -1;

    arbol->raiz=target;
    return 0;
}

/********************************************************************/
/**         Funciones para recorrer al arbol                       **/
/********************************************************************/
extern void arbol_binario_preorden(const arbol_binario *arbol, arbol_binario_impresor impresor) {
    if(arbol_binario_esta_vacio(arbol) == 1) {
        printf("\nEl arbol esta vacio...\n");
        return;
    }

    preorden(arbol->raiz,impresor);

}

extern void arbol_binario_inorden(const arbol_binario *arbol, arbol_binario_impresor impresor) {
    if(arbol_binario_esta_vacio(arbol) == 1) {
        printf("\nEl arbol esta vacio...\n");
        return;
    }

    inorden(arbol->raiz,impresor);

}

extern void arbol_binario_postorden(const arbol_binario *arbol, arbol_binario_impresor impresor) {
    if(arbol_binario_esta_vacio(arbol) == 1) {
        printf("\nEl arbol esta vacio...\n");
        return;
    }

    postorden(arbol->raiz,impresor);
}

/********************************************************************/

extern int arbol_binario_buscar(const arbol_binario *arbol, void *item, arbol_binario_comparador comparador) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return 0;

    return buscar(arbol->raiz,item,comparador);
}

extern void *arbol_binario_minimo(const arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return NULL;

    void *target=NULL;
    target=buscar_minimo(arbol->raiz);

    return target;
}

extern void *arbol_binario_maximo(const arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return NULL;

    void *target=NULL;
    target=buscar_maximo(arbol->raiz);

    return target;
}


/********************************************************************/

extern int arbol_binario_altura(const arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return 0;
    else
        return altura(arbol->raiz);
}

/********************************************************************/

extern int arbol_binario_eliminar(arbol_binario *arbol, void *item, arbol_binario_comparador comparador) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return -1;

    nodo *target=NULL;
    target=eliminar(arbol->raiz,item,comparador);

    if(target == NULL)
        return -1;

    arbol->raiz=target;

    return 1;
}

extern int arbol_binario_eliminar_minimo (arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return -1;

    nodo *target=NULL;
    target=eliminar_minimo(arbol->raiz);

    if(target == NULL)
        return -1;

    arbol->raiz=target;

    return 1;
}

extern int arbol_binario_eliminar_maximo(arbol_binario *arbol) {
    if(arbol_binario_esta_vacio(arbol) == 1)
        return -1;

    nodo *target=NULL;
    target=eliminar_maximo(arbol->raiz);

    if(target == NULL)
        return -1;

    arbol->raiz=target;

    return 1;

}

/********************************************************************/
