//Tanto o número de linhas como o número de colunas é desconhecido
//Criar um vetor de ponteiros que irá aramzenar o endereço inicial de cada linha
//USADO QUANDO O NÚMERO DE LINHAS SÓ É COMHECIDO EM TEMPO DE EXECUÇÃO
#include <stdio.h>

int main(){
	
	int i, j, L, C;
	//matriz inteira, linhas e colunas, é alocada dinamicamente
	int **matriz3;
	puts("Informe o numero de linhas e colunas");
	scanf("%d %d", &L, &C);
	
	//cria um vetor de ponteiros de tamanho L
	matriz3 = (int **) malloc(L * sizeof(int *));
	if(!matriz3){
		printf ("Erro de alocacao de memoria\n");
		return -1;
	}
	for (i=0; i<L; i++){
		*(matriz3 + i) = (int *) malloc (C * sizeof (int));
		if (! (*(matriz3 + i))){
			printf ("Erro de alocacao de memoria\n");
			return -1;
		}
	}
	
	for (i=0; i<L; i++){
		for (j=0; j<C; j++){
			printf ("Matriz[%d][%d]: ",i,j);
			scanf ("%d", *(matriz3 + i) + j);
		}

	}
	
	for (i=0; i<L; i++){
		for (j=0; j<C; j++)
			printf ("[%d] ", *(*(matriz3 + i) + j));
			
			printf("\n");
	}	
	
	return 0;
}

