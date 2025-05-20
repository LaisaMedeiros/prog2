#include <stdio.h>

typedef struct{
	char nome[30];
	int matricula;
}tAluno;

int main(){
	
	tAluno *x; // x é um ponteiro que pode aramzenar o endereço de uma struct tAluno
	tAluno y;  // y é uma variável do tipo tAluno
	x = &y; //x aponta para o endereço da struct y
	
	// x->matricula modifica y.matricula
	x->matricula = 2031; // através da seta x acessa o campo da struct
	// (*x).matricula = 2031  //Desreferencia x e acessa o campo
	printf("%d\n", y.matricula);
	
	return 0; 	
}

// y.matricula acessa direto o campo da struct y
// x->matricula acessa o campo via ponteiro x


