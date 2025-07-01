#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

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

void calcula(char operador, char v[], PILHA* p){
	
	REGISTRO reg1, reg2, reg3;
	
	switch (operador){
		case '*':
			excluirElemPilha(p, &reg1);
			excluirElemPilha(p, &reg2);
			reg3.chave = reg2.chave * reg1.chave;
			printf("%d * %d = %d\n", reg2.chave, reg1.chave, reg3.chave);
			break;
		case '+':
			excluirElemPilha(p, &reg1);
			excluirElemPilha(p, &reg2);
			reg3.chave = reg2.chave + reg1.chave;
			printf("%d + %d = %d\n", reg2.chave, reg1.chave, reg3.chave);
			break;
		case '-':
			excluirElemPilha(p, &reg1);
			excluirElemPilha(p, &reg2);
			reg3.chave = reg2.chave - reg1.chave;
			printf("%d - %d = %d\n", reg2.chave, reg1.chave, reg3.chave);
			break;
	}
	
	inserirElemPilha(p, reg3);
	
}

void realizaOperacoes(PILHA* p, char v[]){
	
	PONT end = p->topo;
	REGISTRO reg;
	
	int tam = strlen(v);
	int i = 0;
	while(v[i] != '\0') {
		if (v[i] == ' '){
			i++;
			continue;
		}
		if (v[i] >= '0' && v[i] <='9'){
			reg.chave = v[i] - '0';
			inserirElemPilha(p, reg);
		}
		else{
			char operador = v[i];
			calcula(operador, v, p);
		}
		i++;
	}
	
}

int main(){
	
	PILHA pilha;
	inicializarPilha(&pilha);
	
	//A  notação pos fixada em um arquivo texto está em forma de string
	char v_teste[] = "6 5 2 3 + 8 * - 3 + *";
	
	/*
	pilha.topo: aponta para o elemento do topo da pilha
	pilha.topo->reg: é a estrutura REGISTRO armazenada
	pilha.topo->reg.chave: é o valor inteiro que você quer acessar
	não pode ser pilha.topo.reg.chave por que pilha.topo é um ponteiro PONT (ELEMENTO*)
	e não pode acessar o campo reg de um ponteiro usando .
	*/
	
	realizaOperacoes(&pilha, v_teste);
	printf("Resultado: %d\n", pilha.topo->reg.chave);
	return 0;
}


