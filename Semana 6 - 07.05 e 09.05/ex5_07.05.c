#include <stdio.h>
#define NOME_A1 "cadastro.txt"
#define NOME_A2 "aumento.txt"

int main(){
	
	long int matricula; float salario;
	int num;
	FILE *pa1, *pa2;
	pa1=fopen(NOME_A1, "r");
	if(pa1 == NULL)
	return -1;
	fscanf(pa1, "%d", &num);
	pa2 = fopen(NOME_A2, "w");
	if(pa2 == NULL){
	fclose(pa1);
	return -1;
	}
	while(num > 0)
	{
	fscanf(pa1, "%ld %f", &matricula, &salario);
	fprintf(pa2, "%ld %.2f\n", matricula, salario*1.1);	
	num--;
	}
	fclose(pa1);
	fclose(pa2);
	return 1;
}
