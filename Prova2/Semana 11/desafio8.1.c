#include <stdio.h>
#include <stdlib.h>

//Fazendo o desafio 8 de novo

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior){
	int fim = tam-1;
	int ini = 0;
	int pos = -1;
	while (ini <= fim) {
		int meio = (fim + ini)/2;
		if (arr[meio] < el){
			ini = meio + 1;
		}
		else if(arr[meio] > el){
				fim = meio - 1;
		}
		else{
			pos = meio;
			break;
		}	
	}
	
	if (pos == -1){
		*menor = ini;
		*maior = tam - ini;
	}
	else{
		*menor = pos;
		*maior = tam - pos -1;
	}
	
}


int main(){
	
	int tam;
	scanf("%d", &tam);
	
	int el;
	scanf("%d", &el);
	
	int *arr = (int *)malloc(tam * sizeof(int));
	if (arr == NULL){
		return 1;
	}
	for(int i = 0; i < tam; i++){
		scanf("%d", &arr[i]);
	}
	
	int maior = 0;
	int menor = 0;
	buscaMenorMaiorBin(arr, tam, el, &menor, &maior);
	
	printf("Menor: %d - Maior: %d", menor, maior);
	free(arr);
	return 0;
	return 0;
}
