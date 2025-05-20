#include <stdio.h>

#define MAX 50

int main(){
	
	FILE *parq1, *parq2;
	
	char arq_entrada[MAX];
	scanf("%s", arq_entrada);
	
	char arq_saida[MAX];
	scanf("%s", arq_saida);
	
	parq1 = fopen(arq_entrada, "r");
	parq2 = fopen(arq_saida, "w");
	if (parq1 == NULL || parq2 == NULL ){
		printf("Erro na abertura de arquivo");
	}
	
	char nome[50];
	float P1, P2, T;
	
	fscanf(parq1, "%s %f  %f %f", nome, &P1, &P2, &T);
	while (!feof(parq1)){
		float media = ((P1 +P2)/2)*0.8 + (T*0.2);
		fprintf(parq2, "%s %.2f\n", nome, media);
		fscanf(parq1, "%s %f  %f %f", nome, &P1, &P2, &T);
	}
	fclose(parq1);
	fclose(parq2);
}
