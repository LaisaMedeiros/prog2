int descubra(int vet[], int n, int k) {
	int x=0, y=0;
	for(int i=0; i<n; i++){
		if(vet[i]<k){ //comparacao 1
			x+=vet[i];
		}
		if(vet[i]>k){ //comparação 2
			y+=vet[i];
		}
	
	return y-x; 
}

//a) O que essa função retorna?
//R: Considerando n como o tamanho do vetor, no primeiro if se vet[i] é menor que o elmento k 
// x recebe o valor de vet[i], pois é x = x + vet[i] e x = 0. A cada loop x em que esse primeiro if
// é verdade x recebe o valor de vet[i] somando ao seu sucessor de como que todos sejam menores que k. 
// Então x é a soam de valores do vetor vet menos que k.Já y é segue a mesma lógica, mas para os elementos 
//maiores do que k. O retorno da função é a soma dos elemntos maiores do que k substraida da soma dos elementos
//menosres que k. 

//b) n vezes, uma vez para cada elemento do vetor, em cada iteração do loop for

//c) n vezes, uma vez para cada elemento do vetor, em cada iteração do loop for

//d) Há 2.n comparações. São feitas 2 comparações por elemento (vet[i]<k e vet[i]>k). 
//O loop executa n vezes (uma para cada elemento)
