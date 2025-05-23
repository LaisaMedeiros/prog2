#include <stdio.h>
#include <string.h>

#define MAX 50      // Tamanho máximo do nome dos arquivos
#define COL 200     // Tamanho máximo de cada linha lida do arquivo

int main() {
    FILE *parq1, *parq2;

    char arq_entrada[MAX];   // Nome do arquivo de entrada
    char arq_saida[MAX];     // Nome do arquivo de saída

    // Lê o nome dos arquivos
    scanf("%s", arq_entrada);
    scanf("%s", arq_saida);

    // Abre os arquivos (leitura e escrita)
    parq1 = fopen(arq_entrada, "r");
    parq2 = fopen(arq_saida, "w");

    // Verifica se houve erro ao abrir os arquivos
    if (parq1 == NULL || parq2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    char linha1[COL];  // Para armazenar a linha original
    char linha2[COL];  // Para armazenar a linha invertida

    // Lê linha por linha com fgets (forma segura)
    while (fscanf(parq1, "%[^\n]", linha1) == 1) {

        fgetc(parq1);
		
		int tam = strlen(linha1);
		
        // Inverte a linha1 e guarda em linha2
        for (int i = 0; i < tam; i++) {
            linha2[i] = linha1[tam - 1 - i];
        }
        linha2[tam] = '\0';  // Finaliza a string invertida

        // Escreve a linha invertida no arquivo de saída
        fprintf(parq2, "%s\n", linha2);
    }

    // Fecha os arquivos
    fclose(parq1);
    fclose(parq2);

    return 0;
}

