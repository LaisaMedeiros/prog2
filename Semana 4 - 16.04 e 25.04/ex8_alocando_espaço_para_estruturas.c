#include <stdio.h>

typedef struct _ALUNO{
	char nome[40];
	float n1, n2, media;
} ALUNO;

int main (void){
	ALUNO *maria;
	maria = (ALUNO *) malloc (sizeof(ALUNO));
	if (!maria) exit(1);
	gets(maria->nome); //lê até o \n
	scanf("%f %f", &(maria->n1), &(maria->n2));
	maria->media = (maria->n1 + maria->n2)/2; //(*maria).media 
	printf("A media de %s vale %0.2f\n", maria->nome, maria->media);
	return 0;
}
