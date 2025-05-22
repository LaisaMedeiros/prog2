#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[100];
	double nota[3];
	double media;
} Taluno;


int main(){

	FILE *pFile;
	
	char nome_arquivo[50];
	printf("Insira o nome do arquivo:");
	scanf("%s", nome_arquivo);
	getchar();
	
	pFile = fopen(nome_arquivo, "wb");
	if (!pFile) {
        printf("Erro ao abrir arquivo");
        return -1;
    }
	
	int N;
	printf("Quantos alunos são?");
	scanf("%d", &N);
	getchar();
	
	Taluno *p;
	p = (Taluno *)malloc(N*sizeof(Taluno));
	if (p == NULL) {
        printf("Erro na alocação de memória");
        fclose(pFile);
        return -1;
    }
	
	for (int i = 0; i < N; i++){
		
		printf("\nAluno %d\n", i + 1);
		
		printf("Informe seu nome:");
		fgets((p+i)->nome, 50, stdin);
		(p+i)->nome[strcspn((p+i)->nome, "\n")] = '\0';
		if (strcmp((p+i)->nome, "")== 0){
			return -1;
		}
		printf("Insira suas três notas:");
		scanf("%lf %lf %lf", &(p+1)->nota[0], &(p + i)->nota[1], &(p+i)->nota[2]);
		p->media = ((p+i)->nota[0] + (p+i)->nota[1] + (p+i)->nota[2])/3.0;
		
		fwrite((p + i), sizeof(Taluno), 1, pFile);	
	}

	free(p);
	fclose(pFile);
	return 0;
}
