#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char *dados; 
    int tamanho; 
    int topo;    
} Pilha;

Pilha* criar_pilha(int tamanho) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->dados = (char*)malloc(tamanho * sizeof(char));
    p->tamanho = tamanho;
    p->topo = -1;
    return p;
}

void empilhar(Pilha *p, char c) {
    p->dados[++(p->topo)] = c;
}

char desempilhar(Pilha *p) {
    return p->dados[(p->topo)--];
}

char topo(Pilha *p) {
    return p->dados[p->topo];
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}


char bem_definida(char *cadeia) {
    Pilha *pilha = criar_pilha(100000); 
    int i = 0;
    while (cadeia[i] != '\0') {
        if (cadeia[i] == '(' || cadeia[i] == '[' || cadeia[i] == '{') {
            empilhar(pilha, cadeia[i]);
        } else {
            if (pilha_vazia(pilha)) {
                free(pilha->dados);
                free(pilha);
                return 'N';
            }
            char topo_pilha = desempilhar(pilha);
            if ((cadeia[i] == ')' && topo_pilha != '(') ||
                (cadeia[i] == ']' && topo_pilha != '[') ||
                (cadeia[i] == '}' && topo_pilha != '{')) {
                free(pilha->dados);
                free(pilha);
                return 'N';
            }
        }
        i++;
    }
    if (!pilha_vazia(pilha)) {
        free(pilha->dados);
        free(pilha);
        return 'N';
    }
    free(pilha->dados);
    free(pilha);
    return 'S';
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char cadeia[100001];
        scanf("%s", cadeia);
        char resultado = bem_definida(cadeia);
        printf("%c\n", resultado);
    }

    return 0;
}
