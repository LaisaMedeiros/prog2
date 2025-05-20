#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "exemplo.txt";
    char linha[100];

    // Cria ou abre o arquivo para leitura e escrita
    arquivo = fopen(nome_arquivo, "w+");
    if (arquivo == NULL) {
        printf("Erro ao criar/abrir o arquivo!\n");
        exit(1);
    }

    // Escreve algumas linhas no arquivo
    fprintf(arquivo, "Primeira linha\n");
    fprintf(arquivo, "Segunda linha\n");
    fprintf(arquivo, "Terceira linha\n");

    // Volta ao início do arquivo com rewind()
    rewind(arquivo);

    // Lê e exibe o conteúdo pela primeira vez
    printf("Conteúdo do arquivo (primeira leitura):\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Usa rewind() para ler o arquivo novamente
    rewind(arquivo);

    // Lê e exibe o conteúdo pela segunda vez
    printf("\nConteúdo do arquivo (segunda leitura):\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Adiciona uma nova linha no final
    fprintf(arquivo, "Quarta linha (adicionada depois)\n");

    // Fecha o arquivo
    fclose(arquivo);

    printf("\nOperações concluídas. Verifique o arquivo '%s'.\n", nome_arquivo);

    return 0;
}
