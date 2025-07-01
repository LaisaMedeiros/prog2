#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//O resto da divisão de N por 2 vai ser colocado em uma pilha

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	//outros campos...
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

void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    while (end != NULL) {
        printf("%i", end->reg.chave);
        end = end->prox;
    }
    printf("\n");
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

void reinicializarPilha(PILHA* p) {
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

void imprimeBinario(PILHA *pilha, int N){
	// Aqui 'pilha' já é um ponteiro não precisa user endereço
	
	REGISTRO resto;
    //A cada divisão por dois insere o elemento na pilha
    while(N > 0){
    	resto.chave = N%2;
    	inserirElemPilha(pilha, resto);
    	N = N/2;
	}
	
	/*while (excluirElemPilha(pilha, &resto)) {
        printf("%d", resto.chave);
    }
    printf("\n");*/
    
    exibirPilha(pilha);
	
}

int main(){
	
	int N;
	scanf("%d", &N);
	
	PILHA pilha; // Variável do tipo PILHA
	imprimeBinario(&pilha, N); // Passa o endereço da pilha
    
    imprimeBinario(&pilha, N);
    
	return 0;
}
