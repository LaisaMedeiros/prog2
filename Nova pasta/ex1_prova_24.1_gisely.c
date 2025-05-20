#include <stdio.h>
#include <stdlib.h>

int *f(int x, int y, int *p, int *z){
	int *w; //declara um ponteiro w para um inteiro
	(*p)++; //o valor de c `somado em 1, ou seja, c = 51
	*p = y; //c = 7
	x+= 10; //x = 20
	//reserva um espaço de memória de tamanho int e retorna o enderço do espaço resrevado
	//w é um endereço
	//como a mem´pria alocada por malloc não é inicializada o valor de w é lixo de memória
	w = (int *)malloc(sizeof(int)); //cria um enderço válido para w apontar
	
	//para a memória vir com zeros 
	//w = (int *)calloc(1,sizeof(int));
	
	(*p)+= y; //*p = *p + y = 7 + 7 = 14, ou seja, c = 14
	*w = *p +5; //*w = 19
	*z++ = x; //d[0]=20 e z passa a apontar para d[1]
	x-=50; //x = -30
	p = &x; //*p = -30
	p = &y; //*p = 7
	(*p)--; //y = 6
	*z+=y; //d[1] = d[1] + 6 = 8
	y*=10; // y = 6*10 = 60
	*++z = *p; //*z = d[2] = 60
	return w; //*w = 19 
}

int main(){
	int a = 10, b = 7, c = 50, d[3] = {1,2,3};
	int *e = f (a,b,&c,d);
	printf("a = %d, b = %d c = %d *e = %d\n", a, b, c, *e); //a = 10 b = 7 c = 14 *e = 19
	for (int i = 0; i < 3; i++){
		printf("d[%i] = %d\n", i, d[i]); //d[0] = 20, d[1] = 8, d[2] = 60
	}
	free(e);
	return 0;
}
