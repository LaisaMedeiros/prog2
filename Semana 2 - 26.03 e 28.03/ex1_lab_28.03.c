/*ImpIemente uma fun��o que recebe dois
par�metros: o sal�rio atuaI de uma pessoa
(por refer�ncia) e o percentuaI de aumento
(por vaIor). A fun��o deve alterar o valor
do sal�rio acrescentando o percentual
correspondente de aumento. Mostre
como a fun��o poderia ser chamada a partir
da fun��omain. */

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
