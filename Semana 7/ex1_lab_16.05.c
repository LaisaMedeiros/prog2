#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFile, int N){
	
	int count = 0;
	for (int i = N; i > 0; i--){
		if(fwrite(&i,sizeof(int), 1, pFile) != 1){
			return count;
		}
		count++;
	}
	
	rewind(pFile);
	return count;	
}

//retorna uma ponteiro
void *recupera(FILE *pFile){
	
	//fseek coloca o ponteiro no final do arquivo
	fseek(pFile, 0, SEEK_END);
	int tam = ftell(pFile);
	tam = tam/sizeof(int);
	
	rewind(pFile);
	
	int *ptr;
	ptr = (int *)malloc(tam*sizeof(int));	
	
	if (ptr == NULL) {
        perror("Erro de alocação");
        return NULL;
    }

	if(fread(ptr, sizeof(int), tam, pFile) != tam){
		free(ptr);
		return NULL;	
	}
	
	return ptr;
}

void exibe_vetor(int *vetor, int N){
	
	for (int i = 0; i < N; i++){
		printf("%d ", *(vetor+i)); //vetor[i]
	}
	printf("\n");	
}

int modifica(FILE *pFile, int M){
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(int);

    if (M <= 0 || M > tam) {
        return -1; // intervalo inválido
    }

    // Volta para o início dos últimos M inteiros
    fseek(pFile, -M * sizeof(int), SEEK_END);

    for (int i = 0; i < M; i++) {
        int valor;
        long pos = ftell(pFile); // agora salva corretamente a posição do valor atual

        if (fread(&valor, sizeof(int), 1, pFile) != 1) {
            return i;
        }

        if (valor % 2 == 0) {
            valor *= 2;
            fseek(pFile, pos, SEEK_SET); // volta para posição correta do valor lido
            if (fwrite(&valor, sizeof(int), 1, pFile) != 1) {
                return i;
            }
            fseek(pFile, pos + sizeof(int), SEEK_SET); // move para o próximo valor
        }
    }

    rewind(pFile);
    return M;
}


void recupera_exibe(FILE *pFile){

	fseek(pFile, 0, SEEK_END);
	int tam = ftell(pFile);
	tam = tam/sizeof(int);
	
	rewind(pFile);
	
	int valor;
	for (int i = 0; i < tam; i++){
		if (fread(&valor, sizeof(int), 1, pFile) == 1){
			printf("%d ", valor);	
		}	
	}
	
}


int main(){
	FILE *pFile;
	int i, N, M, num, mod, *vetor;
	char nome_arquivo[100];
	printf("Informe o nome do arquivo a ser criado: ");
	gets(nome_arquivo);
	
	printf("Informe um numero positivo: ");
	scanf("%d",&N);
	pFile = fopen (nome_arquivo , "wb+");
	
	if (!pFile){ 
		printf("Erro na criacao do arquivo...");
		return -1;
	}
	
	if (grava(pFile, N)!=N){
		printf("Erro na gravacao do arquivo...");
		return -1;
	}
	vetor=recupera(pFile);
	if(vetor==NULL){
		printf("Erro na recuperacao de dados do arquivo...");
		return -1;
	}
	
	exibe_vetor(vetor,N);
	printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: "); 
	scanf("%d",&M);
	
	mod=modifica(pFile,M);
	if(mod==-1){
		printf("Valor de M fora do intervalo permitido...");
		return -1;
	}
	if(mod!=M){ 
		printf("Erro de leitura e/ou gravacao no arquivo...");
		return -1;
	}
	recupera_exibe(pFile);
	fclose (pFile);
	return 0;
}
