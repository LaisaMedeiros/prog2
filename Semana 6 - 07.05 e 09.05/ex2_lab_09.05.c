#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main(int argc, char *argv[]){
	
	FILE *parq1, *parq2;
	
	if (argc < 3){
		return -1;
	}
	
	char *arq_entrada = argv[1];
	char *arq_saida = argv[2];
	
	//abrindo os dois arquivos
	parq1 = fopen(arq_entrada, "r");
	parq2 = fopen(arq_saida, "w");
	if (parq1 == NULL || parq2 == NULL){
		printf("Erro na abertura do arquivo");
		return -1;
	}
	
	//vetor de ponteiros para perocrer o arquivo
	char linha[MAX];  // Para armazenar a linha original

    // Lê linha por linha com fgets (forma segura)
    while (fscanf(parq1, "%[^\n]", linha) == 1) {

        fgetc(parq1);
		
        // Inverte a linha1 e guarda em linha2
        for (int i = 0; linha[i] != '\0'; i++) {
            linha[i] = toupper((unsigned char)linha[i]);
        }
        linha[tam] = '\0'; 

        // Escreve a linha invertida no arquivo de saída
        fprintf(parq2, "%s\n", linha);
    }

    // Fecha os arquivos
    fclose(parq1);
    fclose(parq2);


	fclose(parq1);
	fclose(parq2);
	
	return 0;	
}
