#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

// Estrutura da carta
typedef struct {
    int numero;
    char naipe;
} tCarta;

// Registro da pilha
typedef struct {
    tCarta carta;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

// Inicializações básicas
void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}

bool estaVazia(PILHA* p) {
    return p->topo == NULL;
}

bool inserirElemPilha(PILHA* p, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool excluirElemPilha(PILHA* p, REGISTRO* reg) {
    if (p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

// Função fornecida para exibir a carta
void exibeCarta(tCarta carta) {
    if (carta.numero >= 2 && carta.numero <= 10)
        printf("%d", carta.numero);
    else {
        switch (carta.numero) {
            case 11: printf("Valete"); break;
            case 12: printf("Dama"); break;
            case 13: printf("Rei"); break;
            case 1:  printf("As"); break;
            default: printf("Invalida");
        }
    }

    printf(" de ");
    switch (carta.naipe) {
        case 'o': printf("Ouros\n"); break;
        case 'c': printf("Copas\n"); break;
        case 'p': printf("Paus\n"); break;
        case 'e': printf("Espadas\n"); break;
    }
}

void empilhaBaralho(PILHA* p) {
    char naipes[] = {'o', 'c', 'p', 'e'};  // Ouros, Copas, Paus, Espadas
    for (int i = 0; i < 4; i++) {         // Ordem direta
        for (int num = 1; num <= 13; num++) {
            REGISTRO r;
            r.carta.numero = num;
            r.carta.naipe = naipes[i];
            inserirElemPilha(p, r); // Insere no topo da pilha
        }
    }
}



// Função para buscar a carta e contar quantas foram descartadas
int buscaCarta(PILHA* p, tCarta alvo, tCarta* encontrada) {
    REGISTRO r;
    int descartadas = 0;
    while (excluirElemPilha(p, &r)) {
        if (r.carta.numero == alvo.numero && r.carta.naipe == alvo.naipe) {
    		*encontrada = r.carta;
    		break;
		}
		descartadas++;
    }
    return descartadas;
}

// Função principal
int main() {
    PILHA pilha;
    inicializarPilha(&pilha);
    empilhaBaralho(&pilha);

    tCarta procurada;
    scanf("%d %c", &procurada.numero, &procurada.naipe);

    tCarta resultado;
    int descartadas = buscaCarta(&pilha, procurada, &resultado);

    exibeCarta(resultado);
    printf("%d\n", descartadas);

    return 0;
}

