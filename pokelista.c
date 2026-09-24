#include "pokelista.h"

void inicializarpokelista(pokelista* head) {
    head -> atual.id = 0;
    head -> atual.pokedex = 0;
    strcpy(head -> atual.nome, "HEAD");
    strcpy(head -> atual.tipo, "HEAD");

    head -> proximo = NULL;

    return;
}

void inserirpokelista(pokelista* head, pokemon aserinserido) {
    pokelista* cadeado = head;
    pokelista* novo = (pokelista *) malloc(sizeof(pokelista));

    int i = 1;
    while (cadeado -> proximo != NULL) {
        cadeado = cadeado -> proximo;
        i ++;
    }

    novo -> atual = aserinserido;
    
    cadeado -> proximo = novo;

    return;
}

pokemon removerpokelista(pokelista* head, int ID_aserremovido) {
    int id = 0;
    pokelista* cadeado = head;
    while (id != ID_aserremovido) {
        if (cadeado -> proximo == NULL) {
            printf("Erro! Índice não encontrado.");
            return cadeado -> atual;
        }

        cadeado = cadeado -> proximo;
        id ++;
    }

    if (cadeado -> proximo == NULL) {
        pokelista* anterior = head;
        for (int i = 0; i < ID_aserremovido - 1; i ++) {
            anterior = anterior -> proximo;
        }

        anterior -> proximo = NULL;

        pokemon deretorno = cadeado -> atual;
        free(cadeado);

        return deretorno;
    }

    else if (ID_aserremovido != 0) {
        pokelista* anterior = head;
        pokelista* sucessor = head;
        for (int i = 0; i < ID_aserremovido - 1; i ++) {
            anterior = anterior -> proximo;
        }
        for (int i = 0; i < ID_aserremovido + 1; i ++) {
            sucessor = anterior -> proximo;
        }

        anterior -> proximo = sucessor -> proximo;

        pokemon deretorno = cadeado -> atual;

        free(cadeado);

        return deretorno;
    }
}

pokemon buscapokelista(pokelista* head, int ID_parabusca) {
    int id = 0;
    pokelista* cadeado = head;
    while (id != ID_parabusca) {
        if (cadeado -> proximo == NULL) {
            printf("Erro! Índice não encontrado. Retornando ultimo elemento...");
            return cadeado -> atual;
        }

        cadeado = cadeado -> proximo;
        id ++;
    }

    return cadeado -> atual;
}

void imprimirpokelista(pokelista* head) {
    pokelista* cadeado = head -> proximo;
    while (cadeado -> proximo != NULL) {
        imprimepokemon(cadeado -> atual);
        printf("====================\n");
    }
}