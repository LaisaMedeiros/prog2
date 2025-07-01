#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;
typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;
typedef ELEMENTO *PONT;
typedef struct
{
    PONT topo;
} PILHA;
void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}
bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}
bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
    if (p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}
void reinicializarPilha(PILHA *p)
{
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL)
    {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

void calcula_notacao(PILHA *p, char operador){
	
	REGISTRO reg1, reg2, reg3;
	excluirElemPilha(p, &reg2);
	excluirElemPilha(p, &reg1);
	switch(operador){
		case '*':
			reg3.chave = reg1.chave * reg2.chave;
			printf("%d * %d = %d\n", reg1.chave, reg2.chave, reg3.chave);
			break;
		case '+':
			reg3.chave = reg1.chave + reg2.chave;
			printf("%d + %d = %d\n", reg1.chave, reg2.chave, reg3.chave);
			break;
		case '-':
			reg3.chave = reg1.chave - reg2.chave;
			printf("%d - %d = %d\n", reg1.chave, reg2.chave, reg3.chave);
			break;
	}
	inserirElemPilha(p, reg3);
}

void le_notacao(PILHA* p){

	char s[100];
    fgets(s, 100, stdin);
    
    int i = 0;
    REGISTRO reg;
    while(s[i] != '\0'){
    	
    	if (s[i] != ' '){
	    	if (s[i] >= '0' && s[i] <= '9'){
	    		reg.chave = s[i] - '0';
	    		inserirElemPilha(p, reg);
			}
			else{
				calcula_notacao(p, s[i]);	
			}
		}
		i++;
	}
	if (p->topo != NULL){
		excluirElemPilha(p, &reg);
		printf("Resultado: %d\n", reg.chave);
		reinicializarPilha(p);
	}
	
}

int main(){
	PILHA p;
	inicializarPilha(&p);
	le_notacao(&p);
}
