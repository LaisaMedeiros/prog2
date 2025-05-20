#include <stdio.h>
#define MAX 80
int main (void) {
char linha[MAX];
FILE *pa;
char *nome = "texto.txt";
if (( pa = fopen(nome, "w+")) == NULL) {
printf("Nao foi possivel abrir o arquivo.\n");
return 1;
}
fgets(linha, MAX, stdin);
while (!feof(stdin)) {
fputs(linha, pa);
fgets(linha, MAX, stdin);
}
rewind(pa); /* volta ao inicio do arquivo */
printf("Terminei de escrever, agora vou ler.\n");
fgets(linha, MAX, pa);
while (!feof(pa)) {
puts(linha);
fgets(linha, MAX, pa);
}
fclose(pa);
return 0;
}
