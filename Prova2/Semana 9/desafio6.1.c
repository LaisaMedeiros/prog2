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

void exibeCarta(int num, char naipe) {
    // Switch para o número da carta
    switch (num) {
        case 1:
            printf("Às de ");
            break;
        case 11:
            printf("Valete de ");
            break;
        case 12:
            printf("Dama de ");
            break;
        case 13:
            printf("Rei de ");
            break;
        default:
            printf("%d de ", num); // Para números de 2 a 10
            break;
    }

    // Switch para o naipe da carta
    switch (naipe) {
        case 'o':
            printf("Ouros");
            break;
        case 'c':
            printf("Copas");
            break;
        case 'p':
            printf("Paus");
            break;
        case 'e':
            printf("Espadas");
            break;
        default:
            printf("Naipe desconhecido");
            break;
    }
    printf("\n");
}
//testar com outra coisa
int buscaCarta(PILHA* p){
	int num;
	int naipe;
	scanf("%d %c", &num, &naipe);
	REGISTRO reg;
	int count = 0;
	while(!estaVazia(p)){
		excluirElemPilha(p, &reg);
		if (reg.carta.numero == num && reg.carta.naipe == naipe){
			exibeCarta(num, naipe);
			return count++;
		}
		count++;
	}
	return -1; //a carta naõ foi encontrada	
}

void empilhaBaralho(PILHA* p){
	REGISTRO reg;
	char naipes[] = {'o', 'c', 'p', 'e'};
	for (int i = 0; i < 4; i++){
		for(int j = 1; j <= 13; j++){
			reg.carta.numero = j;
			reg.carta.naipe = naipes[i];
			inserirElemPilha(p, reg);
		}
	}
}

int main(){
	PILHA p;
	inicializarPilha(&p);
	empilhaBaralho(&p);
	int descart = buscaCarta(&p);
	if (descart == -1){
		printf("carta naõ encontrada");
	}
	else{
		printf("%d", descart);
	}
		
}

