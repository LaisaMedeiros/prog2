#include <stdio.h>
#include <stdlib.h>

char *concatena(char *s1, char *s2){
	
	int tam = strlen(s1) + strlen(s2) + 1;
	char *s3 = (char *)malloc(tam*sizeof(char));
	
	if (!s3){
		printf("Erro de alocação de memória\n");
		return NULL;
	}
	char *ptr = s3;
	
	while (*s1 != '\0'){
		*ptr = *s1;
		ptr++;
		s1++;
	}
	
	while (*s2 != '\0'){
		*ptr = *s2;
		ptr++;
		s2++;
	}
	
	*ptr = '\0';
	
	return s3;
}


int main(){
	
	char *s1, *s2, *s3;
	int tam1, tam2;
	scanf("%d", &tam1);
	scanf("%d", &tam2);
	getchar();
	
	s1 = (char *)calloc(tam1, sizeof(char));
	s2 = (char *)calloc(tam2, sizeof(char));
	if (!s1 || !s2){
		printf ("Erro alocacao memoria");
		return -1;
	}
	gets(s1);
	gets(s2);
	
	s3 = concatena(s1, s2);
	
	printf(s3);
	free(s1);
	free(s2);
	free(s3);
}
