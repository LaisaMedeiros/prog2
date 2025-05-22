#include <stdio.h>
int main(){
	float real, maior;
	int lidos;
	char nomearq[100];
	FILE *parq;
	printf("Informe o nome do arquivo: ");
	
	gets(nomearq);
	if (!(parq = fopen(nomearq, "rb"))){
		return -1;
	}
	
	lidos=fread(&maior, sizeof(float), 1, parq);
	if (lidos==0){
		printf("Erro na leitura dos dados");
		return -1;
	}
	
	while(!feof(parq)){
		lidos=fread(&real, sizeof(float), 1, parq);	
		if(real>maior){
			maior=real;
		}
	}
	printf("O maior numero armazenado no arquivo eh %f\n",maior);
	fclose(parq);
	return 0;
}
