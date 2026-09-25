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

void captura(treinador* quetreina, pokemon asercapturado);

void imprimetreinador(treinador* quetreina);

int get_pokebolas(treinador* atual);

char* get_nome_t(treinador* atual);

int get_local_tx(treinador* atual);

int get_local_ty(treinador* atual);

void set_local_t(treinador* atual, localizacao lugar);

void set_pokebolas(treinador* atual, int set);

pokelista* get_lista(treinador* atual);

#endif
