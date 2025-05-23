#include <stdio.h>

#define MAX 100

typedef struct {
    char nome[100];
    double nota[3];
    double media;
} Taluno;


 int main(){
 	
 	FILE *parq;
 	char nome_arq[MAX];
 	
 	printf("Insira o noem do arquivo binário:");
 	scanf("%s", nome_arq);
 	
 	parq = fopen(nome_arq, "rb+");
 	if (parq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
 	
 	Taluno Aluno;
 	int count = 0;
 	double media_nova = 0;
 	int tam = 0;
 	
 	while (fread(&Aluno, sizeof(Aluno), 1, parq) == 1){
 		// Exibe os dados atuais
        printf("\nAluno: %s\n", Aluno.nome);
        printf("Notas: %.2lf, %.2lf, %.2lf\n", Aluno.nota[0], Aluno.nota[1], Aluno.nota[2]);
        printf("Média atual: %.2lf\n", Aluno.media);
        
        // Calcula nova média ponderada
        media_nova = 0.25 * Aluno.nota[0] + 0.35 * Aluno.nota[1] + 0.4 * Aluno.nota[2];
		
		if (Aluno.media != media_nova){
			Aluno.media = media_nova;
			// Volta para a posição correta para atualizar a média
        	fseek(parq, -sizeof(double) , SEEK_CUR);
			fwrite(&Aluno.media, sizeof(double), 1, parq);
			count ++;
		}
		
		tam++;	
	}
 	
 	rewind(parq);
 	
 	while (fread(&Aluno, sizeof(Aluno), 1, parq) == 1){
 		// Exibe os dados atuais
        printf("\nAluno: %s\n", Aluno.nome);
        printf("Notas: %.2lf, %.2lf, %.2lf\n", Aluno.nota[0], Aluno.nota[1], Aluno.nota[2]);
        printf("Média atual: %.2lf\n", Aluno.media);
	}
 	
 	printf("Percentual de alunos com amedia atualizada: %.2f", ((double)count/tam)*100);
 	
 	fclose(parq);
    return 0;
 }
