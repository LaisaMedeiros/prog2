#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;
typedef char TIPOCHAVE;

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

int tamanho(PILHA* p) {
	
	PONT end = p->topo;
	int tam = 0;
	
	while (end != NULL) {
		tam++;
		end = end->prox;
	}
	
	return tam; 
}

bool estaVazia(PILHA* p) {
	if (p->topo == NULL){
		return true;
	}
    return false;
}

void exibirPilha(PILHA* p) {
	PONT end = p->topo;
	printf("Pilha: \" ");
	while (end != NULL) {
		printf("%i ", end->reg.chave);
		end = end->prox; 
	}
	printf("\"\n"); 
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

bool verificaPalindromo(PILHA *p, char palavra[], int tam){
	
	PONT end = p->topo;
	int i = 0;
	while (end != NULL){
		if(end->reg.chave != palavra[i]){
			printf("Nao e palindromo");
			reinicializarPilha(p);
			return false;
		}
		end = end->prox;
		i++;
	}
	printf("E palindromo");
	return true;
}

int main(){
	
	PILHA pilha;
	inicializarPilha(&pilha);
	
	char palavra[100];
	scanf("%s", palavra);
	
	REGISTRO reg;
	int tam = strlen(palavra);
	for (int i = 0; i < tam; i++){
		reg.chave = palavra[i];
		inserirElemPilha(&pilha, reg);
	}
	
	verificaPalindromo(&pilha, palavra, tam);
	
	return 0;
}

