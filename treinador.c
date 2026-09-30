#include "treinador.h"

/* A função inicializatreinador inicializa o treinador com as variáveis
que foram lidas do arquivo de entrada, centraliza a localização deles,
aloca memória para a sua pokelista e inicializa ela. */

void inicializartreinador(treinador* quetreina, int identificador, char nomedotreinador[50], int qtdpokebolas) {
    quetreina -> id = identificador;
    strcpy(quetreina -> nome, nomedotreinador);
    quetreina -> lista = (pokelista *) malloc(sizeof(pokelista));
    inicializarpokelista(quetreina -> lista);
    quetreina -> local.posx = 0; quetreina -> local.posy = 0;
    quetreina -> pokebolas = qtdpokebolas;
    return;
}

/* A função de captura insere o pokemon que vai ser capturado
na pokelista do treinador e subtrai uma pokebola da qtd. de
pokebolas do treinador */

void captura(treinador* quetreina, pokemon asercapturado) {
    inserirpokelista(quetreina -> lista, asercapturado);
    set_pokebolas(quetreina, get_pokebolas(quetreina) - 1);
    return;
}

/* As funções de impressão foram uitilizadas somente para testes. */

void imprimetreinador(treinador* quetreina) {
    printf("ID do treinador: %d\n", quetreina -> id);
    printf("Nome do treinador: %s\n", quetreina -> nome);
    printf("Localizacao: %d %d\n", quetreina -> local.posx, quetreina -> local.posy);
    printf("===== POKELISTA =====\n");
    imprimirpokelista(quetreina -> lista);
    printf("Pokebolas: %d\n\n", quetreina -> pokebolas);

    return;
}

/* As funções get e set retornam os respectivos atributos do 
treinador */

int get_pokebolas(treinador* atual) {
    return atual -> pokebolas;
}

char* get_nome_t(treinador* atual) {
    return atual -> nome;
}

/* A função set_local_t é equivalente à função de mover 
especificada no arquivo de especificação */

void set_local_t(treinador* atual, localizacao lugar) {
    atual -> local = lugar;
    return;
}

void set_pokebolas(treinador* atual, int set) {
    atual -> pokebolas = set;
    return;
}

int get_local_tx(treinador* atual) {
    return atual -> local.posx;
}

int get_local_ty(treinador* atual) {
    return atual -> local.posy;
}

pokelista* get_lista(treinador* atual) {
    return atual -> lista;
}
