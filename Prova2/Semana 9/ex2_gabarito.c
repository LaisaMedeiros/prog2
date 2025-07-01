#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;
typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;
typedef ELEMENTO *PONT;
typedef struct
{
    PONT topo;
} PILHA;
void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}
bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL)
        return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}
bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
    if (p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}
void reinicializarPilha(PILHA *p)
{
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL)
    {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

void calculo(char operador, PILHA *p) {
    REGISTRO reg, reg1, reg2;
    excluirElemPilha(p, &reg1);
    excluirElemPilha(p, &reg2);

    switch (operador) {
        case '*': 
            reg.chave = reg2.chave * reg1.chave; 
            printf("%d * %d = %d \n", reg2.chave, reg1.chave, reg.chave);
            break;
        case '-': 
            reg.chave = reg2.chave - reg1.chave; 
            printf("%d - %d = %d \n", reg2.chave, reg1.chave, reg.chave);
            break;
        case '+': 
            reg.chave = reg2.chave + reg1.chave; 
            printf("%d + %d = %d \n", reg2.chave, reg1.chave, reg.chave);
            break;
        case '/': 
            reg.chave = reg2.chave / reg1.chave;
            printf("%d / %d = %d \n", reg2.chave, reg1.chave, reg.chave);
            break;
    }

    inserirElemPilha(p, reg);
}

int calculadora(char s[]) {
    int i = 0;
    PILHA p;
    inicializarPilha(&p);
    REGISTRO reg;
    while(s[i] != '\0' && s[i] != '\n') {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[i] <= '9' && s[i] >= '0') {
            reg.chave = s[i] - '0';
            inserirElemPilha(&p, reg);
        } else {
            calculo(s[i], &p);
        }
        i++;
    }
    int n = p.topo->reg.chave;
    reinicializarPilha(&p);
    return n;
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    printf("Resultado: %d\n", calculadora(s));
}