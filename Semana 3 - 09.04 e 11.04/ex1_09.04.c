//Crie uma função inic()que inicializa os elementos de um vetor com zeros e faça um
//programa principal que teste a mesma.

#include <stdio.h>
#define DIM 10
void inic(int s[], int n){ //ou int *s ou int s[DIM]

	int i;
	for (i=0; i<n; i++){
		s[i]=0; //ou *(s+i)=0;
	}
}

int main(){

	int v[DIM], i;
	
	inic(v,DIM);
	
	for(i=0; i<DIM; i++){
		printf("%do. elemento = %d \n",i+1,v[i]);
	}
	return 0;

}
