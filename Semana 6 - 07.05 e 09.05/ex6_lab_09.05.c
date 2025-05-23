#include <stdio.h>      // Para entrada e sa�da
#include <string.h>     // Para manipula��o de strings (strstr, strlen, etc.)
#include <ctype.h>      // Para fun��es de caracteres, como tolower()

#define MAX 50          // Tamanho m�ximo para nome do arquivo e padr�o

int main() {
    
    FILE *parq;                      // Ponteiro para o arquivo

    char nome_arquivo[MAX];          // Vetor para armazenar o nome do arquivo
    scanf("%s", nome_arquivo);       // L� o nome do arquivo digitado pelo usu�rio

    char padrao[MAX];                // Vetor para armazenar o padr�o a ser buscado
    scanf("%s", padrao);             // L� o padr�o digitado pelo usu�rio

    // Converte o padr�o para min�sculo para fazer busca case-insensitive
    for (int i = 0; padrao[i]; i++) {
        padrao[i] = tolower((unsigned char)padrao[i]);
    }

    // Tenta abrir o arquivo no modo leitura
    parq = fopen(nome_arquivo, "r");
    if (parq == NULL) {
        printf("Erro ao abrir arquivo.\n");  // Mensagem de erro se n�o conseguir abrir
        return -1;                           // Encerra o programa com c�digo de erro
    }

    char linha[100];       // Vetor para armazenar cada linha lida do arquivo
    int count = 0;         // Contador de quantas vezes o padr�o foi encontrado

    // L� o arquivo linha por linha usando fgets
    while (fscanf(parq, "%[^\n]", linha)) == 1) {

        // Remove o caractere '\n' do final da linha, se existir
       fgetc(parq);

        // Converte a linha inteira para min�sculo
        for (int i = 0; linha[i]; i++) {
            linha[i] = tolower((unsigned char)linha[i]);
        }

        // Procura o padr�o dentro da linha, contando todas as ocorr�ncias
        char *ptr = linha;  // Ponteiro come�a no in�cio da linha
        //strstr retorna um ponteiro para a primeira posi��o onde come�a o padr�o na string
        //Como strstr s� enocntra a primeira ocorrencia � necessario que seja feito um loop para
        //encontrar outras ocorrencias na mesma linha
        while ((ptr = strstr(ptr, padrao)) != NULL) {
            count++;        // Incrementa o contador quando encontra o padr�o
            ptr++;          // Avan�a o ponteiro para continuar a busca (evita loop infinito)
        }
    }

    // Imprime o n�mero total de ocorr�ncias encontradas
    printf("%d\n", count);

    fclose(parq);  // Fecha o arquivo
    return 0;      // Encerra o programa com sucesso
}

