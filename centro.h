#ifndef CENTRO_H
#define CENTRO_H

#include "treinador.h"

typedef struct centro {
    localizacao fixa;
    pokelista fugitivos;
    pokelista recuperados;
} centro;

void inicializacentro(centro* depokemon);

void inserefugitivo(centro* depokemon);

void removefugitivo(centro* depokemon);

void imprimenrecuperado(centro* depokemon);

void recebepokemon(centro* depokemon);

void recarregabolas(treinador* depokemon);

#endif