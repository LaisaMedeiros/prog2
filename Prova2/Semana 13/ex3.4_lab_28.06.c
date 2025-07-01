#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// A fun��o recebe vetores crescentes v[p..q-1]
// e v[q..r-1] e rearranja v[p..r-1] em ordem
// crescente.
static void intercala (int p, int q, int r, int v[]){
	
	int *w; 
	w = malloc ((r-p) * sizeof (int));
	int i = p, j = q; //i � inicio, j � o meio
	int k = 0;
	
	while (i < q && j < r) {
		if (v[i] <= v[j]){
			w[k++] = v[i++];
		}
		else{
			w[k++] = v[j++];
		}
	}
	
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i = p; i < r; ++i) v[i] = w[i-p];
	free (w);
}

//As fun��es abaixo colocam os vetores em ordem. Indicar qual est� certa e errada
// p � inicio e r � o final
void mergesort4 (int p, int r, int v[]) {
	
	if (p < r-1) {
		int q = (p + r) / 2; //q � o meio
		mergesort4 (p, q-1, v); //chama a fun��o para a primeia metade
	
		mergesort4 (q-1, r, v); // ta errado, pois deveria ser q+1, o elmento na posi��o q estar�
		//repetido ao juntar os vetores
		
		intercala (p, q-1, r, v); 
	} 
}

int main(){
	int v[] = {9,8,4,6,3};
	int N = 5;
	mergesort4(0, N, v);
	for(int i = 0; i < N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	
	int s[] = {17,5,8, 3, 1, 6};
	int M = 6;
	mergesort4(0, M, s);
	for(int i = 0; i < M; i++){
		printf("%d ", s[i]);
	}
	
}


