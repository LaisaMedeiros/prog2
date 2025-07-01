//Laísa Medeiros

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	int idade;
}Tpessoa;

//Mescla duas sublistas: uma que vai de p até q e outra que vai de q+1 até r
void merge(Tpessoa* pessoa, int p, int q, int r) {
	int i, j, k; //indices para percorrer as listas
	int tamseq1 = q - p + 1; //tamanho da sequencia 1
	int tamseq2 = r - q;     //tamanho da sequencia 2
	
	//cria a pirmiera sublista e agurda em seq1
	Tpessoa seq1[tamseq1];
	for(i=0; i < tamseq1; i++){
		seq1[i] = pessoa[p+i]; 
		// seq1 pode receber o que está gurdado em pessoa pois são vetores do tipo Tpessoa
	}
	
	//cria a segunda sublista e guarda em seq2
	Tpessoa seq2[tamseq2];
	for(j=0; j < tamseq2; j++){
		seq2[j] = pessoa[q+1+j];
		// seq1 pode receber o que está gurdado em pessoa pois são vetores do tipo Tpessoa
	}
	
	//esse loop roda até uma das sequências chegar ao fim
	//Compara os elementos das duas sublistas e coloca o menor em pessoa[k].
	k = p; i = 0; j = 0;
	while (i < tamseq1 && j < tamseq2){
		// se seq1[i].nome vem antes de seq2[j].nome colocamos seq2[j] em pessoa[k]
		if(strcmp(seq1[i].nome, seq2[j].nome) < 0) {
			pessoa[k] = seq2[j];
			j++; 
		}
		//faz o oposto
		else {
			pessoa[k] = seq1[i];
			i++; 
		}
		
		k++;
	}
	// Copia os elementos restantes da sublista 1, caso ainda existam.
	while (i < tamseq1) {
		pessoa[k] = seq1[i];
		k++;
		i++;
	}
	
	//Copia os elementos restantes da sublista 2, caso ainda existam.
	while (j < tamseq2) {
		pessoa[k] = seq2[j];
		k++;
		j++;
	}
}

//são selecionados dois subarranjos já ordenados
//Função recursiva que ordena o vetor do índice ini até fim.
void mergeSort(Tpessoa* pessoa, int ini, int fim) {
	int meio;
	if(ini < fim) {
	meio = (ini + fim)/2;  //Divide o vetor ao meio, se ainda tiver mais de um elemento.
	
	//Aplica mergeSort recursivamente na metade esquerda e depois na metade direita.
	mergeSort(pessoa, ini, meio); 
	mergeSort(pessoa, meio+1, fim);
	
	//Após dividir e ordenar as duas metades, chama merge para uni-las de forma ordenada.
	merge(pessoa, ini, meio, fim);
	}
}

int main(){
	int N;
	
	scanf("%d", &N);
	Tpessoa* pessoa = malloc(N* sizeof (Tpessoa));
	
	if (pessoa == NULL) {
    	printf("Erro de alocação!\n");
    	exit(1);
	}
	
	for (int i = 0; i < N; i++){
		scanf("%s", pessoa[i].nome);
		scanf("%d", &pessoa[i].idade);
	}
	
	mergeSort(pessoa, 0, N-1);
	
	for (int i =0; i < N; i++){
		printf("%s: %d anos\n", pessoa[i].nome, pessoa[i].idade);
	}
	
	free(pessoa);
	return 0;
	
}

