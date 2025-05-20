// Construir uma função inicM() que inicializa uma matriz quadrada com 9 elementos e
// outra função mostraM() que mostra os elementos dessa matriz.

#include <stdio.h>

#define DIM 3

void inicM(int s[][DIM]){
	
	int i , j;
	for (i = 0; i < DIM; i++){
		for (j = 0; j < DIM; j++){
			s[i][j] = 0;
		}
	}
}

void mostraM(int s[DIM][DIM]){
	
	int i , j;
	for (i = 0; i < DIM; i++){
		for (j = 0; j < DIM; j++){
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	
	int s[DIM][DIM];
	
	inicM(s);
	mostraM(s);
	
	return 0;
	
}
