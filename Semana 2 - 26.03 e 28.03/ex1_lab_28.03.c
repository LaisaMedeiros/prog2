/*ImpIemente uma função que recebe dois
parâmetros: o salário atuaI de uma pessoa
(por referência) e o percentuaI de aumento
(por vaIor). A função deve alterar o valor
do salário acrescentando o percentual
correspondente de aumento. Mostre
como a função poderia ser chamada a partir
da funçãomain. */

#include <stdio.h>

void Altera (float *ps, float p){
	
	*ps = *ps + (*ps * p / 100);
}

int main(){
	
	float S, P;
	scanf("%f", &S);
	scanf("%f", &P);
	Altera(&S, P);
	printf("%.2f", S);
	return 0;
}
