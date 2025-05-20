/* O que o programa abaixo faz, caso você digite o seu primeiro e último nomes separados por um espaço em branco?
Ele pode acessar regiões de memória indevidamente? Em quais situações? Corrija-o mesmo para que isto não aconteça.*/


/*O programa lê uma string digitada pelo usuário (por exemplo: "Maria Silva") e imprime 
apenas o sobrenome, ou seja, a parte do texto após o primeiro espaço. 
Isso acontece porque a função misterio percorre a string até encontrar o primeiro espaço 
e, em seguida, imprime o restante da string a partir do caractere seguinte.*/

/* Sim, o programa pode acessar regiões de memória indevidamente em duas situações:
- gets(), pois essa função não limita a quantidade de carecteres lidos e isso pode 
causar estouro de buffer, invadindo outras regiões da memória;
- Se o usuário digitar apenas um nome o loop vai até o final da string que é \0. 
Nesse caso o ponteiro *n é '\0' e o loop para, mas depois do loop, o código faz n++ 
e o ponteiro vai apontar para além do fim da string. A memória depois disso não pertence 
necessariamente à sua string. 

Nesses casos podem acontecer algumas coisas:
- Lixo na tela (caracteres aleatórios)
- Falha de segmentação (segfault), se você tentar acessar um lugar que não tem permissão
- Comportamento indefinido: o programa faz algo inesperado ou imprevisível 

n++ só deve ser acessado se houver um sobrenom.*/ 

#include <stdio.h>

// Função que imprime a parte do nome após o primeiro espaço
void misterio(char *n);

int main(void)
{
    char nome[41]; // Vetor de 41 caracteres para armazenar nome completo (com espaço)

	// Usar fgets para evitar overflow
    //fgets(nome, sizeof(nome), stdin);
    gets(nome); // Lê a string digitada pelo usuário (perigoso, explico abaixo)

    misterio(nome); // Chama a função que imprime o sobrenome

    return 0;
}

// Função que percorre o nome até o primeiro espaço e imprime o restante
void misterio(char *n)
{
    while (*n != ' ') // Enquanto o caractere apontado não for espaço
        n++;          // Avança para o próximo caractere
	
	// Para consertar o código de acessar a memória indevidamente
	/*if (*n == ''){
    	n++;
		puts(n);
	}else {
    	printf("Nenhum sobrenome encontrado.\n");
	}*/
	
	n++;
    puts(n);          // Imprime a string restante (sobrenome)
}

