#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

typedef struct no{
    char str;
    struct no *prox;
} no;

typedef struct pilha{
    no *inicio;
    int cont;
}pilha;

void inicializa_pilha(pilha *p){
    p->inicio = NULL;
    p->cont = 0;
}

no *cria_no(char str){
    no *novo = malloc(sizeof(no));
    novo->prox = NULL;
    novo->str = str;
    return novo;
}

void empilha(pilha *p, char str){
    no *novo = cria_no(str);
    novo->prox = p->inicio;
    p->inicio = novo;
    p->cont++;
}

int desempilha(pilha *p){
    if(p->inicio == NULL){
        return 0;
    }
    p->inicio = p->inicio->prox;
    p->cont--;
    return 1;
}

int pilha_vazia(pilha *p){
    return p->inicio == NULL;
}

char topo(pilha *p){
    return p->inicio->str;
}

void analisa_config(pilha *p, char *str){
    int i = 0;
    while (str[i] != '\0')
    {
        if (!pilha_vazia(p))
        {
            char top = topo(p);
            if ((str[i] == '*' && top == '*') || (str[i] == '/' && top == '/') || (str[i] == '_' && top == '_'))
            {
                desempilha(p);
                i++;
                continue;
            }
        }
        if (str[i] == '*' || str[i] == '/' || str[i] == '_')
        {
            empilha(p, str[i]);
            i++;
            continue;
        }
        i++;
    }
    
}

int main(void){
    int n;
    scanf("%d", &n);

    pilha p;
    inicializa_pilha(&p);
    
    for (int i = 0; i < n; i++)
    {
        char str[MAX];
        getchar();
        scanf("%[^\n]", str);
        analisa_config(&p, str);
    }
    
    if (pilha_vazia(&p))
    {
        printf("C\n");
    }
    else
    {
        printf("E\n");
    }

    return 0;
}