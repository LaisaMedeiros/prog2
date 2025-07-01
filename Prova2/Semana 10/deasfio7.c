#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

typedef struct{
	char nome[100];
	int t_chegada_cliente;
	int num_prod;
}CLIENTE;

typedef struct {
    CLIENTE cliente;
    //outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}
int tamanho(FILA* f) {
    ELEMENTO* end = f->inicio;
    int tam = 0;
    while (end != NULL) {
    tam++;
    end = end->prox; }
    return tam; 
}

void exibirFila(FILA* f) {
    ELEMENTO* end = f->inicio;
    printf("Fila: \" ");
    while (end != NULL) {
	    printf("%i ", end->reg.cliente);
	    end = end->prox; 
    }
    printf("\"\n"); 
}

bool inserirNaFila(FILA* f,REGISTRO reg) {
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio==NULL) return false;
    *reg = f->inicio->reg;
    ELEMENTO* apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL) f->fim = NULL;
    return true; 
}

void reinicializarFila(FILA* f) {
    ELEMENTO* end = f->inicio;
    while (end != NULL) {
    ELEMENTO* apagar = end;
    end = end->prox;
    free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main() {
    FILA f;
    inicializarFila(&f);
    int K, C;
    scanf("%d", &K);  // Tempo por produto (K)
    scanf("%d", &C);  // Número de clientes
    
    for (int i = 0; i < C; i++) {
        CLIENTE cliente;
        REGISTRO reg;
        scanf("%s %d %d", cliente.nome, &cliente.t_chegada_cliente, &cliente.num_prod);
        reg.cliente = cliente;
        inserirNaFila(&f, reg);
    }
    
    int tempo_atual = 0;
    REGISTRO reg;
    
    while (excluirDaFila(&f, &reg)) {
        CLIENTE c = reg.cliente;
        
        // O cliente começa a ser atendido quando chega OU quando o caixa fica livre
        int inicio_atendimento = (c.t_chegada_cliente > tempo_atual) ? c.t_chegada_cliente : tempo_atual;
        
        // Calcula o tempo de atendimento: 10 segundos fixos + produtos*K
        int tempo_saida = inicio_atendimento + 10 + (c.num_prod * K);
        
        printf("%s %d %d\n", c.nome, c.t_chegada_cliente, tempo_saida);
        
        tempo_atual = tempo_saida;
    }

    return 0;
}
