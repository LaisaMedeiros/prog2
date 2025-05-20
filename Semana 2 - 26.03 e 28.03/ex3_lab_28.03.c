// A função deve atuaIizar o vaIor do argumento passado através do parâmetro n com a quantidade
// de números pares dentre os n primeiros eIementos de um vetor (acessado a partir do
// ponteiro v).

#include <stdio.h>

void pares(int *v, int *n){
	
	while (*v != -1){
		if (*v % 2 == 0){
			*n = *n + 1;
		}
		v++;
	}

}

int main(){
	
	int N;
	scanf("%d", &N);
	
	int v[N+1]; // vetor declarado, mas não inicializado, pois contém valores aleatórios
	// Vetor declarado como N+1 para acomodar o valor -1 acrescentado ao final por causa do ponteiro
	int *ptr = v; //pode fazer isso memso com o vetor não inicializado, pois 
	
	for (int i = 0; i < N; i++){
		scanf("%d", ptr + i); //preecnhe o vetor via ponteiro
	}
	
	v[N] = -1; //Adiciona o valor para que o ponteiro encontre o fim do vetor ao percorrê-lo
	
	int n = 0; //nuemro de pares
	pares(ptr, &n);
	
	printf("%d", n);
	
	return 0;
}
