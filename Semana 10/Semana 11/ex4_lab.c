#include <stdio.h>

// Adicione estas definições no início do arquivo
#define bool int
#define true 1
#define false 0

// Função de busca binária recursiva
bool buscaR(int v[], int n, int procurado, int esq, int dir) {
    // Calcula o índice do meio do intervalo atual
    int meio = (esq + dir) / 2;
    
    // Verifica se o intervalo de busca ainda é válido (esq <= dir)
    if(esq <= dir) {
        // Caso 1: encontramos o elemento procurado
        if(v[meio] == procurado)
            return true;  // Retorna verdadeiro se encontrado
            
        // Caso 2: elemento do meio é maior que o procurado
        else if(v[meio] > procurado)
            // Busca recursivamente na metade ESQUERDA do vetor
            return buscaR(v, n, procurado, esq, meio - 1);
            
        // Caso 3: elemento do meio é menor que o procurado
        else
            // Busca recursivamente na metade DIREITA do vetor
            return buscaR(v, n, procurado, meio + 1, dir);
    }
    
    // Se o intervalo se esgotou (esq > dir) e não encontrou, retorna falso
    return false;
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
	
	int esq = 0;
	int dir = tam -1; 
	
	if(buscaR(arr, tam, el, esq, dir)){
		printf("Elemento encontrando.");
	} 
	else {
		printf("Elemento não encontrado.");
	}
	
	return 0;
}
