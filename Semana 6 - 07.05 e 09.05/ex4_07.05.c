#include <stdio.h>

#define MAX 50

int main(){
	
	int N;
	float F;
	char c[MAX];
	
	FILE* parq;
	parq = fopen("meu_texto.txt", "r");
	
	if (parq == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	

	fscanf(parq,"%d", &N);
	fscanf(parq,"%f", &F);
	//um espaço no inicio diz que o scanf deve ignorar todos os caracteres em branco no inicio
	fscanf(parq, " %[^\n]", c);
	
	fclose(parq);
	
	printf("%d, %f, %s\n", N, F, c);
	
	return 0;
	
}
