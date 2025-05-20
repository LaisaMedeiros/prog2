#include <stdio.h>

#define MAX 50

int main(){
	
	int N = 10;
	float F = 0.2;
	char c[MAX] = "Ciencia da Computacao";
	
	FILE* parq;
	parq = fopen("meu_texto.txt", "w");
	if (parq == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	fprintf(parq, "%d\n%f\n%s", N, F, c);
	
	fclose(parq);
	return 0;
}
