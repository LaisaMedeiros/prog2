int descubra(int vet[], int n, int k) {
	int x=0, y=0;
	for(int i=0; i<n; i++){
		if(vet[i]<k){ //comparacao 1
			x+=vet[i];
		}
		if(vet[i]>k){ //compara��o 2
			y+=vet[i];
		}
	
	return y-x; 
}

//a) O que essa fun��o retorna?
//R: Considerando n como o tamanho do vetor, no primeiro if se vet[i] � menor que o elmento k 
// x recebe o valor de vet[i], pois � x = x + vet[i] e x = 0. A cada loop x em que esse primeiro if
// � verdade x recebe o valor de vet[i] somando ao seu sucessor de como que todos sejam menores que k. 
// Ent�o x � a soam de valores do vetor vet menos que k.J� y � segue a mesma l�gica, mas para os elementos 
//maiores do que k. O retorno da fun��o � a soma dos elemntos maiores do que k substraida da soma dos elementos
//menosres que k. 

//b) n vezes, uma vez para cada elemento do vetor, em cada itera��o do loop for

//c) n vezes, uma vez para cada elemento do vetor, em cada itera��o do loop for

//d) H� 2.n compara��es. S�o feitas 2 compara��es por elemento (vet[i]<k e vet[i]>k). 
//O loop executa n vezes (uma para cada elemento)
