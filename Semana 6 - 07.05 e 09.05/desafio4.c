///Laísa Tatiana Oliveira de Medeiros

#include <stdio.h>
#include <string.h>

// Função para converter horas, minutos e segundos em segundos totais
int calcular_segundos(int horas, int minutos, int segundos) {
    return horas * 3600 + minutos * 60 + segundos;
}

int main() {
    char nome_arquivo[100];
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return -1;
    }

    int A, C; // Número de atletas e corridas
    fscanf(arquivo, "%d %d", &A, &C);

	// Verifica se A e C são positivos
	if (A <= 0 || C <= 0) {
	    fclose(arquivo);
	    return -1;
	}
	
    char nome_vencedor[101];
    int menor_tempo_segundos = -1; // Inicializa com um valor inválido
	
    for (int i = 0; i < A; i++) {
        char nome_atleta[101];
        fscanf(arquivo, "%s", nome_atleta);

		// Verifica se o nome do atleta tem mais de 100 caracteres 
		if (strlen(nome_atleta) >= 100) {
		    fclose(arquivo);
		    return -1;
		}
		
        int total_segundos = 0;
        for (int j = 0; j < C; j++) {
            int h, m, s;
            fscanf(arquivo, "%d %d %d", &h, &m, &s);
            total_segundos += calcular_segundos(h, m, s);
        }

        // Se for o primeiro atleta ou encontrar um tempo menor
        if (menor_tempo_segundos == -1 || total_segundos < menor_tempo_segundos) {
            menor_tempo_segundos = total_segundos;
            strcpy(nome_vencedor, nome_atleta);
        }
    }

    fclose(arquivo);

    // Saída conforme o formato especificado
    printf("%s = %d segundos\n", nome_vencedor, menor_tempo_segundos);

    return 0;
}
