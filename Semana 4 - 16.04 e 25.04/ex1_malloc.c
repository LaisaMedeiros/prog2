#include <stdio.h>   // Para printf
#include <stdlib.h>  // Para malloc e free

int main() {
    int *aux, i;  // Declara um ponteiro para inteiro e uma vari�vel inteira

    // Aloca dinamicamente mem�ria para 4 inteiros (4 * sizeof(int))
    aux = (int *) malloc(4 * sizeof(int));

    // Verifica se a aloca��o foi bem-sucedida
    if (aux != NULL) {
        // Preenche os valores do vetor: 0, 5, 10, 15
        for(i = 0; i < 4; i++) {
            *(aux + i) = i * 5;   // Acessa e modifica a posi��o i do vetor
        }

        // Imprime os valores armazenados
        printf("Valores armazenados em aux:\n");
        for(i = 0; i < 4; i++) {
            printf("aux[%d] = %d\n", i, *(aux + i));
        }

        // Libera a mem�ria alocada quando n�o for mais necess�ria
        free(aux);
    } else {
        printf("Erro ao alocar mem�ria.\n");
    }

    return 0;
}

