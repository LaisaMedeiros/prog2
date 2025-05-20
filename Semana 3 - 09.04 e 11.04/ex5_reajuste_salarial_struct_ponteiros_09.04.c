/* Considere o tipo de dado tEmpregado definido ao lado para armazenar
informa��es sobre um empregado. Implemente uma fun��o para reajustar o
sal�rio de um dado empregado em 10%, caso ele tenha nascido antes de 1980,
e de 7%, caso ele tenha nascido a partir de 1980. */

#include <stdio.h>

typedef struct{
	int dia, mes, ano;
}tData;

typedef struct{
	char nome [40];
	tData dataNascimento, dataAdmissao;
	char sexo;
	float salario;
}tEmpregado;

/* Se o campo j� � um ponteiro: N�o use &. Se o campo � uma vari�vel comum: Use &.
No caso da struct tEmpregado: x � um ponteiro para a struct (tEmpregado *), mas seus campos 
(como dia, mes, ano, sexo, salario) n�o s�o ponteiros � s�o vari�veis normais.
Por isso, usamos & para passar seus endere�os ao scanf.

Em C, os �nicos campos de uma struct que j� s�o ponteiros (ou que decaiem para ponteiros quando 
passados para fun��es) s�o: Vetor de char (strings), Vetor de n�mero e qualquer outro tipo de array/vetor*/

void ler_dados(tEmpregado *x){
	
	printf("Digite o nome do empregado: ");
	fgets(x->nome, 40, stdin);
	x->nome[strcspn(x->nome, "\n")] = '\0';
	
	printf("Digite a data de nascimento (D/M/A): ");
	scanf("%d/%d/%d", &x->dataNascimento.dia, &x->dataNascimento.mes, &x->dataNascimento.ano);
	
	printf("Digite a data de admissao (D/M/A): ");
	scanf("%d/%d/%d", &x->dataAdmissao.dia, &x->dataAdmissao.mes, &x->dataAdmissao.ano);
	
	printf("Infroma o sexo: ");
	scanf(" %c", &x->sexo);
	
	printf("Informe o sal�rio: ");
	scanf("%f", &x->salario);
	
}

void reajuste_salarial(tEmpregado *x){
	
	if (x->dataNascimento.ano < 1980){
		x->salario = x->salario * 1.1;
	}
	else{
		x->salario = x->salario * 1.07;
	}
}

int main(){

	tEmpregado empregado;
	//tEmpregado *x;
	//x = &empregado;
	
	/*printf("Digite o nome do empregado: ");
    fgets(x->nome, 40, stdin);
    x->nome[strcspn(x->nome, "\n")] = '\0'; // remove o '\n' do final

    printf("Digite a data de nascimento (D/M/A): ");
    scanf("%d/%d/%d", &x->dataNascimento.dia, &x->dataNascimento.mes, &x->dataNascimento.ano);

    printf("Digite a data de admissao (D/M/A): ");
    scanf("%d/%d/%d", &x->dataAdmissao.dia, &x->dataAdmissao.mes, &x->dataAdmissao.ano);

    printf("Informe o sexo: ");
    scanf(" %c", &x->sexo); // espa�o antes do %c para limpar o buffer

    printf("Informe o sal�rio: ");
    scanf("%f", &x->salario);
	
	reajuste_salarial(x);*/
 
	ler_dados(&empregado);
	reajuste_salarial(&empregado);
	
	printf("\n--- Dados ap�s reajuste ---\n");
	printf("Nome: %s\n", empregado.nome);
	printf("Sexo: %c\n", empregado.sexo);
	printf("Data de nascimento: %02d/%02d/%04d\n", empregado.dataNascimento.dia, empregado.dataNascimento.mes, empregado.dataNascimento.ano);
	printf("Data de admiss�o: %02d/%02d/%04d\n", empregado.dataAdmissao.dia, empregado.dataAdmissao.mes, empregado.dataAdmissao.ano);
	printf("Sal�rio reajustado: R$ %.2f\n", empregado.salario);
	
	return 0;
}
