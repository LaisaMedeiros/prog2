#include <stdio.h>
int main () {

int i, j, *ip, *jp; 
char c, *cp; 
cp = &c; //o ponteiro cp aponta para o endereço do char c
c = 'a'; // o ponteiro cp derreferenciado agora é 'a'
*cp = 'z';  // c = 'z'
printf("c = %c\n", c);  //imprime 'z'
i = 10;    
ip = &i;
printf("ip=%p\n", ip);  //imprime o endereço apontado por ip
printf("*ip=%d\n", *ip); // imprime o valor de i, o ponteiro derreferenciado
jp = NULL; // jp não aponta para nenhum endereço de memória válido. 
*jp = i; // O valor apontado pleo ponteiro seria i, mas é incorreto pois jp não aponta para uma variável!!!
return 0;

}
