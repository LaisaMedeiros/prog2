#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
	char nome[50];
	float P1;
	float P2;
	float T;
}Notas;

int main(){
	
	FILE *parq;
	char nome_arquivo[MAX];
	scanf("%s", nome_arquivo);
	
	int N;
	printf("Quantos alunos sao?");
	scanf("%d", &N);
	
	//Aluno é um ponteiro para uma struct do tipo Notas, não um vetor de ponteiros
	Notas *Aluno;
	Aluno = (Notas *)malloc(N*sizeof(Notas));
	for (int i = 0; i < N; i++){
		scanf("%s", (Aluno + i)->nome);
		scanf("%f", &((Aluno + i)->P1));
		scanf("%f", &((Aluno + i)->P2));
		scanf("%f", &((Aluno + i)->T));
	}
	
	//abre o arquivo texto
	parq = fopen(nome_arquivo, "w");
	if (parq == NULL){
		printf("Erro ao abrir o arquivo.");
	}
	for(int i = 0; i < N; i++){
		fprintf(parq, "%s %.2f %.2f %.2f\n", (Aluno + i)->nome, (Aluno + i)->P1, (Aluno + i)->P2, (Aluno + i)->T);
	}
	fclose(parq);
	
	return 0;
}
