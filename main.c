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

void leitura_pokemon(FILE* stream, centro* AEDS) {
    int qtdpokemon;
    pokemon aseradicionado;
    fscanf(stream, "%d", &qtdpokemon);
    for (int i = 0; i < qtdpokemon; i ++) {
        aseradicionado.id = i + 1;
        fscanf(stream, "%d %s %s %d %d", &aseradicionado.pokedex, aseradicionado.nome, aseradicionado.tipo, &aseradicionado.pos.posx, &aseradicionado.pos.posy);
        inserirpokelista(AEDS -> fugitivos, aseradicionado);
    }

    return;
}

void atribuicaptura() {

}

void acionaretorno() {

}

void imprimerelatorio() {
    
}

int main() {
    centro AEDS;
    inicializacentro(&AEDS);
    printf("inicializou o AEDS\n");
    treinador treinador1, treinador2;

    FILE* entrada = NULL;

    entrada = fopen("entrada.txt", "r");

    leitura_treinadores(entrada, &treinador1, &treinador2);
    leitura_pokemon(entrada, &AEDS);

    imprimetreinador(&treinador1);
    imprimetreinador(&treinador2);
    imprimirpokelista(AEDS.fugitivos);

    fclose(entrada);

    FILE* saida = NULL;
    fopen(saida, "saida.txt", "w");

    getchar();

    return 0;
}