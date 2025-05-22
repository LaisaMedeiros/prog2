#include <stdio.h>
int main(int argc, char *argv[]){
	
	FILE *arq; 
	int cont = 0;
	
	if(argc < 2) {
		puts("Digite <nome programa> <arquivo de texto>");
		return -1; 
	}
	
	arq = fopen(argv[1], "r");
	if(arq==NULL) {
		puts("erro ao abrir o arquivo");
		return -1;
	}
	
	fseek(arq, 0, SEEK_END);
	//ftell retorna posicao atual do indicador do arquivo
	cont = ftell(arq);
	fclose(arq);
	printf("O arquivo possui %d caracteres\n", cont);
	return 0;
}
