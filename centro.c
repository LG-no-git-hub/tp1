#include "centro.h"

void inicializacentro(centro* depokemon) {
    depokemon -> fixa.posx = 0;
    depokemon -> fixa.posy = 0;
    depokemon -> fugitivos = (pokelista*) malloc (sizeof(pokelista));
    depokemon -> recuperados = (pokelista*) malloc (sizeof(pokelista));
    inicializarpokelista(depokemon -> fugitivos);
    inicializarpokelista(depokemon -> recuperados);
}

void inserefugitivo(centro* depokemon, pokemon fugitivo) {
    inserirpokelista(depokemon -> fugitivos, fugitivo);
    return;
}

pokemon removefugitivo(centro* depokemon, int iddofugitivo) {
    return removerpokelista(depokemon -> fugitivos, iddofugitivo);
}

void recebepokemon(centro* AEDS, treinador* depokemon) {
    while (depokemon -> lista -> proximo != NULL) {
        inserirpokelista(AEDS -> recuperados, removerpokelista(depokemon -> lista, 1));
    }
}

void imprimerecuperado(centro* depokemon) {
    imprimirpokelista(depokemon -> recuperados);
}

int recarregabolas() {
    int RNG = (rand() % 20) + 1;
    return(RNG);
}
