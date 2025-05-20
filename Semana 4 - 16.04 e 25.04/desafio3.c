///Laísa Tatiana Oliveira de Medeiros

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//O cmapo de batalha é divido em blocos que não se sobrepoem.

int main() {
    int L, C, M, N;
    scanf("%d %d %d %d", &L, &C, &M, &N);
    
    if (L <=  0 || C <= 0 || M <= 0 || N <= 0){
    	return -1;
	}

	if (M >= L || N >= C){
		return -1;
	}

	//definindo uma matriz de ponteiro de ponteiro
    int **campo = malloc(L * sizeof(int *));
    if (campo == NULL) {
        //printf("Erro de alocação!\n");
        exit(1);
    }

    for (int i = 0; i < L; i++) {
        campo[i] = malloc(C * sizeof(int));
        if (campo[i] == NULL) {
            printf("Erro de alocação!\n");
            exit(1);
        }
    }

	//Lendo a matriz
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    int max_soma = INT_MIN;

    // Percorre apenas os blocos não sobrepostos
    for (int i = 0; i < L; i += M) {       // Avança de M em M linhas
        for (int j = 0; j < C; j += N) {   // Avança de N em N colunas
            int soma = 0;
            // Soma os elementos no bloco M x N atual
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < N; l++) {
                    soma += campo[i + k][j + l];
                }
            }
            if (soma > max_soma) {
                max_soma = soma;
            }
        }
    }

    printf("%d\n", max_soma);

    for (int i = 0; i < L; i++) {
        free(campo[i]);
    }
    free(campo);

    return 0;
}
