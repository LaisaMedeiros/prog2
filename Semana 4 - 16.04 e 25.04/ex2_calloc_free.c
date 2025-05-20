#include <stdio.h>
#include <stdlib.h>
int main (){

	float *v;
	int i, tam;
	printf ("Qual o tamanho do vetor? ");
	scanf ("%d" , &tam);
	v = (float *) calloc (tam, sizeof (float));
	if (!v)
	{
	
	printf ("Erro alocacao memoria");
	return -1;
	
	}
	for (i=0; i<tam; i++)
	{
	
	printf ("Elemento %d? " , i) ;
	scanf ("%f", v+i);
	
	}
	for (i=0; i<tam; i++)
	
	printf ("v[%d]=%.2f\n",i,*(v+i));
	
	free (v);
	return 0;

}
