#include <stdio.h>
#include <stdlib.h>
//a função retorna um ponteiro de ponteiro
int **aloca_linhas(int L){
	
	int **matriz;
	matriz = (int **)malloc(L*sizeof(int *)); 
	
	if(!matriz){
		printf ("Erro de alocacao de memoria\n");
		return NULL;
	}
	
	return matriz;	
}

void aloca_colunas (int **matriz, int L, int COL){
	
	for (int i = 0; i < L; i++){
		matriz[i] = (int *)malloc(COL*sizeof(int));
	}
}


//*(matriz[i]) é o valor de matriz[i][0]
void le_dados(int **matriz, int L, int COL){
	
	for(int i = 0; i < L; i++){
		for(int j = 0; j < COL; j++){
			printf("Matriz[%d][%d]", i, j);
			scanf("%d", matriz[i] +j);
		}
	}
	
}

void imprime_matriz(int **matriz, int L, int COL){

	for (int i = 0; i < L; i++){
		for (int j =0; j < COL; j++){
			printf("%d ", *(matriz[i] + j));
		}
		printf("\n");
	}
	
}
void troca_linhas (int **matriz, int L1, int L2){
	
	int *salva = matriz[L1];
	matriz[L1] = matriz[L2];
	matriz[L2] = salva; 
}

int main (void) {
	
	int **matriz; //ou *matriz[lin]
	int lin, col;
	
	puts("Qual o numero de linhas?");
	scanf("%d",&lin);
	matriz = aloca_linhas(lin);
	
	puts("Qual o numero de colunas?");
	scanf("%d",&col);
	printf("Alocando espaço para linhas.\n");
	aloca_colunas(matriz, lin, col);
	
	le_dados(matriz, lin, col);
	imprime_matriz(matriz, lin, col);
	
	int linha1, linha2;
	puts("Qual a primeira linha a ser trocada?");
	scanf("%d",&linha1);
	if (linha1 < 0 || linha1 > (lin-1)){
		printf("Numéro inválido.");
		return -1;
	}
	if (linha2 < 0 || linha2 > (lin-1)){
		printf("Numéro inválido.");
		return -1;
	}
	puts("Qual a segunda linha a ser trocada?");
	scanf("%d",&linha2);
	troca_linhas(matriz, linha1, linha2);
	imprime_matriz(matriz, lin, col);
	return 0;
}
