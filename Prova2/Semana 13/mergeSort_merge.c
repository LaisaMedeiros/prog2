
//Mescla duas sublistas: uma que vai de p até q e outra que vai de q+1 até r
void merge(int A[], int p, int q, int r) {
	int i, j, k; //indices para percorrer as listas
	int tamseq1 = q - p + 1; //tamanho da sequencia 1
	int tamseq2 = r - q;     //tamanho da sequencia 2
	
	//cria a pirmiera sublista e agurda em seq1
	int seq1[tamseq1];
	for(i=0; i < tamseq1; i++){
		seq1[i] = A[p+i];
	}
	
	//cria a segunda sublista e guarda em seq2
	int seq2[tamseq2];
	for(j=0; j < tamseq2; j++){
		seq2[j] = A[q+1+j];
	}
	
	//esse loop roda até uma das sequências chegar ao fim
	//Compara os elementos das duas sublistas e coloca o menor em A[k].
	k = p; i = 0; j = 0;
	while (i < tamseq1 && j < tamseq2){
		if(seq2[j] <= seq1[i]) {
			A[k] = seq2[j];
			j++; 
		}
		
		else {
			A[k] = seq1[i];
			i++; 
		}
		
		k++;
	}
	// Copia os elementos restantes da sublista 1, caso ainda existam.
	while (i < tamseq1) {
		A[k] = seq1[i];
		k++;
		i++;
	}
	
	//Copia os elementos restantes da sublista 2, caso ainda existam.
	while (j < tamseq2) {
		A[k] = seq2[j];
		k++;
		j++;
	}
}

//são selecionados dois subarranjos já ordenados
//Função recursiva que ordena o vetor numeros do índice ini até fim.
void mergeSort(int numeros[], int ini, int fim) {
	int meio;
	if(ini < fim) {
	meio = (ini + fim)/2;  //Divide o vetor ao meio, se ainda tiver mais de um elemento.
	
	//Aplica mergeSort recursivamente na metade esquerda e depois na metade direita.
	mergeSort(numeros, ini, meio); 
	mergeSort(numeros, meio+1, fim);
	
	//Após dividir e ordenar as duas metades, chama merge para uni-las de forma ordenada.
	merge(numeros, ini, meio, fim);
	}
}

