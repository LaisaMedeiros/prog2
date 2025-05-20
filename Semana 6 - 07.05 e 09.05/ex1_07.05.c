#include <stdio.h>
#define NUMALUNOS 5
int main()
{
	char nome[50];
	float media;
	int i;
	FILE *parq;
	parq=fopen("teste.txt","w");
	if(parq==NULL)
	{
	printf("Erro na
	abertura do arquivo");
	return -1;
	}
	
	for(i=0;i<NUMALUNOS;i++)
	{
	
	printf("---%do. aluno\n",i+1);
	printf("Nome: ");
	gets(nome);
	printf("Media: ");
	scanf("%f",&media);
	fprintf(parq,"%s %f\n",nome,
	
	media);
	
	getchar();
	
	}
	fclose(parq);
	return;

}


