#include <stdio.h>
#include <string.h>

#define MAX 81

int main(int argc, char *argv[]){
	
	FILE *parq;
	
	// Verifica se os argumentos foram passados corretamente
	if (argc != 3) {
        printf("Uso: %s \"padrao\" arquivo.txt\n", argv[0]);
        return -1;
    }
	
	char *padrao = argv[1];
    char *nome_arquivo = argv[2];
	
	parq = fopen(nome_arquivo, "r");
	if(parq == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
    
 	char linha[100];       // Vetor para armazenar cada linha lida do arquivo
	int count = 0;
    // Lê o arquivo linha por linha usando fgets
    while (fscanf(parq, "%[^\n]", linha) == 1) {
		
		count ++;
        // Remove o caractere '\n' do final da linha, se existir
       fgetc(parq);

        // Converte a linha inteira para minúsculo
        for (int i = 0; linha[i]; i++) {
            linha[i] = tolower((unsigned char)linha[i]);
        }

       	if (strstr(linha, padrao) != NULL){
       		printf("%d %s", count, linha);
		}	      
    }
	return 0;
}
