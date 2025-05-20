#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[40];
	int ano_nasc;
	float renda;
} Tfunc;

Tfunc *inicializa(Tfunc *cad, int func){
	
	cad = (Tfunc *)malloc(func*sizeof(Tfunc));
	if (!cad){
		printf("Erro ao alocar memória.\n");
		return NULL;
	}
	for (int i = 0; i < func; i++){
		scanf("%s", (cad+i)->nome);
		scanf("%d", &((cad+i)->ano_nasc));
		scanf("%f", &((cad+i)->renda));
		//getchar();
	}
	
	return cad;
}
Tfunc *inclui_novos(Tfunc *cad, int func, int adc){
	
	cad = (Tfunc *)realloc(cad, (func + adc)*sizeof(Tfunc));
	if (!cad){
		printf("Erro ao realocar memória.\n");
        return NULL;	
	}
	for (int i = func; i < (adc + func); i++){
		getchar();
		scanf("%s", (cad+i)->nome);
		scanf("%d", &((cad+i)->ano_nasc));
		scanf("%f", &((cad+i)->renda));
		//getchar();
	}
	
	return cad;
}

void imprime(Tfunc *cad, int interv, int tot){
	
	for (int i = 0; i < tot; i++){
		printf("Nome", cad->nome);
		printf("Nascimento:", cad->ano_nasc );
		printf("Renda:", cad->renda);
	}
	
}

int main(void){
	
	Tfunc *cadastro;
	
	int funcionarios, adicionais;
	printf("Quantos funcionarios? ");
	scanf("%d",&funcionarios);
	cadastro = inicializa(cadastro, funcionarios);
	
	if (!cadastro){
		return -1;
	}
	
	printf("Quantos funcionarios a mais deseja adicionar? ");
	scanf("%d",&adicionais);
	cadastro = inclui_novos(cadastro, funcionarios, adicionais);
	if (!cadastro){
		return -1;
	}
	printf("Lista de funcionarios cadastrados\n");
	imprime(cadastro, 0, funcionarios+adicionais);
	free(cadastro);
	return 0;
	
}
