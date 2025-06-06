#include <stdio.h>   // Biblioteca padr�o de entrada e sa�da

#define MAX 50       // Define o tamanho m�ximo da fila (50 elementos)

#define true 1       // Define o valor l�gico verdadeiro como 1
#define false 0      // Define o valor l�gico falso como 0

typedef int bool;    // Define 'bool' como sin�nimo de 'int' para representar booleanos

typedef int TIPOCHAVE;  // Define o tipo da chave de cada elemento da fila (pode ser alterado futuramente)


// Estrutura que representa um elemento da fila
//A chave indentifica cada elemento da fila. Ela � usada para representar o conte�do que est� sendo
//armazenado ou manipulado � pode ser um n�mero, um c�digo, uma letra, etc., dependendo da aplica��o.
typedef struct {
    TIPOCHAVE chave;     // Cada elemento (registro) tem uma chave
} REGISTRO;


// Estrutura da fila est�tica
//nroElem + inicio = fim
//Se n�o h� elementos na fila coloca -1
typedef struct {
    REGISTRO A[MAX];     // Vetor fixo com os elementos da fila (tamanho m�ximo definido por MAX)
    int inicio;          // �ndice do primeiro elemento da fila (in�cio da fila)
    int nroElem;         // N�mero atual de elementos armazenados na fila
} FILA;

//inicializando a fila antes de fazer opera��es com ela
// o ponteiro � utilizado, pois estamos modificando diretamente os valores da fila dentro da fun��o
// se passar a fila sem ponteiro a mudan�a feita n�o altera a fila original
//Se n�o usar a fun��o altera a c�pia, mas a fila original fora da fun��o continua com lixo de mem�ria.
void inicializarFila(FILA* f) {
	f->inicio=0;      //valor no inicio
	f->nroElem=0;
}

int tamanhoFila(FILA* f){
	return f->nroElem;
}

void exibirFila(FILA* f) {
    
	printf("Fila: \" ");           // Imprime o in�cio da visualiza��o da fila
    int i = f->inicio;             // Come�a do �ndice onde est� o primeiro elemento da fila
    int temp;                      // Vari�vel auxiliar para o loop
    for (temp = 0; temp < f->nroElem; temp++) {  // Percorre a fila at� o n�mero total de elementos
        printf("%i ", f->A[i].chave);            // Imprime a chave (conte�do) do elemento atual
        i = (i + 1) % MAX;                       // Avan�a para o pr�ximo �ndice (forma circular)
    }
    printf("\"\n");               // Fecha a visualiza��o com aspas e quebra de linha
}

// Fun��o para inserir um elemento (registro) na fila est�tica
//  - REGISTRO reg: o registro que ser� inserido na fila
// Retorno:
//  - bool (true ou false): indica se a inser��o foi bem-sucedida (true) ou se a fila est� cheia e n�o d� para inserir (false)
bool inserirElementoFila(FILA* f, REGISTRO reg) {
    if (f->nroElem >= MAX)           // Se a fila j� est� cheia (n�mero de elementos atingiu o limite m�ximo)
        return false;                // Retorna false, pois n�o d� para inserir

    // Calcula a posi��o correta para inserir o novo elemento
    // (�ndice inicial + n�mero de elementos) m�dulo MAX para circularidade
    int posicao = (f->inicio + f->nroElem) % MAX;

    f->A[posicao] = reg;             // Insere o registro na posi��o calculada

    f->nroElem++;                    // Atualiza o n�mero de elementos da fila, pois inseriu um novo

    return true;                    // Retorna true para indicar que a inser��o foi feita com sucesso
}

// Fun��o para remover (excluir) o elemento do in�cio da fila
//  - REGISTRO* reg: ponteiro para um registro onde ser� guardado o elemento removido
bool excluirElementoFila(FILA* f, REGISTRO* reg) {
    if (f->nroElem == 0)          // Se a fila estiver vazia (n�o h� elementos para remover)
        return false;             // Retorna false indicando que n�o foi poss�vel remover

	//f->A � o vetor de registros dentro da fila.
	//f->inicio � o �ndice do primeiro elemento da fila (aquele que ser� removido).
	//Ent�o: f->A[f->inicio] � o registro que est� no in�cio da fila.
    *reg = f->A[f->inicio];      
    f->inicio = (f->inicio + 1) % MAX;  // Atualiza o �ndice do in�cio da fila para o pr�ximo elemento, com tratamento circular

    f->nroElem--;                 // Decrementa o n�mero de elementos da fila, pois um elemento foi removido

    return true;                  // Retorna true indicando que a remo��o foi realizada com sucesso
}

void reinicializarFila(FILA* f) {
	inicializarFila(f); 
}

