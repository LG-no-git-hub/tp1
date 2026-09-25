#include "pokemon.h"

int get_id_p(pokemon atual) {
    return atual.id;
}

int get_pokedex(pokemon atual) {
    return atual.pokedex;
}

char* get_nome_p(pokemon atual) {
    return atual.nome;
}

char* get_tipo(pokemon atual) {
    return atual.tipo;
}

localizacao get_local_p(pokemon atual) {
    return atual.pos;
}

int get_local_px(pokemon atual) {
    return atual.pos.posx;
}

int get_local_py(pokemon atual) {
    return atual.pos.posy;
}

/* foi optado por não utilizar as funções "set" no main porque a implementação delas tornaria
o código mais complicado de se fazer e mais difícil de ler, optando-se por ler as informações 
diretamente do arquivo de entrada. */

void set_id_p(pokemon* atual, int set) {
    atual -> id = set;
    return;
}

void set_pokedex(pokemon* atual, int set) {
    atual -> pokedex = set;
    return;
}

void set_nome_p(pokemon* atual, char set[50]) {
    strcpy(atual -> nome, set);
    return;
}

void set_tipo(pokemon* atual, char set[25]) {
    strcpy(atual -> nome, set);
    return;    
}

void set_localizacao_p(pokemon* atual, int posx, int posy) {
    atual -> pos.posx = posx;
    atual -> pos.posy = posy;
    return;
}

pokemon inicializapokemon(FILE* stream, int id) {
    pokemon aserinicializado;
    int pokedex;
    char nome[50];
    char tipo[25];
    int posx, posy;
    fscanf(stream, "%d %s %s %d %d", &pokedex, nome, tipo, &posx, &posy);
    set_id_p(&aserinicializado, id);
    set_nome_p(&aserinicializado, nome);
    set_tipo(&aserinicializado, tipo);
    set_localizacao_p(&aserinicializado, posx, posy);
    return aserinicializado;
}

/* A função imprimepokemon só foi utilizada para testes. */

void imprimepokemon(pokemon atual) {
    printf("Id: %d\n", atual.id);
    printf("Numero PokeDex: %d\n", atual.pokedex);
    printf("Nome do Pokemon: %s\n", atual.nome);
    printf("Tipo do Pokemon: %s\n", atual.tipo);
    printf("Coordenadas X: %d, Coordenadas Y: %d\n", atual.pos.posx, atual.pos.posy);
}