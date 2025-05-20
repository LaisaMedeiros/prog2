#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define COL 50

int main(){
	
	FILE *parq1, *parq2;
	
	char arq_entrada[MAX];
	printf("Insira o nome do arquivo de entrada:");
	scanf("%s", arq_entrada);
	
	char arq_saida[MAX];
	printf("Insira o nome do arquivo de saida:");
	scanf("%s", arq_saida);
	
	//abrindo os dois arquivos
	parq1 = fopen(arq_entrada, "r");
	parq2 = fopen(arq_saida, "w");
	if (parq1 == NULL || parq2 == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	//Quantas linhas o arquivo tem
	int L;
	printf("Quantas linhas o arquivo de entrada tem?");
	scanf("%d", &L);
	
	//vetor de ponteiros para perocrer o arquivo
	char **linhas1;
	linhas1 = (char **)malloc(L*sizeof(char *));
	
	//Lendo o arquivo de entrada e guardando em cada linha da matriz
	for (int i = 0; i < L; i++){
		linhas1[i] = (char *)malloc(COL*sizeof(char *));
		fgets(linhas1[i], COL, parq1);
	}
	
	for(int i = 0; i<L; i++){
		for (int j = 0; linhas1[i][j] != '\0'; j++){
			linhas1[i][j] = toupper(linhas1[i][j]);
		}
		fputs(linhas1[i], parq2);
		printf("\n");
	}
	
	// Liberação e fechamento
    for (int i = 0; i < L; i++) {
        free(linhas1[i]);
    }

	fclose(parq1);
	fclose(parq2);
	
	return 0;	
}
