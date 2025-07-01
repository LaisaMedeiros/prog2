#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
    //outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;
void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}
int tamanho(FILA* f) {
    ELEMENTO* end = f->inicio;
    int tam = 0;
    while (end != NULL) {
    tam++;
    end = end->prox; }
    return tam; 
}

void exibirFila(FILA* f) {
    ELEMENTO* end = f->inicio;
    printf("Fila: \" ");
    while (end != NULL) {
    printf("%i ", end->reg.chave);
    end = end->prox; }
    printf("\"\n"); 
}

bool inserirNaFila(FILA* f,REGISTRO reg) {
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio==NULL) return false;
    *reg = f->inicio->reg;
    ELEMENTO* apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL) f->fim = NULL;
    return true; 
}

void reinicializarFila(FILA* f) {
    ELEMENTO* end = f->inicio;
    while (end != NULL) {
    ELEMENTO* apagar = end;
    end = end->prox;
    free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main(){
    FILA f_par;
    FILA f_impar;
    REGISTRO N;
    inicializarFila(&f_par);
    inicializarFila(&f_impar);
    scanf("%d", &N.chave);
    while (N.chave != 0){
        if (N.chave % 2 == 0){
            inserirNaFila(&f_par, N);
        }
        else{
            inserirNaFila(&f_impar, N);
        }
        scanf("%d", &N.chave);
    }
    int tam = tamanho(&f_par) + tamanho(&f_impar);
    
    while (tamanho(&f_par) || tamanho(&f_impar)){

        if (excluirDaFila(&f_impar, &N)){
            printf("%d", N.chave);
        }
        if (excluirDaFila(&f_par, &N)){
            printf("%d", N.chave);
        }
    }
    return 0;
}

ex1.c
Exibindo ex1.c.
