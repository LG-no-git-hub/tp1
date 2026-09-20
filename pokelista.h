#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"

typedef struct pokelista {
    pokemon atual;
    pokemon* proximo;
} pokelista;

void inicializarpokelista(pokelista* head);

void inserirpokelista(pokelista* head, pokemon aserinserido);

pokemon removerpokelista(pokelista* head, int ID_aserremovido);

pokemon buscapokelista(pokelista* head, int ID_parabusca);

void imprimirpokelista(pokelista* head);

#endif