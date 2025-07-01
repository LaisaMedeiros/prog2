#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// outros campos...
} REGISTRO;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT inicio;
} LISTA;

void inicializarLista(LISTA* l){
	l->inicio = NULL;
}

int tamanho(LISTA* l) {
	PONT end = l->inicio;
	int tam = 0;
	while (end != NULL) {
		tam++;
		end = end->prox;
	}
	return tam; 
}

void exibirLista(LISTA* l) {
	PONT end = l->inicio;
	printf("Lista: \" ");
	while (end != NULL) {
		printf("%i ", end->reg.chave);
		end = end->prox; 
	}
	printf("\"\n"); 
}

bool insere(LISTA* l, REGISTRO reg, int pos) {
	if (pos<0 || pos>tamanho(l)) return false;
	ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	novo->reg = reg;
	int i;
	ELEMENTO* p;
	if (pos == 0){
		novo->prox = l->inicio;
		l->inicio = novo;
	}
	else{
		p = l->inicio;
		for (i=0;i<pos-1;i++) p = p->prox;
		novo->prox = p->prox;
		p->prox = novo;
	}
	return true; 
}

bool exclui(LISTA* l, int pos) {
	if (pos<0 || pos>tamanho(l)-1) return false;
	int i;
	ELEMENTO* p;
	ELEMENTO* apagar;
	if (pos == 0) {
		apagar = l->inicio;
		l->inicio = apagar->prox;
	}
	else {
		p = l->inicio;
		for (i=0;i<pos-1;i++) p = p->prox;
		apagar = p->prox;
		p->prox = apagar->prox; 
	}
	free(apagar);
	return true; 
}

void reinicializarLista(LISTA* l) {
	
	PONT end = l->inicio;
	
	while (end != NULL) {
		PONT apagar = end;
		end = end->prox;
		free(apagar); 
	}
	l->inicio = NULL;
}

//precisa de um ponteiro pos para percorre a lista1, pois como os elementos não são sequencias
// a ideia é encontrar o ultimo elemento da lists 1 para ligar o próximo dele ao inicio da lista 2

void concatenaListas(LISTA* L1, LISTA* L2){
	if (L1->inicio == NULL){
		L1->inicio = L2->inicio;
	}
	else {
		// faz com que o endereço de pos seja o proprrio l1
		ELEMENTO *pos = L1->inicio;
		while (pos->prox != NULL){
			pos = pos->prox;
		}
		// faz com que o prox de pos aponte para L2->inicio 
		pos->prox = L2->inicio;
		}
}

bool iguaisListas(LISTA* L1, LISTA *L2){
	
	if (L1->inicio == NULL && L2->inicio == NULL){
		return true;
	}
	
	if (tamanho(L1) != tamanho(L2)){
		return false;
	}
	
	ELEMENTO* ini1 = L1->inicio;
	ELEMENTO* ini2 = L2->inicio;

	while (ini1 != 0 && ini2 !=0){
		if (ini1->reg.chave != ini2->reg.chave){
			return false;
		}
		ini1 = ini1->prox;
		ini2 = ini2->prox;
	}
	return true;	
}

bool modificaElem(LISTA* L, REGISTRO reg, int pos){
	
	//verifica se a lista é vazia
	if (L->inicio == NULL){
		return false;
	}
	ELEMENTO *atual = L->inicio;
	int i = 0;
	while (atual != NULL){
		if (pos == i){
			atual->reg = reg;
			return true;	
		}
		atual = atual->prox;
		i++;
	}	
	return false;
}

int main(){

    LISTA L1, L2;
    inicializarLista(&L1);
    inicializarLista(&L2);
    
    iguaisListas(&L1, &L2);
    
    return 0;
}
