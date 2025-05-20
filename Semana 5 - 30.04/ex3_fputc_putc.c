#include <stdio.h>
#include <stdlib.h>
int main() {
	int c;
	FILE *pa;
	char *nome = "texto.txt";
	if (( pa = fopen(nome, "w+")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
		exit(1);
	}
	c = getchar();
	while (!feof(stdin)) {
		fputc(c, pa);
		c = getchar();
	}
	rewind(pa); /* volta ao inicio do arquivo */
	printf("\nTerminei de escrever, agora vou ler.\n");
		c = fgetc(pa);
	while (!feof(pa)) {
		putchar(c);
		c = fgetc(pa);
	}
	fclose(pa);
	return 0;
}
