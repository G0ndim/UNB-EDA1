#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int votos;
} Item;

#define codigo(A) (A.codigo)
#define votos(A) (A.votos)
#define less(A, B) ((votos(A) == votos(B)) ? (codigo(A) > codigo(B)) : (votos(A) > votos(B)))
#define exch(A, B) {Item t; t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++) {
        if (less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quicksort(Item *v, int l, int r){
    int j;
    if (r <= l) return;

    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);

    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int main(){
    int sen, dfederal, destadual;
    scanf("%d %d %d", &sen, &dfederal, &destadual);

    int candidato;

    Item *presidente = calloc(100, sizeof(Item));
    Item *senador = calloc(1000, sizeof(Item)) ;
    Item *deputadof = calloc(10000, sizeof(Item)) ;
    Item *deputadoe = calloc(100000, sizeof(Item));

    int validos = 0;
    int invalidos = 0;
    int total_pres = 0;

    while (scanf("%d", &candidato) == 1) {
        if (candidato > 0) {
            validos++;
            if (candidato >= 10000) {
                if (deputadoe[candidato].codigo == 0) {
                    deputadoe[candidato].codigo = candidato;
                }
                deputadoe[candidato].votos++;
            }
            
            else if (candidato >= 1000){
                if (deputadof[candidato].codigo == 0) {
                    deputadof[candidato].codigo = candidato;
                } 
                deputadof[candidato].votos++;
            }

            else if (candidato >= 100){
                if (senador[candidato].codigo == 0) {
                    senador[candidato].codigo = candidato;
                } 
                senador[candidato].votos++;
            }
            else{
                if (presidente[candidato].codigo == 0) {
                    presidente[candidato].codigo = candidato;
                }
                presidente[candidato].votos++;
                total_pres++;
            }
        }
        else invalidos++;
    }
    
    int aux = 0;
    for (int i = 0; i < 100; i++)
        if (presidente[i].votos)
            presidente[aux++] = presidente[i];
    quicksort(presidente, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 1000; i++)
        if (senador[i].votos)
            senador[aux++] = senador[i];
    quicksort(senador, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 10000; i++)
        if (deputadof[i].votos)
            deputadof[aux++] = deputadof[i];
    quicksort(deputadof, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 100000; i++)
        if (deputadoe[i].votos)
            deputadoe[aux++] = deputadoe[i];
    quicksort(deputadoe, 0, aux);

    printf("%d %d\n", validos, invalidos);

    if ((float) presidente[0].votos/total_pres >= 0.51)
        printf("%d\n", presidente[0].codigo);
    else
        printf("Segundo turno\n");
    
    for (int i = 0; i < sen; i++)
        printf("%d ", senador[i].codigo);   
    printf("\n");

    for (int i = 0; i < dfederal; i++)
        printf("%d ", deputadof[i].codigo);   
    printf("\n");

    for (int i = 0; i < destadual; i++)
        printf("%d ", deputadoe[i].codigo);   
    printf("\n");
    
    free(presidente);
    free(senador);
    free(deputadof);
    free(deputadoe);

    return 0;
}