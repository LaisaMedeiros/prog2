#include <stdio.h>
#include <ctype.h>

#define MAX 100
#define COL 100

int main() {
    char nome_arquivo[MAX];
    FILE *parq;
    
    printf("Insira o nome do arquivo:");
    scanf("%s", nome_arquivo);
    
    parq = fopen(nome_arquivo, "r");
    if (parq == NULL) {
        printf("Erro na abertura do arquivo");
        return -1;
    }
    
    char linha[COL];
    int letra_A = 0, letra_E = 0, letra_I = 0, letra_O = 0, letra_U = 0;
    
    // Usando fscanf para ler até encontrar \n ou EOF
    while (fscanf(parq, "%[^\n]", linha) != EOF) {
        // Consome o caractere \n do buffer
        fgetc(parq);
        
        for (int j = 0; linha[j] != '\0'; j++) {
            char c = tolower(linha[j]);
            if (c == 'a') letra_A++;
            if (c == 'e') letra_E++;
            if (c == 'i') letra_I++;
            if (c == 'o') letra_O++;
            if (c == 'u') letra_U++;
        }
    }
    
    fclose(parq);
    
    printf("a %d\n", letra_A);
    printf("e %d\n", letra_E);
    printf("i %d\n", letra_I);
    printf("o %d\n", letra_O);
    printf("u %d\n", letra_U);
    
    return 0;
}
