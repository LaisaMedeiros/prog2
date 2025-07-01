
//Bubble sort
void bolha(int v[], int tam){
	int ult, i, aux;
	//começa do final em ult e vai diminuindo um
	//compara dois a dois até o maior numero ir pro final
	for (ult=tam-1; ult>0; ult--){
		//vai pro inicio 
		for (i=0; i<ult; i++){
			//compara dois numeros um ao lado do outro
			if (v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux; 
			}
		}
	}
}

//Insertion Sort
//começa no segundo elemento, e vai até o último
//compara cada elemento com seus anteriores
//inseri o numero no lugar certo
void insercao(int v[], int tam){
	int i, aux, j;
	for (i=1; i<tam; i++) {
		
		aux=v[i];
		j=i;
		
		while ((j>0)&&(aux<v[j-1])){
			v[j] = v[j-1];
			j--; 
		}
		
		v[j] = aux; 
	}	
}

//Exemplo 9 8 4 6 3
//aux = 8; j = 1; 
//j>0 SIM; 8 < 9 SIM [9, 9, 8, 4, 6, 3] sai do loop
//v[0] = 8   [8, 9, 4, 6, 3]

//i = 2; aux = 4; j = 2;
//j> 0 SIM; 4 < 9 SIM [8, 9, 9, 6, 3] j = 1
// j > 0 SIM; 4 < 8 SIM [8, 8, 9, 6, 3]
// j = 0; acabou o loop [4,8,9,6,3]

//Ordem decrescente
//aux = 6; i = 3; j = 3
//j >0 SIM; 6 > 4? SIM [9 8 4 4 3]
//


void selecao(int v[], int tam) {
	int i, p, aux, posMenor;
	for (i=0; i<tam-1; i++) {
		posMenor = i;
		
		//encontra o menor elemento
		for (p=i+1; p<tam; p++){
			if (v[p] < v[posMenor])
				posMenor = p;
		}
		if (v[posMenor] < v[i]){
			aux = v[i];
			v[i] = v[posMenor];
			v[posMenor] = aux;
		}
	} 
}


