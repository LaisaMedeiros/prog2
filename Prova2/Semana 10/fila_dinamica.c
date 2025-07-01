//Al´me de um ponteiro para o elmento precisa de um ponteiro para o próximo elemento
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

// Registro que vai guardar a informação da fila (aqui só uma chave)
typedef struct {
	int chave;
	// outros campos que quiser adicionar
} REGISTRO;

// Estrutura de um elemento 
typedef struct aux {
	REGISTRO reg;         // dado armazenado no elemento
	struct aux* prox;     // ponteiro para o próximo elemento da fila
} ELEMENTO;

// Estrutura da fila dinâmica em si
typedef struct {
	ELEMENTO* inicio;     // ponteiro para o primeiro elemento da fila
	ELEMENTO* fim;        // ponteiro para o último elemento da fila
} FILA;

// Função para calcular o tamanho (número de elementos) da fila dinâmica
int tamanho(FILA* f) {
    ELEMENTO* end = f->inicio;   // Começa pelo primeiro elemento da fila
    int tam = 0;                 // Contador inicializado em zero

    while (end != NULL) {        // Enquanto não chegar no fim da lista (NULL)
        tam++;                  // Conta um elemento
        end = end->prox;        // Passa para o próximo elemento
    }

    return tam;                  // Retorna o total contado
}

// Função para exibir todos os elementos da fila dinâmica
void exibirFila(FILA* f) {
    ELEMENTO* end = f->inicio;      // Começa pelo primeiro elemento da fila

    printf("Fila: \" ");            // Imprime início da visualização da fila

    while (end != NULL) {           // Enquanto não chegar no final da fila
        printf("%i ", end->reg.chave);  // Imprime a chave do elemento atual
        end = end->prox;            // Passa para o próximo elemento
    }

    printf("\"\n");                 // Fecha a visualização com aspas e quebra de linha
}

// Função para inserir um elemento no final da fila dinâmica
// FILA* f: ponteiro para a fila a ser modificada
// REGISTRO reg: registro a ser inserido na fila
// Retorno:
//  - bool: retorna true sempre que a inserção for realizada (pode-se melhorar para tratar falta de memória)
bool inserirNaFila(FILA* f, REGISTRO reg) {
    // Aloca memória para um novo elemento
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    
    novo->reg = reg;            // Copia o registro para o novo elemento
    novo->prox = NULL;          // Próximo elemento é NULL pois será o último da fila

    if (f->inicio == NULL)      // Se a fila estiver vazia (sem elementos)
        f->inicio = novo;       // O novo elemento é o início da fila
    else
        f->fim->prox = novo;    // Caso contrário, liga o último elemento atual ao novo

    f->fim = novo;              // Essa linha atualiza o ponteiro f->fim para apontar para o novo último elemento.
	//o ponteiro f->fim aponta para o mesmo endereço que novo aponta.
    return true;                // Inserção feita com sucesso
}

// Função para remover o primeiro elemento da fila dinâmica
// REGISTRO* reg: ponteiro para armazenar o registro removido
// Retorno bool: true se conseguiu remover, false se a fila estava vazia
bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio == NULL)        // Se a fila está vazia, não tem o que remover
        return false;             // Retorna false para indicar falha

	//Para ser acesado fora da função já que reg n pode ser retorna pq é uma função do tipo bool
    *reg = f->inicio->reg;        // Copia o registro do primeiro elemento para 'reg'

    ELEMENTO* apagar = f->inicio; // Guarda o endereço do elemento que será removido

    f->inicio = f->inicio->prox;  // Atualiza o início da fila para o próximo elemento

    free(apagar);                 // Libera a memória do elemento removido

    if (f->inicio == NULL)        // Se após remover a fila ficou vazia
        f->fim = NULL;            // Atualiza o fim da fila para NULL também

    return true;                  // Remoção feita com sucesso
}

// Função para reinicializar (esvaziar) uma fila dinâmica,
// liberando toda a memória dos elementos e deixando a fila vazia.
void reinicializarFila(FILA* f) {
    ELEMENTO* end = f->inicio;    // Começa pelo primeiro elemento da fila

    while (end != NULL) {         // Enquanto houver elemento na fila
        ELEMENTO* apagar = end;   // Guarda o endereço do elemento atual para liberar
        end = end->prox;          // Vai para o próximo elemento
        free(apagar);             // Libera a memória do elemento atual
    }

    f->inicio = NULL;             // Depois de liberar tudo, fila fica vazia, inicio é NULL
    f->fim = NULL;                // Também atualiza fim para NULL, pois não há elementos
}


