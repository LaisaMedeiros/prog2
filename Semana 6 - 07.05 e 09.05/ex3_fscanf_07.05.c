#include <stdio.h>
int main()
{
	char nome[50];
	float media;
	int i;
	
	FILE *parq;
	parq=fopen("teste.txt","r");
	if(parq==NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	i=0;
	while (!feof(parq)){
		printf("---%do. aluno\n",i+1);
		fscanf(parq,"%[A-Z a-z] %f\n", nome, &media);
		printf("Nome: %s – Media:%.1f\n",nome,media);
	
	i++;
	}
	fclose(parq);
	return 0;
}
