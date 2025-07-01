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
    PONT inicio;
} LISTA;

void concatenaListas(LISTA *l1, LISTA *l2) {
    if(l1->inicio == NULL) {
        l1->inicio = l2->inicio;
    }
    ELEMENTO *pos = l1->inicio;
    while(pos->prox != NULL) {
        pos = pos->prox;
    }
    pos->prox = l2->inicio;
}

bool iguaisListas(LISTA *l1, LISTA *l2) {
    ELEMENTO *pos1 = l1->inicio;
    ELEMENTO *pos2 = l2->inicio;

    while (pos1 != NULL && pos2 != NULL) {
        if (pos1->reg.chave != pos2->reg.chave) {
            return false;
        }
        pos1 = pos1->prox;
        pos2 = pos2->prox;
    }
    return pos1 == NULL && pos2 == NULL;
}

bool modificaElem(LISTA *l, REGISTRO reg, int pos) {
    ELEMENTO *atual = l->inicio;
    int count = 0;
    while (atual != NULL) {
        if (count == pos) {
            atual->reg = reg;
            return true;
        }
        atual = atual->prox;
        count++;
    }
    return false;
}