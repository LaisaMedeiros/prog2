#include <stdio.h>      // Para entrada e saída
#include <string.h>     // Para manipulação de strings (strstr, strlen, etc.)
#include <ctype.h>      // Para funções de caracteres, como tolower()

#define MAX 50          // Tamanho máximo para nome do arquivo e padrão

int main() {
    
    FILE *parq;                      // Ponteiro para o arquivo

    char nome_arquivo[MAX];          // Vetor para armazenar o nome do arquivo
    scanf("%s", nome_arquivo);       // Lê o nome do arquivo digitado pelo usuário

    char padrao[MAX];                // Vetor para armazenar o padrão a ser buscado
    scanf("%s", padrao);             // Lê o padrão digitado pelo usuário

    // Converte o padrão para minúsculo para fazer busca case-insensitive
    for (int i = 0; padrao[i]; i++) {
        padrao[i] = tolower((unsigned char)padrao[i]);
    }

    // Tenta abrir o arquivo no modo leitura
    parq = fopen(nome_arquivo, "r");
    if (parq == NULL) {
        printf("Erro ao abrir arquivo.\n");  // Mensagem de erro se não conseguir abrir
        return -1;                           // Encerra o programa com código de erro
    }

    char linha[100];       // Vetor para armazenar cada linha lida do arquivo
    int count = 0;         // Contador de quantas vezes o padrão foi encontrado

    // Lê o arquivo linha por linha usando fgets
    while (fscanf(parq, "%[^\n]", linha)) == 1) {

        // Remove o caractere '\n' do final da linha, se existir
       fgetc(parq);

        // Converte a linha inteira para minúsculo
        for (int i = 0; linha[i]; i++) {
            linha[i] = tolower((unsigned char)linha[i]);
        }

        // Procura o padrão dentro da linha, contando todas as ocorrências
        char *ptr = linha;  // Ponteiro começa no início da linha
        //strstr retorna um ponteiro para a primeira posição onde começa o padrão na string
        //Como strstr só enocntra a primeira ocorrencia é necessario que seja feito um loop para
        //encontrar outras ocorrencias na mesma linha
        while ((ptr = strstr(ptr, padrao)) != NULL) {
            count++;        // Incrementa o contador quando encontra o padrão
            ptr++;          // Avança o ponteiro para continuar a busca (evita loop infinito)
        }
    }

    // Imprime o número total de ocorrências encontradas
    printf("%d\n", count);

    fclose(parq);  // Fecha o arquivo
    return 0;      // Encerra o programa com sucesso
}

