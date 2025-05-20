#include <stdio.h>
#include <stdlib.h>

// Função que usa stack
void usa_stack() {
    int vetor_stack[5] = {1, 2, 3, 4, 5};
    printf("?? Stack: Endereço do vetor_stack: %p\n", (void*)vetor_stack);
    for (int i = 0; i < 5; i++) {
        printf("vetor_stack[%d] = %d (endereço: %p)\n", i, vetor_stack[i], (void*)&vetor_stack[i]);
    }
}

// Função que usa heap
void usa_heap() {
    int* vetor_heap = malloc(5 * sizeof(int)); // alocação dinâmica
    if (vetor_heap == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        vetor_heap[i] = i + 10;
    }

    printf("?? Heap: Endereço do vetor_heap: %p\n", (void*)vetor_heap);
    for (int i = 0; i < 5; i++) {
        printf("vetor_heap[%d] = %d (endereço: %p)\n", i, vetor_heap[i], (void*)&vetor_heap[i]);
    }

    free(vetor_heap); // sempre liberar memória da heap!
}

int main() {
    usa_stack();
    printf("\n-------------------------\n\n");
    usa_heap();
    return 0;
}

