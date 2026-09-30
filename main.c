#include "centro.h"

/* A função leitura_treinadores realiza a leitura das informações
dos treinadores conforme a especificação. */

void leitura_treinadores(FILE* stream, treinador* treinador1, treinador* treinador2) {
    char nome[50];
    int pokebolas;
    if (stream != NULL) {
        if (fscanf(stream, "%s %d", nome, &pokebolas) == 2) {
            inicializartreinador(treinador1, 1, nome, pokebolas);
        }
        
        /* Como o fscanf salva a posição que lê, é possível
        fazer isso sem preocupar com pular informações já 
        escaneadas. */
        
        if (fscanf(stream, "%s %d", nome, &pokebolas) == 2) {
            inicializartreinador(treinador2, 2, nome, pokebolas);
        }
    }

    return;
}

/* A função leitura_pokemon realiza a leitura das informações
dos pokémon. Primeiro ela lê a qtd. de pokémon conforme foi
especificado que deveria estar no arquivo de entrada na 
especificação. Depois, para cada linha, é chamada a função
inicializapokemon. Finalmente, os pokémon lido são colocados 
na lista de fugitivos do centro de pokémon. */

void leitura_pokemon(FILE* stream, centro* AEDS, int* qtdpokemon) {
    pokemon aseradicionado;
    fscanf(stream, "%d", qtdpokemon);
    for (int i = 0; i < *qtdpokemon; i ++) {
        aseradicionado = inicializapokemon(stream, i + 1);
        inserefugitivo(AEDS, aseradicionado);
    }
}

/* Escreve o início da missão conforme foi especificado na especificação. */

void escreveinicio(treinador* treinador1, treinador* treinador2, int qtdpokemon) {
    printf("========================================\n");
    printf("           INÍCIO DA MISSÃO\n");
    printf("========================================\n\n");
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n", get_nome_t(treinador1), get_pokebolas(treinador1));
    printf("Treinador(a) %s: posição (0,0) | Pokébolas: %d\n\n", get_nome_t(treinador2), get_pokebolas(treinador2));
    printf("Pokémons fugitivos a serem resgatados: %d\n\n", qtdpokemon);

    return;
}

/* Escreve o que deve ser escrito no caso em que o retorno de um treinador
para o centro de pesquisa é acionado e realiza as respectivas operações
especificadas no arquivo de especificação. */

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

/* Escreve o que deve ser escrito na atribuição de uma captura à um 
treinador e realiza as respectivas operações. No caso, a operação 
principal é o cálculo da distância entre os treinadores e o 
pokémon alvo. Além disso, o alvo é escolhido conforme a sua posição
na lista de fugitivos. */

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
    
    dt1 = sqrt(pow(dx1, 2) + pow(dy1, 2)); // d^2 = x^2 + y^2
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
    srand(time(NULL)); // Conforme está dito no centro.c, a seed para as pokebolas é time(NULL);
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

    /* Como a função atribuicaptura não aciona a si mesma, foi decido
    que enquanto houver fugitivos, a função será acionada. */

    while (!semfugitivos(&AEDS)) {
        atribuicaptura(&AEDS, &treinador1, &treinador2);
    }

    fclose(saida);

    /* O getchar() está aqui para previnir que o terminal feche imediatamente
    após o programa útil terminar. */
    
    getchar();

    return 0;
}
