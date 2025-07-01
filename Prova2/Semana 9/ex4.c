#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}

bool inserirElemPilha(PILHA* p, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool excluirElemPilha(PILHA* p, REGISTRO* reg) {
    if (p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

bool ehBalanceado(PILHA* p) {
    char s[MAX];
    fgets(s, MAX, stdin);
    
    int parenteses_abertos = 0, parenteses_fechados = 0;
    int colchetes_abertos = 0, colchetes_fechados = 0;
    int chaves_abertas = 0, chaves_fechadas = 0;
    
    REGISTRO reg;
    
    for (int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '(':
                parenteses_abertos++;
                reg.chave = s[i];
                inserirElemPilha(p, reg);
                break;
            case ')':
                parenteses_fechados++;
                if (p->topo == NULL || p->topo->reg.chave != '(') {
                    return false;
                }
                excluirElemPilha(p, &reg);
                break;
            case '[':
                colchetes_abertos++;
                reg.chave = s[i];
                inserirElemPilha(p, reg);
                break;
            case ']':
                colchetes_fechados++;
                if (p->topo == NULL || p->topo->reg.chave != '[') {
                    return false;
                }
                excluirElemPilha(p, &reg);
                break;
            case '{':
                chaves_abertas++;
                reg.chave = s[i];
                inserirElemPilha(p, reg);
                break;
            case '}':
                chaves_fechadas++;
                if (p->topo == NULL || p->topo->reg.chave != '{') {
                    return false;
                }
                excluirElemPilha(p, &reg);
                break;
        }
    }
    
    // Verifica se todos foram fechados corretamente
    bool balanceado = (parenteses_abertos == parenteses_fechados) &&
                     (colchetes_abertos == colchetes_fechados) &&
                     (chaves_abertas == chaves_fechadas) &&
                     (p->topo == NULL);
    
    return balanceado;
}

int main() {
    PILHA p;
    inicializarPilha(&p);
    
    printf("Digite a expressao: ");
    if (ehBalanceado(&p)) {
        printf("Expressao balanceada!\n");
    } else {
        printf("Expressao NAO balanceada!\n");
    }
    
    return 0;
}
