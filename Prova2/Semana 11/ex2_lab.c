#include <stdio.h>

int buscaBin(int arr[], int tam, int el) {
    int fim = tam - 1;
    int ini = 0;
    int iteracao = 1;
    
    while (ini <= fim) {
        int meio = (fim + ini) / 2;
        
        if (arr[meio] < el) {
            // Descartamos da posição ini até meio (inclusive)
            printf("%da. iteracao: %d\n", iteracao, meio - ini+1);
            ini = meio + 1;
        }
        else if (arr[meio] > el) {
            // Descartamos da posição meio até fim (inclusive)
            printf("%da. iteracao: %d\n", iteracao, fim - meio+1);
            fim = meio - 1;
        }
        else if (arr[meio] == el && iteracao == 1){
        	printf("%da. iteracao:%d\n", iteracao, 0);
            return 0;  // Elemento encontrado
        }
        else if (arr[meio] == el && iteracao > 1){
        	printf("%da. iteracao:%d\n", iteracao, fim-ini);
            return 0;  // Elemento encontrado
        }
        
        iteracao++;
    }
    
    return -1;  // Elemento não encontrado
}

int main(){
	
	int tam;
	printf("Digite a quantidade de elementos do vetor:");
	scanf("%d", &tam);
	
	int arr[tam];
	printf("Digite os elementos do vetor:");
	for (int i = 0; i < tam; i++){
		scanf("%d", &arr[i]);
	}
	
	int el;
	printf("Digite o elemento procurado:");
	scanf("%d", &el);
	
	buscaBin(arr, tam, el); 
	
	return 0;
}
