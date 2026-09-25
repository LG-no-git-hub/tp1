#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct localizacao {
    int posx;
    int posy;
} localizacao;

typedef struct pokemon {
    int id;
    int pokedex;
    char nome[50];
    char tipo[25];
    localizacao pos;
} pokemon;

int get_id_p(pokemon atual);

int get_pokedex(pokemon atual);

char* get_nome_p(pokemon* atual);

char* get_tipo(pokemon* atual);

localizacao get_local_p(pokemon* atual);

int get_local_px(pokemon* atual);

int get_local_py(pokemon* atual);

void set_id_p(pokemon* atual, int set);

void set_pokedex(pokemon* atual, int set);

void set_nome_p(pokemon* atual, char set[50]);

void set_tipo(pokemon* atual, char set[25]);

void set_localizacao_p(pokemon* atual, int posx, int posy);

pokemon inicializapokemon(FILE* stream, int id);

void imprimepokemon(pokemon atual);

#endif