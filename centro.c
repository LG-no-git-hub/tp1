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

void imprimerecuperado(centro* depokemon) {
    imprimirpokelista(depokemon -> recuperados);
}

int recarregabolas() {
    int tempo = (int) time(NULL);
    int RNG = (tempo % 20) + 1;
    
    return(RNG);
}
