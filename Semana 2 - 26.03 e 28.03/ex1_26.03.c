#include <stdio.h>
int main () {

int i, j, *ip, *jp; 
char c, *cp; 
cp = &c; //o ponteiro cp aponta para o endere�o do char c
c = 'a'; // o ponteiro cp derreferenciado agora � 'a'
*cp = 'z';  // c = 'z'
printf("c = %c\n", c);  //imprime 'z'
i = 10;    
ip = &i;
printf("ip=%p\n", ip);  //imprime o endere�o apontado por ip
printf("*ip=%d\n", *ip); // imprime o valor de i, o ponteiro derreferenciado
jp = NULL; // jp n�o aponta para nenhum endere�o de mem�ria v�lido. 
*jp = i; // O valor apontado pleo ponteiro seria i, mas � incorreto pois jp n�o aponta para uma vari�vel!!!
return 0;

}
