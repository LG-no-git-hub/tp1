#include "centro.h"

void leitura_treinadores(FILE* stream, treinador* treinador1, treinador* treinador2) {
    char nome[50];
    int pokebolas;
    if (stream != NULL) {
        if (fscanf(stream, "%s %d", nome, &pokebolas) == 2) {
            inicializartreinador(treinador1, 1, nome, pokebolas);
        }
        if (fscanf(stream, "%s %d", nome, &pokebolas) == 2) {
            inicializartreinador(treinador2, 2, nome, pokebolas);
        }
    }

    return;
}

void leitura_pokemon(FILE* stream, centro* AEDS, int* qtdpokemon) {
    pokemon aseradicionado;
    fscanf(stream, "%d", qtdpokemon);
    for (int i = 0; i < *qtdpokemon; i ++) {
        aseradicionado.id = i + 1;
        fscanf(stream, "%d %s %s %d %d", &aseradicionado.pokedex, aseradicionado.nome, aseradicionado.tipo, &aseradicionado.pos.posx, &aseradicionado.pos.posy);
        inserefugitivo(AEDS, aseradicionado);
    }
}

void escreveinicio(FILE* saida, treinador treinador1, treinador treinador2, int qtdpokemon) {
    fprintf(saida, "========================================\n");
    fprintf(saida, "           INÍCIO DA MISSÃO\n");
    fprintf(saida, "========================================\n\n");
    fprintf(saida, "Treinador(a) %s: posição (0,0) | Pokébolas: %d\n", treinador1.nome, treinador1. pokebolas);
    fprintf(saida, "Treinador(a) %s: posição (0,0) | Pokébolas: %d\n\n", treinador2.nome, treinador2. pokebolas);
    fprintf(saida, "Pokémons fugitivos a serem resgatados: %d\n\n", qtdpokemon);
    fprintf(saida, "----------------------------------------\n");

    return;
}

void atribuicaptura(FILE* saida, centro* AEDS, treinador* treinador1, treinador* treinador2) {
    int dx1, dx2, dy1, dy2;
    double dt1, dt2;
    fprintf(saida, "Pokémon alvo: %s\n", AEDS -> fugitivos -> proximo -> atual.nome);
    fprintf(saida, "Localização: (%d, %d)\n\n", AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);

    dx1 = (treinador1 -> local.posx) - (AEDS -> fugitivos -> proximo -> atual.pos.posx);
    dx2 = (treinador2 -> local.posx) - (AEDS -> fugitivos -> proximo -> atual.pos.posx);
    dy1 = (treinador1 -> local.posy) - (AEDS -> fugitivos -> proximo -> atual.pos.posy);
    dy2 = (treinador2 -> local.posy) - (AEDS -> fugitivos -> proximo -> atual.pos.posy);
    
    dt1 = sqrt(pow(dx1, 2) + pow(dy1, 2));
    dt2 = sqrt(pow(dx2, 2) + pow(dy2, 2));

    fprintf(saida, "Distância Treinador(a) %s: %.2llf\n", treinador1 -> nome, dt1);
    fprintf(saida, "Distância Treinador(a) %s: %.2llf\n\n", treinador2 -> nome, dt2);

    if (dt1 >= dt2) {
        fprintf(saida, "Missão atribuída ao(à) Treinador(a) %s\n\n", treinador1 -> nome);
        fprintf(saida, "Treinador(a) %s se movimentou para (%d, %d).\n", treinador1 -> nome, AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);
        fprintf(saida, "%s capturado com sucesso!\n\n", AEDS -> fugitivos -> proximo -> atual.nome);
        treinador1 -> local = AEDS -> fugitivos -> proximo -> atual.pos;
        treinador1 -> pokebolas -= 1;
        if (treinador1 -> pokebolas == 0) {
            acionaretorno(treinador1);
        }
        inserirpokelista(treinador1 -> lista, removefugitivo(AEDS, 1));
    }
    else {
        fprintf(saida, "Missão atribuída ao(à) Treinador(a) %s\n\n", treinador2 -> nome);
        fprintf(saida, "Treinador(a) %s se movimentou para (%d, %d).\n", treinador2 -> nome, AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);
        fprintf(saida, "%s capturado com sucesso!\n\n", AEDS -> fugitivos -> proximo -> atual.nome);
        treinador2 -> local = AEDS -> fugitivos -> proximo -> atual.pos;
        treinador2 -> pokebolas -= 1;
        if (treinador1 -> pokebolas == 0) {
            acionaretorno(treinador1);
        }
        inserirpokelista(treinador2 -> lista, removefugitivo(AEDS, 1));
    }
    
    return;
}

void acionaretorno(treinador* depokemon) {

}

void imprimerelatorio() {

}

int main() {
    centro AEDS; int qtdpokemon;
    inicializacentro(&AEDS);
    treinador treinador1, treinador2;

    FILE* entrada = NULL;

    entrada = fopen("entrada.txt", "r");

    leitura_treinadores(entrada, &treinador1, &treinador2);
    leitura_pokemon(entrada, &AEDS, &qtdpokemon);

    imprimetreinador(&treinador1);
    imprimetreinador(&treinador2);
    imprimirpokelista(AEDS.fugitivos);

    fclose(entrada);

    FILE* saida = NULL;
    saida = fopen("saida.txt", "w");

    escreveinicio(saida, treinador1, treinador2, qtdpokemon);

    atribuicaptura(saida, &AEDS, &treinador1, &treinador2);

    fclose(saida);
    getchar();
    return 0;
}