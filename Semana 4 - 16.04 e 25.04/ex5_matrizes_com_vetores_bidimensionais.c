#include <stdio.h>

int main(){
	int matriz[LIN][COL], i, j;
	//lendo os valores da matriz
	for (i = 0; i <LIN; i++){
		for(j = 0; j < COL; j++){
			printf("Matriz[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	//imprimindo a matriz
	for (i = 0; i < N; i++){
		for (j = 0; j < COL; j++){
			printf("[%d]", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
