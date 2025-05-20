//Laísa Tatiana Oliveira de Medeiros

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int idade;
} Tpessoa;

int grava(FILE *pFile, int N) {
    Tpessoa pessoa;
    int cont = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%s %d", pessoa.nome, &pessoa.idade);
        if (fwrite(&pessoa, sizeof(Tpessoa), 1, pFile) != 1) {
            return cont;
        }
        cont++;
    }
    return cont;
}

int modifica(FILE *pFile, int M, int idade) {
    // Verifica se M está dentro do intervalo permitido
    fseek(pFile, 0, SEEK_END);
    long file_size = ftell(pFile);
    int total_records = file_size / sizeof(Tpessoa);
    
    if (M < 1 || M > total_records) {
        return -1;
    }
    
    // Posiciona no registro a ser modificado
    fseek(pFile, (M - 1) * sizeof(Tpessoa), SEEK_SET);
    
    Tpessoa pessoa;
    if (fread(&pessoa, sizeof(Tpessoa), 1, pFile) != 1) {
        return 0;
    }
    
    // Modifica a idade
    pessoa.idade = idade;
    
    // Volta para a posição do registro para escrever a modificação
    fseek(pFile, (M - 1) * sizeof(Tpessoa), SEEK_SET);
    
    if (fwrite(&pessoa, sizeof(Tpessoa), 1, pFile) != 1) {
        return 0;
    }
    
    return 1;
}

void exibe(FILE *pFile) {
    Tpessoa pessoa;
    
    // Volta para o início do arquivo
    rewind(pFile);
    
    while (fread(&pessoa, sizeof(Tpessoa), 1, pFile) == 1) {
        printf("%s - %d anos\n", pessoa.nome, pessoa.idade);
    }
}

int main() {
    FILE *pFile;
    int N, M, mod, idade;
    char nome_arquivo[101];
    
    fgets(nome_arquivo, 100, stdin); // nome do arquivo criado
    nome_arquivo[strlen(nome_arquivo)-1] = '\0';
    scanf("%d", &N); // numero de pessoas 
    
    pFile = fopen(nome_arquivo, "wb+");
    if (!pFile) {
        printf("Erro na criacao do arquivo...");
        return -1;
    }
    
    if (grava(pFile, N) != N) {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }
    
    scanf("%d", &M); // numero correspondente a ordem de entrada da pessoa que se deseja alterar a idade
    scanf("%d", &idade); // valor da idade a ser atualizado para a M-ésima pessoa
    
    mod = modifica(pFile, M, idade);
    if (mod == -1) {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }
    if (mod == 0) {
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }
    
    exibe(pFile);
    fclose(pFile);
    return 0;
}
