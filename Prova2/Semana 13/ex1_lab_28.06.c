#include <stdio.h>

#define MAX 1000

//Bubble sort decrescente
void bolha(int v[], int tam){
	int ult, i, aux;
	for (ult=tam-1; ult>0; ult--){
		for (i=0; i<ult; i++){
			if (v[i+1] > v[i]) {
				aux = v[i+1];
				v[i+1] = v[i];
				v[i] = aux; 
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
		
		while ((j>0)&&(aux>v[j-1])){
			v[j] = v[j-1];
			j--; 
		}
		
		v[j] = aux; 
	}	
}

/* Exemplo: [9 8 4 6 3]
aux = 8; j = 1; lOOP: j > 0 SIM; 8 > 9 NÃO; v[1] = 8; [9 8 4 6 3]
aux = 4; j = 2; LOOP: j > 0 SIM; 4 > 8 NÃO v[2] = 4; [9 8 4 6 3]
aux = 6; j = 3; LOOP: j > 0 SIM; 6 > 4 SIM [9 8 4 4 6 3]
                LOOP: j > 0 SIM; 6 > 8 NÃO [9 8 6 4 3]
*/

void selecao(int v[], int tam) {
	int i, p, aux, posMenor;
	for (i= tam -1; i>=0; i--) {
		posMenor = i;
		
		//encontra o menor elemento
		for (p=i-1; p>=0; p--){
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

/* Exemplo [3 6 4 8 9]
i = 4; posMenor = 4; posMenor = 0; 3 < 9? SIM [9 6 4 8 3]
i = 3; posMenor = 3; posMenor = 2; 4 < 8 ? SIM [ 9 6 8 4 3]
i = 2; posMenor = 2; posMenor = 1; 6 < 8 ? SIM [9 8 6 4 3]
*/

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
	
	bolha(v_1, N);
	printf("Bubble sort\n");
	for (int i = 0; i < N; i++){
		printf("%d ", v_1[i]);
	}
	printf("\n");
	
	insercao(v_2, N);
	printf("Insertion sort\n");
	for (int j = 0; j < N; j++){
		printf("%d ", v_2[j]);
	}
	
	printf("\n");
	
	selecao(v_3, N);
	printf("Selection sort\n");
	for (int k = 0; k < N; k++){
		printf("%d ", v_3[k]);
	}
	
	return 0;	
}
