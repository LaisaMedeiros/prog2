// Construir uma função inicM() que inicializa uma matriz quadrada com 9 elementos e
// outra função mostraM() que mostra os elementos dessa matriz.

#include <stdio.h>

#define DIM 3

void inicM(int (*ptr)[DIM]){ //ptr é um ponteiro para um array (linha) de DIM inteiros
// ptr aponta para a primeira linha
	
	for (int i = 0; i < DIM; i++){
		for (int j = 0; j < DIM; j++){
		*(*(ptr + i)+j) = 0;
		}
	}
}

void mostraM(int (*ptr)[DIM]){
	
	int i , j;
	for (i = 0; i < DIM; i++){
		for (j = 0; j < DIM; j++){
			printf("%d ", *(*(ptr+i)+j));
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
