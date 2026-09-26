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
        aseradicionado = inicializapokemon(stream, i + 1);
        inserefugitivo(AEDS, aseradicionado);
    }
}

void escreveinicio(treinador* treinador1, treinador* treinador2, int qtdpokemon) {
    printf("========================================\n");
    printf("           INÍCIO DA MISSÃO\n");
    printf("========================================\n\n");
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n", get_nome_t(treinador1), get_pokebolas(treinador1));
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n\n", get_nome_t(treinador2), get_pokebolas(treinador2));
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", qtdpokemon);

    return;
}

void acionaretorno(centro* AEDS, treinador* depokemon) {
    int RNGpokebolas;

    printf("========================================\n");
    printf("      Treinador(a) %s SEM POKÉBOLAS\n", get_nome_t(depokemon));
    printf("========================================\n\n");

    printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n\n", get_nome_t(depokemon));

    set_local_t(depokemon, get_local_c(AEDS));

    printf("Entregando Pokémon ao Centro de Pesquisa.\n\n");

    recebepokemon(AEDS, depokemon);

    RNGpokebolas = recarregabolas();

    set_pokebolas(depokemon, RNGpokebolas);

    printf("Treinador(a) %s recebeu %d Pokébolas.\n\n", get_nome_t(depokemon), RNGpokebolas);
}

void atribuicaptura(centro* AEDS, treinador* treinador1, treinador* treinador2) {
    int dx1, dx2, dy1, dy2;
    double dt1, dt2;
    printf("----------------------------------------\n");
    printf("Pokémon alvo: %s\n", get_nome_p(get_fugitivo(AEDS)));
    printf("Localização: (%d, %d)\n\n", get_local_px(get_fugitivo(AEDS)), get_local_py(get_fugitivo(AEDS)));

    dx1 = (get_local_tx(treinador1)) - (get_local_px(get_fugitivo(AEDS)));
    dx2 = (get_local_tx(treinador2)) - (get_local_px(get_fugitivo(AEDS)));
    dy1 = (get_local_ty(treinador1)) - (get_local_py(get_fugitivo(AEDS)));
    dy2 = (get_local_ty(treinador2)) - (get_local_py(get_fugitivo(AEDS)));
    
    dt1 = sqrt(pow(dx1, 2) + pow(dy1, 2));
    dt2 = sqrt(pow(dx2, 2) + pow(dy2, 2));

    printf("Distância Treinador(a) %s: %.2llf\n", get_nome_t(treinador1), dt1);
    printf("Distância Treinador(a) %s: %.2llf\n\n", get_nome_t(treinador2), dt2);

    treinador* maisproximo;

    if (dt1 <= dt2) {
        maisproximo = treinador1;
    }
    else {
        maisproximo = treinador2;
    }

    printf("Missão atribuída ao Treinador(a) %s\n\n", get_nome_t(maisproximo));
    printf("Treinador(a) %s se movimentou para (%d, %d).\n", get_nome_t(maisproximo), get_local_px(get_fugitivo(AEDS)), get_local_py(get_fugitivo(AEDS)));
    printf("%s capturado com sucesso!\n\n", get_nome_p(get_fugitivo(AEDS)));

    set_local_t(maisproximo, get_local_p(get_fugitivo(AEDS)));

    captura(maisproximo, removefugitivo(AEDS, 1));

    printf("Pokébolas restantes para o Treinador(a) %s: %d\n\n", get_nome_t(maisproximo), get_pokebolas(maisproximo));

    if (get_pokebolas(maisproximo) == 0) {
        acionaretorno(AEDS, maisproximo);
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

    escreveinicio(&treinador1, &treinador2, qtdpokemon);

    FILE* saida;
    saida = fopen("relatorio.txt", "w");

    while (!semfugitivos(&AEDS)) {
        atribuicaptura(&AEDS, &treinador1, &treinador2);
    }

    fclose(saida);

    getchar();

    return 0;
}