#ifndef TREINADOR_H
#define TREINADOR_H

#include "pokelista.h"

typedef struct treinador {
    int id;
    char nome[50];
    localizacao local;
    pokelista* lista;
    int pokebolas;
} treinador;

void inicializartreinador(treinador* quetreina, int identificador, char nomedotreinador[50], int qtdpokebolas);

void movimenta(treinador* quetreina, localizacao desejada);

void captura(treinador* quetreina, pokemon asercapturado);

void imprimetreinador(treinador* quetreina);

#endif
