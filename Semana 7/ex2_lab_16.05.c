#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {
    FILE *pFile;
    char nome_arquivo[50];
    printf("Insira o nome do arquivo:");
    scanf("%49s", nome_arquivo);
    getchar();
    
    pFile = fopen(nome_arquivo, "wb");
    if (!pFile) {
        printf("Erro ao abrir arquivo");
        return -1;
    }
    
    int N;
    printf("Quantos alunos são?");
    scanf("%d", &N);
    getchar();
    
    Taluno aluno;  // Variável única para ler os dados temporariamente
    
    for (int i = 0; i < N; i++) {
        printf("\nAluno %d\n", i + 1);
        
        printf("Informe seu nome:");
        fgets(aluno.nome, 100, stdin);
        aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
        if (strcmp(aluno.nome, "") == 0) {
            fclose(pFile);
            return -1;
        }
        
        printf("Insira suas três notas:");
        scanf("%lf %lf %lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
        getchar();  // Limpa o buffer do teclado
        
        aluno.media = (aluno.nota[0] + aluno.nota[1] + aluno.nota[2]) / 3.0;
        
        fwrite(&aluno, sizeof(Taluno), 1, pFile);
        
        printf("Nova média: %.2lf\n", Aluno.media);
    }

    fclose(pFile);
    return 0;
}
