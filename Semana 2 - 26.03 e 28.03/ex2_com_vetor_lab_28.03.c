// Faça uma função que receba uma string como parâmetro e retorne o número de
// vogais desta. – Apresente duas versões da função: uma usando
// vetores e outra utiIizando ponteiros.

#include <stdio.h>
#include <ctype.h> //para usar tolower()

#define MAX 100

//uma string é um vetor de char

// como c é um vetor tem que passar como parametro c[]
int procura_vogais(char c[], int v){
	
	int i = 0;
	while (c[i] != '\0'){
		c[i] = tolower(c[i]);
		if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i'|| c[i] == 'o' || c[i]== 'u'){
			v += 1;
		}
		i++;
	}
	
	return v;
}


int main(){
	
	char c[MAX];
	
	//Ao dar entender é incluido um \n que precisa ser removido senão é contado como letra
	//fgets inclui a quebra de linha \n que precisa ser removida
	fgets(c, sizeof(c), stdin); // Lê a linha inteira, incluindo espaços
	
	//Encontra o\n e susbtitui por \0
	c[strcspn(c, "\n")] = '\0';
	int vogais = 0;
	
	printf("%d", procura_vogais(c, vogais));
	
	return 0;
}
