//exemplo de malloc e free com vetor de ponteiros

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int tam, i;
	char *g[3]; //vetor de 3 ponteiros de caracteres
	tam = sizeof(char);
	// (char *) converte o ponteiro void retornado por malloc para uma char*
	g[0] = (char *)malloc(13*tam); //g[0] aponta para um espa�o na heap de 13*tam bytes
	strcpy(g[0], "Computa��o I");
	g[1] = (char *)malloc(23*tam);
	strcpy(g[1], "Ssietmas de Informa��o");
	g[2] = (char *)malloc(14*tam);
	strcpy(g[2], "Computa��o II");
	for (i=0; i <3; i++){
		free(g[i]);
	}
	return 0;
}
