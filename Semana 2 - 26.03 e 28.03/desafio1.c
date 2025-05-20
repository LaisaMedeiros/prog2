//Laisa Tatiana Oliveira de Medeiros

#include <stdio.h>
#include <math.h> // Biblioteca necessária para usar a função fabs()

// Função que retorna o índice do elemento mais próximo da média
int closest_to_mean_index(int *vetor, int N) {

    // Variável para guardar a soma dos valores do vetor
    int s = 0; 
    for (int i = 0; i < N; i++) {
        s = s + *vetor; // Soma cada elemento do vetor
        vetor++; //não pode acessar diretamente os indices
    }

    // Calcula a média convertendo a soma para float para evitar divisão inteira
    float media = (float)s / N; 

    // Inicia a menor distância com a diferença absoluta entre o 1º elemento e a média
    float dist_min = fabs(*vetor - media);  
    int indice = 0; // Índice do elemento mais próximo da média

    // Percorre os elementos do vetor para comparar as distâncias
    for (int j = 1; j < N; j++) {
    	vetor++;
        dist = fabs(*vetor - media); // Calcula a diferença absoluta para a média
        if (dist_min > dist) { // Se encontrar uma distância menor do que dist_min
            dist_min = dist;   // Atualiza a menor distância, dist_min
            indice = j;        // Atualiza o índice do elemento mais próximo da média
        }
    }
    return indice; // Retorna o índice do elemento mais próximo da média
}

int main() {
    
    int N; // Quantidade de elementos do vetor
    scanf("%d", &N); // Lê a quantidade de elementos
    
    int v[N]; // Declara um vetor 
    int *ptr = v;
    
    // Preenche o vetor com os valores fornecidos pelo usuário
    for (int i = 0; i < N; i++) {
        scanf("%d", ptr);
        ptr++;
    }

    // Exibe o índice do elemento mais próximo da média
    printf("%d\n", closest_to_mean_index(v, N));
    return 0; // Encerra o programa com sucesso
}

