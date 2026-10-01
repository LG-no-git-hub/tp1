#include "pokelista.h"

/* A inicializarpokelista recebe um ponteiro para pokelista e altera seus campos.
Isso é feito para evitar casos em que a pokelista é vazia. */

void inicializarpokelista(pokelista* head) {
    head -> atual.id = 0;
    head -> atual.pokedex = 0; 
    strcpy(head -> atual.nome, "HEAD");
    strcpy(head -> atual.tipo, "HEAD");

    head -> proximo = NULL;

    return;
}

/* Para inserir um pokemon à pokelista, é alocada a memória para um struct pokelista
cujo endereço correspondente ao próximo item é NULL. Também é utilizado um "cadeado" que
é responsável por armazenar o endereço de memória do último item da lista, cujo campo 
"proximo" será igualado ao "novo".*/

void inserirpokelista(pokelista* head, pokemon aserinserido) {
    pokelista* cadeado = head;
    pokelista* novo = (pokelista *) malloc(sizeof(pokelista));
    novo -> proximo = NULL;

    while (cadeado -> proximo != NULL) {
        cadeado = cadeado -> proximo;
    }

    novo -> atual = aserinserido;
    
    cadeado -> proximo = novo;

    return;
}

/* A função removerpokelista remove o pokémon de uma pokelista 
conforme o índice dele. Além disso, ela retorna esse pokémon 
porque as operações em que ela é chamada geralmente exigem que
esse pokémon retornado va para algum outro lugar. */

pokemon removerpokelista(pokelista* head, int ID_aserremovido) {
    int id = 0;
    pokelista* cadeado = head;
    
    while (id != ID_aserremovido) {
        
        /* Nesta implementação, o índice é só a posição que o
        pokémon encontra-se na pokelista, e não tem muita relação
        com o campo "id" do pokémon. Na verdade, todas as
        chamadas desta função no main só mexem no primeiro pokémon
        (não-head) de uma pokelista. */
        
        if (cadeado -> proximo == NULL) {
            printf("Erro! Índice não encontrado.");
            return cadeado -> atual;
        }

        cadeado = cadeado -> proximo;
        id ++;
    }

    /* Este bloco if lida com o caso em que o ID representa o último 
    elemento da pokelista. Neste caso, o penúltimo elemento recebe o 
    ponteiro NULL no atributo próximo e o último elemento tem a 
    memória liberada. Além disso, é retornado o pokémon que foi 
    removido. */

    if (cadeado -> proximo == NULL) {
        pokelista* anterior = head;
        for (int i = 0; i < ID_aserremovido - 1; i ++) {
            anterior = anterior -> proximo;
        }

        anterior -> proximo = NULL;

        pokemon deretorno = cadeado -> atual;
        free(cadeado);

        return deretorno;
    }
        
    /* Já este bloco if lida com remoções no meio da lista.
    Nesse caso, o elemento anterior ao elemento que vai ser 
    removido recebe o ponteiro do elemento que sucede o elemento que vai
    ser removido. Paralelamente ao bloco anterior, é liberada a
    memória e o pokémon removido é retornado. */

    else if (ID_aserremovido != 0) {
        pokelista* anterior = head;
        pokelista* sucessor = head;
        for (int i = 0; i < ID_aserremovido - 1; i ++) {
            anterior = anterior -> proximo;
        }
        for (int i = 0; i < ID_aserremovido + 1; i ++) {
            sucessor = sucessor -> proximo;
        }

        anterior -> proximo = sucessor;

        pokemon deretorno = cadeado -> atual;

        free(cadeado);

        return deretorno;
    }
}

/* A função buscapokelista retorna o pokémon na posição 
ID_parabusca na lista. */

pokemon buscapokelista(pokelista* head, int ID_parabusca) {
    int id = 0;
    pokelista* cadeado = head;
    while (id != ID_parabusca) {
        if (cadeado -> proximo == NULL) {
            printf("Erro! Índice não encontrado. Retornando ultimo elemento...");
            return cadeado -> atual;
        }

        cadeado = cadeado -> proximo;
        id ++;
    }

    return cadeado -> atual;
}

/* As funções de impressão foram utilizadas somente para testes. */

void imprimirpokelista(pokelista* head) {
    pokelista* cadeado;

    if (head -> proximo != NULL) {
        cadeado = head -> proximo;
    }
    else {
        printf("(Vazia)\n");
        return;
    }

    while (1) {
        imprimepokemon(cadeado -> atual);
        printf("====================\n");
        if (cadeado -> proximo == NULL) {
            break;
        }
        cadeado = cadeado -> proximo;
    }
}
