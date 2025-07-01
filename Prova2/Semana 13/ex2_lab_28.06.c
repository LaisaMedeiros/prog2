#include <stdio.h>

#define MAX 1000

//Bubble sort
void bolha(int v[], int tam){
	int ult, i, aux;
	//começa do final em ult e vai diminuindo um
	//compara dois a dois até o maior numero ir pro final
	for (ult=tam-1; ult>0; ult--){
		//vai pro inicio 
		for (i=0; i<ult; i++){
			//compara dois numeros um ao lado do outro
			if (v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux; 
			}
		}
	}
}

//Insertion Sort
void insercao(int v[], int tam){
	int i, aux, j;
	for (i=1; i<tam; i++) {
		
		aux=v[i];
		j=i;
		
		while ((j>0)&&(aux<v[j-1])){
			v[j] = v[j-1];
			j--; 
		}
		
		v[j] = aux; 
	}	
}

//Selection Sort
void selecao(int v[], int tam) {
	int i, p, aux, posMenor;
	for (i=0; i<tam-1; i++) {
		posMenor = i;
		
		//encontra o menor elemento
		for (p=i+1; p<tam; p++){
			if (v[p] < v[posMenor])
				posMenor = p;
		}
		if (v[posMenor] < v[i]){
			aux = v[i];
			v[i] = v[posMenor];
			v[posMenor] = aux;
		}
	} 
}

void bolha_recursiva(int numeros[], int ini, int fim){
	int meio;
	if (ini < fim){
		meio = (ini + fim)/2;
		
		bolha_recursiva(numeros, ini, meio); 
		bolha_recursiva(numeros, meio+1, fim);
		
		//Após dividir e ordenar as duas metades, chama merge para uni-las de forma ordenada.
		bolha(numeros, fim - ini + 1);
	}
}

void insercao_recursiva(int numeros[], int ini, int fim){
	int meio;
	if (ini < fim){
		meio = (ini + fim)/2;
		
		insercao_recursiva(numeros, ini, meio); 
		insercao_recursiva(numeros, meio+1, fim);

		insercao(numeros, fim - ini + 1);
	}
}

void selecao_recursiva(int numeros[], int ini, int fim){
	int meio;
	if (ini < fim){
		meio = (ini + fim)/2;
		
		selecao_recursiva(numeros, ini, meio); 
		selecao_recursiva(numeros, meio+1, fim);
		
		selecao(numeros, fim - ini + 1);
	}
}

int main(){
	
	int v_1[MAX];
	int v_2[MAX];
	int v_3[MAX];
	
	int N;
	scanf("%d", &N);
	
	for (int i=0; i < N; i++){
		scanf("%d", &v_1[i]);
		v_2[i] = v_1[i];
		v_3[i] = v_1[i];
	}
	
	bolha_recursiva(v_1, 0, N-1);
	printf("Bubble sort\n");
	for (int i = 0; i < N; i++){
		printf("%d ", v_1[i]);
	}
	printf("\n");
	
	insercao_recursiva(v_2, 0, N -1);
	printf("Insertion sort\n");
	for (int j = 0; j < N; j++){
		printf("%d ", v_2[j]);
	}
	printf("\n");
	
	selecao_recursiva(v_3, 0, N-1);
	printf("Selection sort\n");
	for (int k = 0; k < N; k++){
		printf("%d ", v_3[k]);
	}
	
	return 0;
}

