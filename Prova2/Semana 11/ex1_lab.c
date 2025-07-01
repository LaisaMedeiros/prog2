#include <stdio.h>

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant) {
	int i;
	for (i=0; i<tam; i++) {
		if (arr[i] >= el) {
			if ((arr[i] == el) && (*pos == -1)) {
				*pos = i; 
				*quant += 1;
			}
			else if ((arr[i] == el) && (*pos >= 0)) {
				*quant += 1;
			}
		}
	}
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
	
	
	int pos = -1;
	int quant = 0;  
	buscaSeqOrdRep(arr, tam, el, &pos, &quant);
	
	printf("Posiçao da primeira ocorrencia: %d\n", pos);
	printf("Quantidade de ocorrencias: %d\n", quant);
	
	return 0; 
}
