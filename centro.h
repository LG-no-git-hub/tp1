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

pokemon removefugitivo(centro* depokemon, int iddofugitivo);

void imprimerecuperado(centro* depokemon);

void recebepokemon(centro* AEDS, treinador* depokemon);

int recarregabolas();

localizacao get_local_c(centro* depokemon);

pokemon* get_fugitivo(centro* depokemon);

int semfugitivos(centro* depokemon);

#endif
