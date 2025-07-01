#include <stdio.h>

// A função recebe vetores crescentes v[p..q-1]
// e v[q..r-1] e rearranja v[p..r-1] em ordem
// crescente.
static void intercala (int p, int q, int r, int v[]){
	int *w;
	w = malloc ((r-p) * sizeof (int));
	int i = p, j = q;
	int k = 0;
	while (i < q && j < r) {
		if (v[i] <= v[j]) w[k++] = v[i++];
		else w[k++] = v[j++];
	}
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i = p; i < r; ++i) v[i] = w[i-p];
	free (w);
}

void mergesort_i (int n, int v[]){
	int b = 1;
	while (b < n) {
		int p = 0;
		while (p + b < n) {
			int r = p + 2*b;
			if (r > n) r = n;
			intercala (p, p+b, r, v);
			p = p + 2*b;
		}
		b = 2*b;
	}
}

int main(){
	
	int v[] = {9,8,4,6,3};
	int s[] = {17,5,8, 3, 1, 6};
	int N = 5;
	int M = 6;
	mergesort_i(N, v);
	for(int i = 0; i < N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	mergesort_i(M, s);
	for(int i = 0; i < M; i++){
		printf("%d ", s[i]);
	}
	
}
