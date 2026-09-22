#ifndef CENTRO_H
#define CENTRO_H

#include "treinador.h"

typedef struct centro {
    localizacao fixa;
    pokelista* fugitivos;
    pokelista* recuperados;
} centro;

void inicializacentro(centro* depokemon);

void inserefugitivo(centro* depokemon, pokemon fugitivo);

void removefugitivo(centro* depokemon, int iddofugitivo);

void imprimerecuperado(centro* depokemon);

void recebepokemon(centro* depokemon, pokemon recuperado);

int recarregabolas();

#endif
