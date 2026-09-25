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

void escreveinicio(treinador treinador1, treinador treinador2, int qtdpokemon) {
    printf("========================================\n");
    printf("           INÍCIO DA MISSÃO\n");
    printf("========================================\n\n");
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n", treinador1.nome, treinador1. pokebolas);
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n\n", treinador2.nome, treinador2. pokebolas);
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", qtdpokemon);

    return;
}

void acionaretorno(centro* AEDS, treinador* depokemon) {
    int RNGpokebolas;

    printf("========================================\n");
    printf("      Treinador(a) %s SEM POKÉBOLAS\n", depokemon -> nome);
    printf("========================================\n\n");

    printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n\n", depokemon -> nome);

    depokemon -> local = AEDS -> fixa;

    printf("Entregando Pokémon ao Centro de Pesquisa.\n\n");

    recebepokemon(AEDS, depokemon);

    RNGpokebolas = recarregabolas();

    depokemon -> pokebolas = RNGpokebolas;

    printf("Treinador(a) %s recebeu %d Pokébolas.\n\n", depokemon -> nome, RNGpokebolas);
}

void atribuicaptura(centro* AEDS, treinador* treinador1, treinador* treinador2) {
    int dx1, dx2, dy1, dy2;
    double dt1, dt2;
    printf("----------------------------------------\n");
    printf("Pokémon alvo: %s\n", AEDS -> fugitivos -> proximo -> atual.nome);
    printf("Localização: (%d, %d)\n\n", AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);

    dx1 = (treinador1 -> local.posx) - (AEDS -> fugitivos -> proximo -> atual.pos.posx);
    dx2 = (treinador2 -> local.posx) - (AEDS -> fugitivos -> proximo -> atual.pos.posx);
    dy1 = (treinador1 -> local.posy) - (AEDS -> fugitivos -> proximo -> atual.pos.posy);
    dy2 = (treinador2 -> local.posy) - (AEDS -> fugitivos -> proximo -> atual.pos.posy);
    
    dt1 = sqrt(pow(dx1, 2) + pow(dy1, 2));
    dt2 = sqrt(pow(dx2, 2) + pow(dy2, 2));

    printf("Distância Treinador(a) %s: %.2llf\n", treinador1 -> nome, dt1);
    printf("Distância Treinador(a) %s: %.2llf\n\n", treinador2 -> nome, dt2);

    if (dt1 <= dt2) {
        printf("Missão atribuída ao Treinador(a) %s\n\n", treinador1 -> nome);
        printf("Treinador(a) %s se movimentou para (%d, %d).\n", treinador1 -> nome, AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);
        printf("%s capturado com sucesso!\n\n", AEDS -> fugitivos -> proximo -> atual.nome);

        treinador1 -> local = AEDS -> fugitivos -> proximo -> atual.pos;
        treinador1 -> pokebolas -= 1;

        printf("Pokébolas restantes para o Treinador(a) %s: %d\n\n", treinador1 -> nome, treinador1 -> pokebolas);

        if (treinador1 -> pokebolas == 0) {
            acionaretorno(AEDS, treinador1);
        }
        inserirpokelista(treinador1 -> lista, removefugitivo(AEDS, 1));
    }
    else {
        printf("Missão atribuída ao Treinador(a) %s\n\n", treinador2 -> nome);
        printf("Treinador(a) %s se movimentou para (%d, %d).\n", treinador2 -> nome, AEDS -> fugitivos -> proximo -> atual.pos.posx, AEDS -> fugitivos -> proximo -> atual.pos.posy);
        printf("%s capturado com sucesso!\n\n", AEDS -> fugitivos -> proximo -> atual.nome);

        treinador2 -> local = AEDS -> fugitivos -> proximo -> atual.pos;
        treinador2 -> pokebolas -= 1;

        printf("Pokébolas restantes para o Treinador(a) %s: %d\n\n", treinador2 -> nome, treinador2 -> pokebolas);

        if (treinador2 -> pokebolas == 0) {
            acionaretorno(AEDS, treinador2);
        }
        inserirpokelista(treinador2 -> lista, removefugitivo(AEDS, 1));
    }
    
    return;
}

void imprimerelatorio() {

}

int main() {
    centro AEDS; int qtdpokemon; 
    srand(time(NULL));
    inicializacentro(&AEDS);
    treinador treinador1, treinador2;

    FILE* entrada = NULL;

    entrada = fopen("entrada.txt", "r");

    leitura_treinadores(entrada, &treinador1, &treinador2);
    leitura_pokemon(entrada, &AEDS, &qtdpokemon);

    fclose(entrada);

    escreveinicio(treinador1, treinador2, qtdpokemon);

    FILE* saida;
    saida = fopen("relatorio.txt", "w");

    while (AEDS.fugitivos -> proximo != NULL) {
        atribuicaptura(&AEDS, &treinador1, &treinador2);
    }

    fclose(saida);

    getchar();

    return 0;
}