/* Implemente a fun��o posicao que tem o seguinte prot�tipo:
int posicao(char *substr, char *str);
Esta fun��o deve verificar se a cadeia apontada por substr est� presente na cadeia apontada por
str e retornar a posi��o em que a sub-cadeia aparece em cadeia (deve ser retornada a posi��o em
 que inicia a primeira ocorr�ncia, mesmo que a substring se repita na string).

Fa�a um programa principal para testar a fun��o implementada.  */

#include <stdio.h>
#include <string.h>

#define MAX 100

int posicao(char *substr, char *str){
	
	int len_str = strlen(str);
    int len_sub = strlen(substr);
	
	//S� vale a pena tentar at� len_str - len_sub, porque depois disso n�o h� espa�o 
	//suficiente para a substring.
	for (int i = 0; i < len_str - len_sub; i++){
		int j;
		
		//compara cada caractere da substring com a parte da str iniciando em i.
		//Se todos os caracteres baterem, j vai at� o final de substr.
		//Se algum caractere for diferente, ele d� break.
		for (j = 0; j < len_sub; j++){
			if (str[i+j] != substr[j]){
				break;
			}
		}
		if (j == len_sub) // achou a substring
            return i;
	}
	
	//Se sair do for principal sem encontrar nada, retorna -1, dizendo que n�o foi encontrado.
	return -1; //n�o encontrado
}

int main(){
	
	char c1[MAX];
	fgets(c1, MAX, stdin);
	c1[strcspn(c1, "\n")] = '\0'; // remove '\n' do final
	
	char c2[MAX];
	fgets(c2, MAX, stdin);
	c2[strcspn(c2, "\n")] = '\0'; // remove '\n' do final
	
	int pos = posicao(c1, c2);
	
	if (pos >= 0)
        printf("Substring encontrada na posi��o: %d\n", pos);
    else
        printf("Substring n�o encontrada.\n");

    return 0;
}


