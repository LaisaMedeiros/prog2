/* O que o programa abaixo faz, caso voc� digite o seu primeiro e �ltimo nomes separados por um espa�o em branco?
Ele pode acessar regi�es de mem�ria indevidamente? Em quais situa��es? Corrija-o mesmo para que isto n�o aconte�a.*/


/*O programa l� uma string digitada pelo usu�rio (por exemplo: "Maria Silva") e imprime 
apenas o sobrenome, ou seja, a parte do texto ap�s o primeiro espa�o. 
Isso acontece porque a fun��o misterio percorre a string at� encontrar o primeiro espa�o 
e, em seguida, imprime o restante da string a partir do caractere seguinte.*/

/* Sim, o programa pode acessar regi�es de mem�ria indevidamente em duas situa��es:
- gets(), pois essa fun��o n�o limita a quantidade de carecteres lidos e isso pode 
causar estouro de buffer, invadindo outras regi�es da mem�ria;
- Se o usu�rio digitar apenas um nome o loop vai at� o final da string que � \0. 
Nesse caso o ponteiro *n � '\0' e o loop para, mas depois do loop, o c�digo faz n++ 
e o ponteiro vai apontar para al�m do fim da string. A mem�ria depois disso n�o pertence 
necessariamente � sua string. 

Nesses casos podem acontecer algumas coisas:
- Lixo na tela (caracteres aleat�rios)
- Falha de segmenta��o (segfault), se voc� tentar acessar um lugar que n�o tem permiss�o
- Comportamento indefinido: o programa faz algo inesperado ou imprevis�vel 

n++ s� deve ser acessado se houver um sobrenom.*/ 

#include <stdio.h>

// Fun��o que imprime a parte do nome ap�s o primeiro espa�o
void misterio(char *n);

int main(void)
{
    char nome[41]; // Vetor de 41 caracteres para armazenar nome completo (com espa�o)

	// Usar fgets para evitar overflow
    //fgets(nome, sizeof(nome), stdin);
    gets(nome); // L� a string digitada pelo usu�rio (perigoso, explico abaixo)

    misterio(nome); // Chama a fun��o que imprime o sobrenome

    return 0;
}

// Fun��o que percorre o nome at� o primeiro espa�o e imprime o restante
void misterio(char *n)
{
    while (*n != ' ') // Enquanto o caractere apontado n�o for espa�o
        n++;          // Avan�a para o pr�ximo caractere
	
	// Para consertar o c�digo de acessar a mem�ria indevidamente
	/*if (*n == ''){
    	n++;
		puts(n);
	}else {
    	printf("Nenhum sobrenome encontrado.\n");
	}*/
	
	n++;
    puts(n);          // Imprime a string restante (sobrenome)
}

