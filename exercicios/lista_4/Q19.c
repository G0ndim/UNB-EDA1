#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int codigo;
    int valor;
} Item;

typedef struct fila{
    Item *dados;
    int inicio;
    int fim;
    int tamanho;
    int ocupados;
} fila;

void inicializa_fila(fila *f, int tam){
    f->dados = malloc(sizeof(Item) * tam);
    f->tamanho = tam;
    f->inicio = -1;
    f->fim = 0;
    f->ocupados = 0;
}

int enfileira(fila *f, Item i){
    if (f->ocupados == f->tamanho){
        return 0;
    }
    
    f->dados[f->fim] = i;
    f->fim = (f->fim + 1) % f->tamanho;
    f->ocupados++;
    return 1;
}

int desenfileira(fila *f){
    if (f->ocupados == 0)
    {
        return 0;
    }

    f->ocupados--;
    f->inicio = (f->inicio + 1) % f->tamanho;
    return 1;
}

Item primeiro_elemento(fila *f){
    return f->dados[(f->inicio + 1) % f->tamanho];
}

int fila_vazia(fila *f){
    return f->ocupados == 0;
}

void libera_memoria(fila *f){
    free(f->dados);
    f->tamanho = 0;
}

int main(void){
    int p, r, cont = 1;

    while (scanf("%d %d", &p, &r) && (r != 0 && p != 0))
    {
        fila Fila;
        inicializa_fila(&Fila, p);

        for (int i = 0; i < p; i++)
        {
            int codigo;
            scanf("%d", &codigo);
            Item i = {codigo, 0};
            enfileira(&Fila, i);
        }
        
        int comando;
        for (int  i = 0; i < r; i++)
        {
            scanf("%*d %d", &comando);
            fila aux;
            inicializa_fila(&aux, (&Fila)->ocupados);

            while (!fila_vazia(&Fila))
            {
                Item x = primeiro_elemento(&Fila);
                scanf(" %d", &((&x)->valor));
                if ((&x)->valor == comando)
                {
                    enfileira(&aux, x);
                }
                desenfileira(&Fila);
            }
            
            while (!fila_vazia(&aux))
            {
                Item y = primeiro_elemento(&aux);
                enfileira(&Fila, y);
                desenfileira(&aux);
            }
            libera_memoria(&aux);
        }
        Item ganhador = primeiro_elemento(&Fila);
        printf("Teste %d\n%d\n\n", cont, ganhador.codigo);
        libera_memoria(&Fila);
        cont++;
    }
}