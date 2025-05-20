#include <stdio.h>

void strcpy1(char *dest, char *fonte){
	
	int i = 0;
	// Enquanto a atribuição do caractere de fonte para dest não for o terminador \0
	// Quando fonte[i] for \0, ele será copiado para dest[i] e o loop termina
	while ((*dest++ = *fonte++) != '\0'){
		i++;
	}
	
	/*while ((dest[i] = fonte[i]) != '\0'){
		i++;
	}
	
	while ((*dest = *fonte) != '\0'){
		dest++;
		fonte++;
	}
	
	while ((*dest = *fonte) != '\0');
	
	// O while para quando detecta '\0', mesmo sem uma comparação explícita.
	while (*dest++ = *fonte++);*/
}

int main(){
	char a[100], b[] = "Ola mundo";
	strcpy1(a,b);
	printf("a: %s\nb: %s\n", a, b);
	return 0;
}
