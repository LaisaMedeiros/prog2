#include <stdio.h>
#include <string.h>

#define MAX 50
#define COL 200

int main(){
	
	FILE *parq1, *parq2;
	
	char arq_entrada[MAX];
	scanf("%s", arq_entrada);
	
	char arq_saida[MAX];
	scanf("%s", arq_saida);
	
	parq1 = fopen(arq_entrada, "r");
	parq2 = fopen(arq_saida, "w");
	if (parq1 == NULL || parq2 == NULL){
		printf("Erro ao abrir o arquivo");
		return -1;
	}
	
	char linha1[COL];
	char linha2[COL];
	
	while (!feof(parq1)) {
    
		if (fgets(linha1, COL, parq1) == NULL) {
	        break; // sai se a leitura falhar
	    }
	
	    int tam = strlen(linha1);
	
	    // Remove '\n' se presente
	    if (linha1[tam - 1] == '\n') {
	        linha1[tam - 1] = '\0';
	        tam--;
	    }
	
	    for (int i = 0; i < tam; i++) {
	        linha2[i] = linha1[tam - 1 - i];
	    }
	    linha2[tam] = '\0';
	
	    fprintf(parq2, "%s\n", linha2);
}

	
	fclose(parq1);
	fclose(parq2);
	
	
	return 0;
}
