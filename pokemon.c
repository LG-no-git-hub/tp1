#include "pokemon.h"

int get_id(pokemon atual) {
    return atual.id;
}

int get_pokedex(pokemon atual) {
    return atual.pokedex;
}

char* get_nome(pokemon* atual) {
    return atual -> nome;
}

char* get_tipo(pokemon* atual) {
    return atual -> tipo;
}

localizacao get_localizacao(pokemon atual) {
    return atual.pos;
}

void set_id(pokemon* atual, int set) {
    atual -> id = set;
    return;
}

void set_pokedex(pokemon* atual, int set) {
    atual -> pokedex = set;
    return;
}

void set_nome(pokemon* atual, char set[50]) {
    strcpy(atual -> nome, set);
    return;
}

void set_tipo(pokemon* atual, char set[25]) {
    strcpy(atual -> nome, set);
    return;    
}

void set_localizacao(pokemon* atual, int posx, int posy) {
    atual -> pos.posx = posx;
    atual -> pos.posy = posy;
    return;
}

pokemon* inicializapokemon() {
    return ((pokemon*) malloc(sizeof(pokemon)));
}

void imprimepokemon(pokemon atual) {
    printf("Id: %d\n", atual.id);
    printf("Numero PokeDex: %d\n", atual.pokedex);
    printf("Nome do Pokemon: %s\n", atual.nome);
    printf("Tipo do Pokemon: %s\n", atual.tipo);
    printf("Coordenadas X: %d, Coordenadas Y: %d\n", atual.pos.posx, atual.pos.posy);
}