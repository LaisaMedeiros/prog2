//Al�me de um ponteiro para o elmento precisa de um ponteiro para o pr�ximo elemento
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

// Registro que vai guardar a informa��o da fila (aqui s� uma chave)
typedef struct {
	int chave;
	// outros campos que quiser adicionar
} REGISTRO;

// Estrutura de um elemento 
typedef struct aux {
	REGISTRO reg;         // dado armazenado no elemento
	struct aux* prox;     // ponteiro para o pr�ximo elemento da fila
} ELEMENTO;

// Estrutura da fila din�mica em si
typedef struct {
	ELEMENTO* inicio;     // ponteiro para o primeiro elemento da fila
	ELEMENTO* fim;        // ponteiro para o �ltimo elemento da fila
} FILA;

// Fun��o para calcular o tamanho (n�mero de elementos) da fila din�mica
int tamanho(FILA* f) {
    ELEMENTO* end = f->inicio;   // Come�a pelo primeiro elemento da fila
    int tam = 0;                 // Contador inicializado em zero

    while (end != NULL) {        // Enquanto n�o chegar no fim da lista (NULL)
        tam++;                  // Conta um elemento
        end = end->prox;        // Passa para o pr�ximo elemento
    }

    return tam;                  // Retorna o total contado
}

// Fun��o para exibir todos os elementos da fila din�mica
void exibirFila(FILA* f) {
    ELEMENTO* end = f->inicio;      // Come�a pelo primeiro elemento da fila

    printf("Fila: \" ");            // Imprime in�cio da visualiza��o da fila

    while (end != NULL) {           // Enquanto n�o chegar no final da fila
        printf("%i ", end->reg.chave);  // Imprime a chave do elemento atual
        end = end->prox;            // Passa para o pr�ximo elemento
    }

    printf("\"\n");                 // Fecha a visualiza��o com aspas e quebra de linha
}

// Fun��o para inserir um elemento no final da fila din�mica
// FILA* f: ponteiro para a fila a ser modificada
// REGISTRO reg: registro a ser inserido na fila
// Retorno:
//  - bool: retorna true sempre que a inser��o for realizada (pode-se melhorar para tratar falta de mem�ria)
bool inserirNaFila(FILA* f, REGISTRO reg) {
    // Aloca mem�ria para um novo elemento
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    
    novo->reg = reg;            // Copia o registro para o novo elemento
    novo->prox = NULL;          // Pr�ximo elemento � NULL pois ser� o �ltimo da fila

    if (f->inicio == NULL)      // Se a fila estiver vazia (sem elementos)
        f->inicio = novo;       // O novo elemento � o in�cio da fila
    else
        f->fim->prox = novo;    // Caso contr�rio, liga o �ltimo elemento atual ao novo

    f->fim = novo;              // Essa linha atualiza o ponteiro f->fim para apontar para o novo �ltimo elemento.
	//o ponteiro f->fim aponta para o mesmo endere�o que novo aponta.
    return true;                // Inser��o feita com sucesso
}

// Fun��o para remover o primeiro elemento da fila din�mica
// REGISTRO* reg: ponteiro para armazenar o registro removido
// Retorno bool: true se conseguiu remover, false se a fila estava vazia
bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio == NULL)        // Se a fila est� vazia, n�o tem o que remover
        return false;             // Retorna false para indicar falha

	//Para ser acesado fora da fun��o j� que reg n pode ser retorna pq � uma fun��o do tipo bool
    *reg = f->inicio->reg;        // Copia o registro do primeiro elemento para 'reg'

    ELEMENTO* apagar = f->inicio; // Guarda o endere�o do elemento que ser� removido

    f->inicio = f->inicio->prox;  // Atualiza o in�cio da fila para o pr�ximo elemento

    free(apagar);                 // Libera a mem�ria do elemento removido

    if (f->inicio == NULL)        // Se ap�s remover a fila ficou vazia
        f->fim = NULL;            // Atualiza o fim da fila para NULL tamb�m

    return true;                  // Remo��o feita com sucesso
}

// Fun��o para reinicializar (esvaziar) uma fila din�mica,
// liberando toda a mem�ria dos elementos e deixando a fila vazia.
void reinicializarFila(FILA* f) {
    ELEMENTO* end = f->inicio;    // Come�a pelo primeiro elemento da fila

    while (end != NULL) {         // Enquanto houver elemento na fila
        ELEMENTO* apagar = end;   // Guarda o endere�o do elemento atual para liberar
        end = end->prox;          // Vai para o pr�ximo elemento
        free(apagar);             // Libera a mem�ria do elemento atual
    }

    f->inicio = NULL;             // Depois de liberar tudo, fila fica vazia, inicio � NULL
    f->fim = NULL;                // Tamb�m atualiza fim para NULL, pois n�o h� elementos
}


