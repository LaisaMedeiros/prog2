//Laisa Tatiana Oliveira de Medeiros

#include <stdio.h>
#include <math.h> // Biblioteca necess�ria para usar a fun��o fabs()

// Fun��o que retorna o �ndice do elemento mais pr�ximo da m�dia
int closest_to_mean_index(int *vetor, int N) {

    // Vari�vel para guardar a soma dos valores do vetor
    int s = 0; 
    for (int i = 0; i < N; i++) {
        s = s + *vetor; // Soma cada elemento do vetor
        vetor++; //n�o pode acessar diretamente os indices
    }

    // Calcula a m�dia convertendo a soma para float para evitar divis�o inteira
    float media = (float)s / N; 

    // Inicia a menor dist�ncia com a diferen�a absoluta entre o 1� elemento e a m�dia
    float dist_min = fabs(*vetor - media);  
    int indice = 0; // �ndice do elemento mais pr�ximo da m�dia

    // Percorre os elementos do vetor para comparar as dist�ncias
    for (int j = 1; j < N; j++) {
    	vetor++;
        dist = fabs(*vetor - media); // Calcula a diferen�a absoluta para a m�dia
        if (dist_min > dist) { // Se encontrar uma dist�ncia menor do que dist_min
            dist_min = dist;   // Atualiza a menor dist�ncia, dist_min
            indice = j;        // Atualiza o �ndice do elemento mais pr�ximo da m�dia
        }
    }
    return indice; // Retorna o �ndice do elemento mais pr�ximo da m�dia
}

int main() {
    
    int N; // Quantidade de elementos do vetor
    scanf("%d", &N); // L� a quantidade de elementos
    
    int v[N]; // Declara um vetor 
    int *ptr = v;
    
    // Preenche o vetor com os valores fornecidos pelo usu�rio
    for (int i = 0; i < N; i++) {
        scanf("%d", ptr);
        ptr++;
    }

    // Exibe o �ndice do elemento mais pr�ximo da m�dia
    printf("%d\n", closest_to_mean_index(v, N));
    return 0; // Encerra o programa com sucesso
}

