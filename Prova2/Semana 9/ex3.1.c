#include <stdio.h>
#include <stdlib.h>
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

bool ehPalindromo(PILHA* p){

	char s[100];
    scanf("%s", s);
    
    int i = 0;
    REGISTRO reg;
    while(s[i] != '\0'){
    	reg.chave = s[i];
    	inserirElemPilha(p, reg);
		i++	;
	}
	
	//desempilhando coma  função excluir
	for (int j = 0; excluirElemPilha(p, &reg); j++){
		if (s[j] != reg.chave){
			printf("Nao e palindromo");
			reinicializarPilha(p);
			return false;
		}
	}
	
	/*
	// Método 4: Percorrer pilha sem destruir (apenas ler) e verificar palíndromo
    
	ELEMENTO* end = p->topo;
    int i = 0;
    int len = strlen(s);
    
    while (end != NULL && i < len) {
        if (end->reg.chave != s[i]) {
            printf("Nao eh palindromo\n");
            return false;
        }
        end = end->prox;
        i++;  // Moved inside the loop
    }
    
    // Verifica se ambas as estruturas foram completamente percorridas
    if (end != NULL || i < len) {
        printf("Nao eh palindromo (tamanhos diferentes)\n");
        return false;
    }
    
    printf("Eh palindromo!\n");
    return true;
}
	*/
	
	//
	printf("Eh palindromo");
	return true;
}

int main(){
	PILHA p;
	inicializarPilha(&p);
	ehPalindromo(&p);
}
