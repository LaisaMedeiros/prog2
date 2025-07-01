#include <stdio.h>   // Biblioteca padrão de entrada e saída

#define MAX 50       // Define o tamanho máximo da fila (50 elementos)

#define true 1       // Define o valor lógico verdadeiro como 1
#define false 0      // Define o valor lógico falso como 0

typedef int bool;    // Define 'bool' como sinônimo de 'int' para representar booleanos

typedef int TIPOCHAVE;  // Define o tipo da chave de cada elemento da fila (pode ser alterado futuramente)


// Estrutura que representa um elemento da fila
//A chave indentifica cada elemento da fila. Ela é usada para representar o conteúdo que está sendo
//armazenado ou manipulado — pode ser um número, um código, uma letra, etc., dependendo da aplicação.
typedef struct {
    TIPOCHAVE chave;     // Cada elemento (registro) tem uma chave
} REGISTRO;


// Estrutura da fila estática
//nroElem + inicio = fim
//Se não há elementos na fila coloca -1
typedef struct {
    REGISTRO A[MAX];     // Vetor fixo com os elementos da fila (tamanho máximo definido por MAX)
    int inicio;          // Índice do primeiro elemento da fila (início da fila)
    int nroElem;         // Número atual de elementos armazenados na fila
} FILA;

//inicializando a fila antes de fazer operações com ela
// o ponteiro é utilizado, pois estamos modificando diretamente os valores da fila dentro da função
// se passar a fila sem ponteiro a mudança feita não altera a fila original
//Se não usar a função altera a cópia, mas a fila original fora da função continua com lixo de memória.
void inicializarFila(FILA* f) {
	f->inicio=0;      //valor no inicio
	f->nroElem=0;
}

int tamanhoFila(FILA* f){
	return f->nroElem;
}

void exibirFila(FILA* f) {
    
	printf("Fila: \" ");           // Imprime o início da visualização da fila
    int i = f->inicio;             // Começa do índice onde está o primeiro elemento da fila
    int temp;                      // Variável auxiliar para o loop
    for (temp = 0; temp < f->nroElem; temp++) {  // Percorre a fila até o número total de elementos
        printf("%i ", f->A[i].chave);            // Imprime a chave (conteúdo) do elemento atual
        i = (i + 1) % MAX;                       // Avança para o próximo índice (forma circular)
    }
    printf("\"\n");               // Fecha a visualização com aspas e quebra de linha
}

// Função para inserir um elemento (registro) na fila estática
//  - REGISTRO reg: o registro que será inserido na fila
// Retorno:
//  - bool (true ou false): indica se a inserção foi bem-sucedida (true) ou se a fila está cheia e não dá para inserir (false)
bool inserirElementoFila(FILA* f, REGISTRO reg) {
    if (f->nroElem >= MAX)           // Se a fila já está cheia (número de elementos atingiu o limite máximo)
        return false;                // Retorna false, pois não dá para inserir

    // Calcula a posição correta para inserir o novo elemento
    // (índice inicial + número de elementos) módulo MAX para circularidade
    int posicao = (f->inicio + f->nroElem) % MAX;

    f->A[posicao] = reg;             // Insere o registro na posição calculada

    f->nroElem++;                    // Atualiza o número de elementos da fila, pois inseriu um novo

    return true;                    // Retorna true para indicar que a inserção foi feita com sucesso
}

// Função para remover (excluir) o elemento do início da fila
//  - REGISTRO* reg: ponteiro para um registro onde será guardado o elemento removido
bool excluirElementoFila(FILA* f, REGISTRO* reg) {
    if (f->nroElem == 0)          // Se a fila estiver vazia (não há elementos para remover)
        return false;             // Retorna false indicando que não foi possível remover

	//f->A é o vetor de registros dentro da fila.
	//f->inicio é o índice do primeiro elemento da fila (aquele que será removido).
	//Então: f->A[f->inicio] é o registro que está no início da fila.
    *reg = f->A[f->inicio];      
    f->inicio = (f->inicio + 1) % MAX;  // Atualiza o índice do início da fila para o próximo elemento, com tratamento circular

    f->nroElem--;                 // Decrementa o número de elementos da fila, pois um elemento foi removido

    return true;                  // Retorna true indicando que a remoção foi realizada com sucesso
}

void reinicializarFila(FILA* f) {
	inicializarFila(f); 
}

