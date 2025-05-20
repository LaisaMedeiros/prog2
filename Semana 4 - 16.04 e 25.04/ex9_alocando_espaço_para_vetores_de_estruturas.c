#include <stdio.h>
#include <stdlib.h>
typedef struct _func
{
char nome[40];
float salario;
} Tfunc ;
void le (Tfunc *cadastro, int funcionarios)
{
int i;
char linha[40];
for (i=0; i<funcionarios; i++)
{
puts("Nome ?");
fgets((cadastro+i)->nome, 39, stdin);
puts ("Salario ?"); fgets(linha, 39, stdin);
sscanf(linha, "%f", &((cadastro+i)->salario));
}
}


float media(Tfunc *cadastro, int funcionarios)
{
float media=0.0;
int i;
for (i=0; i<funcionarios; i++)
{
media += (cadastro+i)->salario;
}
return media /= funcionarios;
}

int main(void)
{
Tfunc *cadastro;
int funcionarios;
char linha[40];
puts("Quantos funcionarios ?");
fgets(linha, 39, stdin);
sscanf (linha, "%d" , &funcionarios);
cadastro = (Tfunc *)malloc(funcionarios * sizeof (Tfunc));
if (!cadastro) exit (1) ;
le(cadastro, funcionarios);
printf("Salario medio = %.2f\n",
media(cadastro, funcionarios) );
return 0;
}
