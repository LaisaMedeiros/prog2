// Fa�a uma fun��o que receba uma string como par�metro e retorne o n�mero de
// vogais desta. � Apresente duas vers�es da fun��o: uma usando
// vetores e outra utiIizando ponteiros.

#include <stdio.h>
#include <ctype.h> //para usar tolower()

#define MAX 100

//uma string � um vetor de char

int procura_vogais(char *c, int v){

	while (*c != '\0'){
		*c = tolower(*c);
		if (*c == 'a' || *c == 'e' || *c == 'i'|| *c== 'o' || *c == 'u'){
			v += 1;
		}
		c++; // Avan�a o ponteiro para o pr�ximo caractere
	}
	
	return v;
}
	


int main(){
	
	char c[MAX];
	
	char *ptr;
	//Ao dar entender � incluido um \n que precisa ser removido sen�o � contado como letra
	//fgets inclui a quebra de linha \n que precisa ser removida
	fgets(c, sizeof(c), stdin); // L� a linha inteira, incluindo espa�os
	
	//Encontra o\n e susbtitui por \0
	c[strcspn(c, "\n")] = '0';
	
	ptr = c;
	int vogais = 0;
	
	printf("%d", procura_vogais(ptr, vogais));
	
	return 0;
}
