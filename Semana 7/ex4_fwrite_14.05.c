#include <stdio.h>
#include <string.h>
typedef struct {

char nome [50];
int idade;
char sexo; } Tpessoa;

int main()
{

	FILE *parq;
	Tpessoa p;
	strcpy (p.nome, "Joao Silva");
	p.idade = 46;
	p.sexo = 'M';
	if (!(parq = fopen ("arquivo_bin.dat", "wb")))
	
	return -1;
	
	fwrite (&p, sizeof(Tpessoa), 1, parq);
	fclose (parq);
	return 0;

}
