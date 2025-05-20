#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 2


int main(){
	//aloca dinamicamente um vetor de 6 inteiros para os elementos da matriz
	//há um ponteiro só e ele vai apontando para cada elemento, um por vez. 
	int *matriz1 = (int *)malloc(LIN*COL*sizeof(int)), i, j;
	if(!matriz1){
		printf("Erro de alocação de memória\n");
		return -1;
	}
	
	for (i=0; i<LIN; i++){
		for (j=0; j <COL; j++){
			printf("Matriz[%d][%d]:", i, j);
			scanf("%d", matriz1+((i*COL)+j));
		}
	}
	
	for (i=0; i < LIN; i++){
		for (j=0; j < COL; j++){
			printf("[%d]", *(matriz1 + ((i*COL)+j)));
		}
		printf("\n");
	}
	free(matriz1);
	
	//Com vetores de ponteiros
	
	//Cada elemento de matriz2 será um ponteiro apontando para uma linha. há um ponteiro para cada linha. 
	//Como conhecemos o tamanho de LIN em tempo de compilação o vetor de ponteiros estará na stack
	int *matriz2[LIN];
	
	for (i=0; i<LIN; i++){
		
		//apenas as linhas são alocadas dinamicamente
		matriz2[i] = (int *)malloc(COL*sizeof(int));
		if (!matriz2[i]){
			printf("Erro de alocação de memória\n");
			return -1;
		}
	}
	for (i=0; i <LIN; i++){
		for (j=0; j < COL; j++){
			printf("Matriz[%d][%d]:", i, j);
			scanf("%d", matriz2[i] +j);
		}
	
	}
	
	for (i=0; i < LIN; i++){
		for (j=0; j < COL; j++){
			printf("[%d]", *(matriz2[i]+j));
		}
		printf("\n");
	}	
	
	return 0;
	
}


/* 
i = 0 -> 0*2 + 0 = 0;
i = 0 -> 0*2 + 1 = 1;
i = 1 -> 1*2 + 0 = 2;
i = 1 -> 1*2 + 1 = 3;
i = 2 -> 2*2 + 0 = 4;
i = 2 -> 2*2 + 1 = 5;
    
i =0 -> 	
	
*/
