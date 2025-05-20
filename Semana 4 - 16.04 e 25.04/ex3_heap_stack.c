#include <stdio.h>
#include <stdlib.h>

// Fun��o que usa stack
void usa_stack() {
    int vetor_stack[5] = {1, 2, 3, 4, 5};
    printf("?? Stack: Endere�o do vetor_stack: %p\n", (void*)vetor_stack);
    for (int i = 0; i < 5; i++) {
        printf("vetor_stack[%d] = %d (endere�o: %p)\n", i, vetor_stack[i], (void*)&vetor_stack[i]);
    }
}

// Fun��o que usa heap
void usa_heap() {
    int* vetor_heap = malloc(5 * sizeof(int)); // aloca��o din�mica
    if (vetor_heap == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        vetor_heap[i] = i + 10;
    }

    printf("?? Heap: Endere�o do vetor_heap: %p\n", (void*)vetor_heap);
    for (int i = 0; i < 5; i++) {
        printf("vetor_heap[%d] = %d (endere�o: %p)\n", i, vetor_heap[i], (void*)&vetor_heap[i]);
    }

    free(vetor_heap); // sempre liberar mem�ria da heap!
}

int main() {
    usa_stack();
    printf("\n-------------------------\n\n");
    usa_heap();
    return 0;
}

