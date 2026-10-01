#include "centro.h"

/* A função inicializa as celulas cabeça das pokelistas de 
fugitivos e recuperados do centro pokémon e centraliza a
localização do centro em (0, 0). */

void inicializacentro(centro* depokemon) {
    depokemon -> fixa.posx = 0;
    depokemon -> fixa.posy = 0;
    depokemon -> fugitivos = (pokelista*) malloc (sizeof(pokelista));
    depokemon -> recuperados = (pokelista*) malloc (sizeof(pokelista));
    inicializarpokelista(depokemon -> fugitivos);
    inicializarpokelista(depokemon -> recuperados);
}

/* As funções de inserir e remover pokémon das pokelistas
de fugitivos e recuperados chamam as funções da pokelista
e aplicam elas nas pokelistas do TAD centro. */

void inserefugitivo(centro* depokemon, pokemon fugitivo) {
    inserirpokelista(depokemon -> fugitivos, fugitivo);
    return;
}

pokemon removefugitivo(centro* depokemon, int iddofugitivo) {
    return removerpokelista(depokemon -> fugitivos, iddofugitivo);
}

/* Neste caso, a função é chamada até que a pokelista do treinador esteja
vazia. */

void recebepokemon(centro* AEDS, treinador* depokemon) {
    while (depokemon -> lista -> proximo != NULL) {
        inserirpokelista(AEDS -> recuperados, removerpokelista(depokemon -> lista, 1));
    }
}

pokemon removerecuperado(centro* depokemon, int iddofugitivo) {
    return removerpokelista(depokemon -> recuperados, iddofugitivo);
}

/* As funções de impressão foram utilizadas somente para testes. */

void imprimerecuperado(centro* depokemon) {
    imprimirpokelista(depokemon -> recuperados);
}

/* Gera um número aleatório entre 1 e 20 e retorna esse número para 
ser a qtd. de pokebolas do treinador que voltou para o centro e está
sem pokebolas. No main, a seed é a função time(NULL) da biblioteca
padrão time.h. */

int recarregabolas() {
    int RNG = (rand() % 20) + 1;
    return(RNG);
}

localizacao get_local_c(centro* depokemon) {
    return depokemon -> fixa;
}

pokemon* get_fugitivo(centro* depokemon) {
    return &depokemon -> fugitivos -> proximo -> atual;
}

/* retorna 1 se a pokelista de fugitivos for vazia */

int semfugitivos(centro* depokemon) {
    return depokemon -> fugitivos -> proximo == NULL;
}
