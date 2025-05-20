#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;

Tfunc *inicializa(Tfunc *cadastro, int n) {
    cadastro = (Tfunc *)malloc(n * sizeof(Tfunc));
    if (!cadastro) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", (cadastro+i)->nome);
		scanf("%d", &((cadastro+i)->ano_nasc));
		scanf("%f", &((cadastro+i)->renda));
		getchar();
    }
    return cadastro;
}

Tfunc *inclui_novos(Tfunc *cadastro, int antigo_tam, int novos) {
    Tfunc *novo_cadastro = (Tfunc *)realloc(cadastro, (antigo_tam + novos) * sizeof(Tfunc));
    if (!novo_cadastro) {
        printf("Erro ao realocar memória.\n");
        return NULL;
    }

    for (int i = antigo_tam; i < antigo_tam + novos; i++) {
        printf("\nFuncionário %d:\n", i + 1);
       	scanf("%s", (novo_cadastro+i)->nome);
		scanf("%d", &((novo_cadastro+i)->ano_nasc));
		scanf("%f", &((novo_cadastro+i)->renda)); 
		getchar(); 
    }
    return novo_cadastro;
}

void imprime(Tfunc *cadastro, int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Ano de nascimento: %d\n", cadastro[i].ano_nasc);
        printf("Renda: %.2f\n", cadastro[i].renda);
    }
}

int main(void) {
   
    Tfunc *cadastro;
    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    while (scanf("%d", &funcionarios) != 1 || funcionarios <= 0) {
        printf("Número inválido. Digite novamente: ");
    }
    
    cadastro = inicializa(cadastro, funcionarios);
    if (!cadastro)
        return -1;

    printf("Quantos funcionarios a mais deseja adicionar? ");
    while (scanf("%d", &adicionais) != 1 || adicionais < 0) {
        printf("Número inválido. Digite novamente: ");
    }
    
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro) {
        return -1;
    }
    cadastro = temp;

    printf("\nLista de funcionarios cadastrados:\n");
    imprime(cadastro, 0, funcionarios + adicionais);

    free(cadastro);
    return 0;
}
