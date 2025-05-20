#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define COL 100

int main(){
	char nome_arquivo[MAX];
	FILE *parq;
	
	printf("Insira o nome do arquivo:");
	scanf("%s", nome_arquivo);
	
	parq = fopen(nome_arquivo, "r");
	if (parq == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	int L;
	printf("Quantas linhas o arquivo tem?");
	scanf("%d", &L);
	
	char **linhas;
	linhas = (char **)malloc(L*sizeof(char *));
	for (int i = 0; i < L; i++){
		linhas[i] = (char*)malloc(COL*sizeof(char));
	}
	//Le até o \n
	for (int i = 0; i<L; i++){
		fgets(linhas[i], COL, parq);
	}
	fclose(parq);
	
	//Contar vogais
	int letra_A = 0, letra_E = 0, letra_I = 0, letra_O = 0, letra_U = 0;
	for (int i = 0; i < L; i++){
		for (int j = 0; linhas[i][j] != '\0'; j++){
			if (tolower(*(linhas[i]+j))== 'a'){
				letra_A += 1;
			}
			if (tolower(*(linhas[i]+j))== 'e'){
				letra_E += 1;
			}
			if (tolower(*(linhas[i]+j))== 'i'){
				letra_I += 1;
			}
			if (tolower(*(linhas[i]+j))== 'o'){
				letra_O += 1;
			}
			if (tolower(*(linhas[i]+j))== 'u'){
				letra_U += 1;
			}
		}
	}
	
	printf("%d\n%d\n%d\n%d\n%d", letra_A, letra_E, letra_I, letra_O, letra_U);
	
	return 0;
	
}
