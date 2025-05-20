#include <stdio.h>
#include <string.h>

#define MAX 100
#define COL 80

int main(){
	
	FILE *parq;
	
	char nome_arquivo[MAX];
	printf("Insira o nome do arquivo:");
	scanf("%s", nome_arquivo);
	
	char padrao[MAX];
	printf("Insira o padrao à procurar:");
	scanf("%s", padrao);
	
	parq = fopen(nome_arquivo, "r");
	if(parq == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	//pede o numero de linhas ao usuario
	int L;
	printf("Insira a quantidade de linhas do arquivo:");
	scanf("%d", &L);
		
	int **linhas;
	linhas = (char **)malloc(L*sizeof(char *));
	for (int i = 0; i < L; i++){
		linhas[i] = (char *)malloc(COL*sizeof(char));
		fgets(linhas[i], COL, parq);
	}
	
	for (int i = 0; i < L; i ++){
		char *resultado = strstr(linhas[i], padrao);
		if (resultado != NULL){
			printf("%d %s", i, linhas[i]);
		}	
	}
	
	return 0;
}
