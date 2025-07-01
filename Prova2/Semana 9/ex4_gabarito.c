#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef char TIPOCHAVE;
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
bool estaVazia(PILHA *p)
{
    if (p->topo == NULL)
        return true;
    return false;
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

bool combinam(char c1, char c2) {
    return (c1 == ')' && c2 == '(') || (c1 == ']' && c2 == '[') || (c1 == '}' && c2 == '{');
}

bool ehBalanceado(char expressao[]) {
    PILHA p;
    inicializarPilha(&p);
    REGISTRO reg;
    int i = 0;
    while (expressao[i] != '\0') {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            reg.chave = expressao[i];
            inserirElemPilha(&p, reg);
        } 
        else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (!excluirElemPilha(&p, &reg) || !combinam(expressao[i], reg.chave)) {
                return false;
            }
        }
        i++;
    }

    if(estaVazia(&p)) 
        return true;
    
    reinicializarPilha(&p);
    return false;
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    ehBalanceado(s) ? printf("Balanceada\n") : printf("Desbalanceada\n");
}