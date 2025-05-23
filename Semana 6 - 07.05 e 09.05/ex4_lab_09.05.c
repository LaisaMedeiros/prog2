#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char nome[50];
    float P1;
    float P2;
    float T;
} Notas;

int main() {
    FILE *parq;
    char nome_arquivo[MAX];
    scanf("%s", nome_arquivo);
    
    int N;
    printf("Quantos alunos sao? ");
    scanf("%d", &N);
    
    Notas aluno;  // Agora é uma única variável, não um vetor
    
    // Abre o arquivo texto para escrita
    parq = fopen(nome_arquivo, "w");
    if (parq == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        // Lê os dados do aluno
        scanf("%s", aluno.nome);
        scanf("%f", &aluno.P1);
        scanf("%f", &aluno.P2);
        scanf("%f", &aluno.T);
        
        // Escreve imediatamente no arquivo
        fprintf(parq, "%s %.2f %.2f %.2f\n", aluno.nome, aluno.P1, aluno.P2, aluno.T);
    }
    
    fclose(parq);
    
    return 0;
}
