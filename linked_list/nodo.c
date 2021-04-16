#include "lista_encadenada.h"
#include <stdlib.h>

void incrementar_indices (nodo *cursor) {
    while(cursor != NULL) {
        cursor->indice++;
        cursor=cursor->siguiente;
    }
}

void decrementar_indices(nodo *cursor) {
    while(cursor != NULL) {
        cursor->indice--;
        cursor=cursor->siguiente;
    }
}

void nodo_destruir(nodo *cursor) {
    if(cursor == NULL)
        return;

    nodo_destruir(cursor->siguiente);
    free(cursor);
}
