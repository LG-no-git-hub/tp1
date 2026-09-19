#include "pokelista.h"

void inicializarpokelista(pokelista* head) {
    head -> atual.id = 0;
    head -> atual.pokedex = 0;
    strcpy(head -> atual.nome, "HEAD");
    strcpy(head -> atual.tipo, "HEAD");

    head -> proximo = NULL;

    return;
}