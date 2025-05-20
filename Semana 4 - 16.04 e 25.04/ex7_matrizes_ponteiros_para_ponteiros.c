//Tanto o n�mero de linhas como o n�mero de colunas � desconhecido
//Criar um vetor de ponteiros que ir� aramzenar o endere�o inicial de cada linha
//USADO QUANDO O N�MERO DE LINHAS S� � COMHECIDO EM TEMPO DE EXECU��O
#include <stdio.h>

int main(){
	
	int i, j, L, C;
	//matriz inteira, linhas e colunas, � alocada dinamicamente
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

