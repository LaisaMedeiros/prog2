#include <stdio.h>
#include <stdlib.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior) {
    int fim = tam - 1;
    int ini = 0;
    int pos = -1;  // Posição do elemento, se encontrado
    
    // Busca binária para encontrar o elemento ou posição de inserção
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        
        if (arr[meio] < el) {
            ini = meio + 1;
        } else if (arr[meio] > el) {
            fim = meio - 1;
        } else {
            pos = meio;  // Elemento encontrado
            break;
        }
    }
    
    // Se não encontrou o elemento, 'ini' indica a posição onde estaria
    if (pos == -1) {
        pos = ini;
    }
    
    // Calcula quantos elementos são menores que 'el'
    *menor = pos;
    
    // Calcula quantos elementos são maiores que 'el'
    *maior = tam - pos - (pos < tam && arr[pos] == el ? 1 : 0);
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    
    int el;
    printf("Digite o elemento de referencia: ");
    scanf("%d", &el);
    
    int *arr = (int *)malloc(tam * sizeof(int));
    printf("Digite os elementos do vetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
    }
    
    int menor, maior;
    buscaMenorMaiorBin(arr, tam, el, &menor, &maior);
    
    printf("Menor: %d - Maior: %d\n", menor, maior);
    
    free(arr);
    return 0;
}
