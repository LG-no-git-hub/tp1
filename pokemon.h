#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int get_id(pokemon atual);

int get_pokedex(pokemon atual);

char* get_nome(pokemon atual);

char* get_tipo(pokemon atual);

localizacao get_localizacao(pokemon atual);

void set_id(pokemon* atual, int set);

void set_pokedex(pokemon* atual, int set);

void set_nome(pokemon* atual, char set[50]);

void set_tipo(pokemon* atual, char set[25]);

void imprimepokemon(pokemon atual);

#endif