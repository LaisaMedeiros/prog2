// Faça uma função que receba uma string como parâmetro e retorne o número de
// vogais desta. – Apresente duas versões da função: uma usando
// vetores e outra utiIizando ponteiros.

#include <stdio.h>
#include <ctype.h> //para usar tolower()

#define MAX 100

//uma string é um vetor de char

int procura_vogais(char *c, int v){

	while (*c != '\0'){
		*c = tolower(*c);
		if (*c == 'a' || *c == 'e' || *c == 'i'|| *c== 'o' || *c == 'u'){
			v += 1;
		}
		c++; // Avança o ponteiro para o próximo caractere
	}
	
	return v;
}
	


int main(){
	
	char c[MAX];
	
	char *ptr;
	//Ao dar entender é incluido um \n que precisa ser removido senão é contado como letra
	//fgets inclui a quebra de linha \n que precisa ser removida
	fgets(c, sizeof(c), stdin); // Lê a linha inteira, incluindo espaços
	
	//Encontra o\n e susbtitui por \0
	c[strcspn(c, "\n")] = '0';
	
	ptr = c;
	int vogais = 0;
	
	printf("%d", procura_vogais(ptr, vogais));
	
	return 0;
}
