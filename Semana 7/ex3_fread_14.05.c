#include <stdio.h>
typedef struct {

char nome [50];
int idade;
char sexo; } Tpessoa;

int main()
{

	FILE *parq;
	Tpessoa p;
	if (!(parq = fopen ("arquivo_bin.dat", "rb"))){
		return -1;
	}
	fread (&p, sizeof(Tpessoa), 1, parq);
	printf("%s %d %c\n",p.nome,p.idade,p.sexo);
	fclose (parq);
	return 0;

}
