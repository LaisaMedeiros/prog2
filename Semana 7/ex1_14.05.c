#include <stdio.h>

//Abre o arquivo dados.txt e tenta ler os últimos 20 caracteres a parrir do fim

int main(){
	char c;
	FILE *parq=fopen("dados.txt","r");
	if(parq==NULL){
			return -1;
	}
	
	if (fseek(parq, -20, SEEK_END) != 0) {
        printf("Erro com fseek. O arquivo pode ser muito pequeno.\n");
        fclose(parq);
        return -1;
    }
	
	/*
	while(!feof(parq)){
		c='\n'; //valor aleatório só para ter algo caso a aleitura falhe
		fscanf (parq,"%c",&c);
		printf("%c",c);
		
	}
	*/
	
	//fgetc(parq) retorna o proximo caractere do arquivo apontado por parq como um int entre 0 e 255
	//EOF é menos -1;
	int c;
	while ((c = fgetc(parq)) != EOF) {
        putchar(c); //imprime um unico caractere na saida padrão
    }
	
	fclose(parq);
	return 0;

}
