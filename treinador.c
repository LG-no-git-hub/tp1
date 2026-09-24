#include "treinador.h"

void inicializartreinador(treinador* quetreina, int identificador, char nomedotreinador[50], int qtdpokebolas) {
    quetreina -> id = identificador;
    quetreina -> nome = nomedotreinador;
    inicializarpokelista(quetreina -> lista);
    quetreina -> local.posx = 0; quetreina -> local.posy = 0;
    quetreina -> pokebolas = qtdpokebolas
    return;
}

void movimenta(treinador* quetreina, localizacao desejada) {
    quetreina -> local = desejada;
    return;
}

void captura(treinador* quetreina, pokemon asercapturado) {
    inserirpokelista(quetreina -> lista, asercapturado);
    return;
}

void imprimetreinador(treinador* quetreina) {
    printf("ID do treinador: %d\n", quetreina -> id);
    printf("Nome do treinador: %s\n", quetreina -> nome);
    printf("Localizacao: %s %s", quetreina -> local.posx, quetreina -> local.posy);
    printf("===== POKELISTA =====\n");
    imprimirpokelista(quetreina -> lista);
    printf("Pokebolas: %d", quetreina -> pokebolas);

    return;
}
