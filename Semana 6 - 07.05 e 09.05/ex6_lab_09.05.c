#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int main(){
	
	FILE *parq;
	
	char nome_arquivo[MAX];
	scanf("%s", nome_arquivo);
	
	char padrao[MAX];
	scanf("%s", padrao);
	
	parq = fopen(nome_arquivo, "r");
	if (parq == NULL){
		printf("Erro ao abrir arquivo.");
		return -1;
	}
	
	char linha[100];
	int count  = 0;
	
	while (!feof(parq)) {
        if (fscanf(parq, "%[^\n]", linha) == NULL) {
            break;
        }

        // Converter a linha para minúscula
        for (int i = 0; linha[i]; i++) {
            linha[i] = tolower((unsigned char)linha[i]);
        }

        // Procurar o padrão
        char *ptr = linha;
        while ((ptr = strstr(ptr, padrao)) != NULL) {
            count++;
            ptr++;  // avança o ponteiro para continuar procurando
        }
    }
	
	printf("%d", count);
	fclose(parq);
	return 0;
}
