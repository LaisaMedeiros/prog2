#include <stdio.h>   // Para printf
#include <stdlib.h>  // Para malloc e free

int main() {
    int *aux, i;  // Declara um ponteiro para inteiro e uma variável inteira

    // Aloca dinamicamente memória para 4 inteiros (4 * sizeof(int))
    aux = (int *) malloc(4 * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (aux != NULL) {
        // Preenche os valores do vetor: 0, 5, 10, 15
        for(i = 0; i < 4; i++) {
            *(aux + i) = i * 5;   // Acessa e modifica a posição i do vetor
        }

        // Imprime os valores armazenados
        printf("Valores armazenados em aux:\n");
        for(i = 0; i < 4; i++) {
            printf("aux[%d] = %d\n", i, *(aux + i));
        }

        // Libera a memória alocada quando não for mais necessária
        free(aux);
    } else {
        printf("Erro ao alocar memória.\n");
    }

    return 0;
}

