#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_origem, *arquivo_destino;
    char nome_origem[100], nome_destino[100];
    char c;

    // Solicita os nomes dos arquivos ao usuário
    printf("Digite o nome do arquivo de origem: ");
    scanf("%99s", nome_origem);
    
    printf("Digite o nome do arquivo de destino: ");
    scanf("%99s", nome_destino);

    // Abre o arquivo de origem para leitura
    arquivo_origem = fopen(nome_origem, "r");
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo de origem!\n");
        exit(1);
    }

    // Abre o arquivo de destino para escrita
    arquivo_destino = fopen(nome_destino, "w");
    if (arquivo_destino == NULL) {
        printf("Erro ao criar o arquivo de destino!\n");
        fclose(arquivo_origem);
        exit(1);
    }

    // Copia o conteúdo caractere por caractere
    while ((c = fgetc(arquivo_origem)) != EOF) {
        fputc(c, arquivo_destino);
    }

    // Fecha os arquivos
    fclose(arquivo_origem);
    fclose(arquivo_destino);

    printf("Arquivo copiado com sucesso!\n");

    return 0;
}
