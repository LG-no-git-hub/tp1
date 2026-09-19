#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"

typedef struct pokelista {
    pokemon atual;
    pokelista* proximo;
} pokelista;

void inicializarpokelista(pokelista* head);

void inserirpokelista(pokelista* head, pokemon aserinserido);

void removerpokelista(pokelista* head, int ID_aserremovido);

void buscapokelista(pokelista* head, int ID_parabusca);

void imprimirpokelista(pokelista* head);

#endif