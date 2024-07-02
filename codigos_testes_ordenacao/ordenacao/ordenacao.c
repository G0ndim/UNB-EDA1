//https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html
//https://brunoribas.com.br/apostila-eda/ordenacao-elementar.html
//https://github.com/bcribas/benchmark-ordenacao

#include "ordenacao.h"
#include "ordenacao-elementar.c"
#include "ordenacao-eficiente.c"

void show(Item v[], int l, int r){
    for(int i=l; i<=r; i++){
        printf("%ld ", v[i]);
    }
    printf("\n");
}

int is_sorted(Item v[], int l, int r){
    int p;
    for(p=r; p>l && v[p-1]<=v[p]; p--);

    return (p==l);
}

int cless(const void* v1, const void* v2){
    return *(Item *)v1 < *(Item *)v2;
}

int clesseq(const void* v1, const void* v2){
    return *(Item *)v1 <= *(Item *)v2;
}

//time ./a.out selection < input/10-aleatorio
int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    
    if(argc>2 && atoi(argv[2]) < n) n = atoi(argv[2]);
    printf("%d elementos\n", n);
    
    Item *v = malloc(n*sizeof(Item));
    char **s;
    s = malloc(n*sizeof(char*));
    for(int i=0; i<n; i++) {
        if(!strcmp(argv[1], "radixMSD")){
            s[i] = malloc(101*sizeof(char));
            scanf("%s", s[i]);
        }
        else scanf("%ld", &v[i]);
    }

    if(n<50) 
        show(v, 0, n-1);

    if(argc>1){
        if(!strcmp(argv[1], "shaker"))
            shaker(v, 0, n-1);
        
        else if(!strcmp(argv[1], "bubble"))
            bubble(v, 0, n-1);

        else if(!strcmp(argv[1], "selection"))
            selection(v, 0, n-1);
        else if(!strcmp(argv[1], "selection_r"))
            selection_r(v, 0, n-1);
        
        else if(!strcmp(argv[1], "insertion_s"))
            insertion_simples(v, 0, n-1);
        else if(!strcmp(argv[1], "insertion_o"))
            insertion_otimizado(v, 0, n-1);
        else if(!strcmp(argv[1], "insertion_op"))
            insertion_otimizado_pre(v, 0, n-1);
        
        else if(!strcmp(argv[1], "shell"))
            shell(v, 0, n-1);
        
        else if(!strcmp(argv[1], "merge"))
            merge_sort(v, 0, n-1);
        else if(!strcmp(argv[1], "mergebu"))
            mergeBU_sort(v, 0, n-1);

        else if(!strcmp(argv[1], "quickC")){
            quick_sortC(v, 0, n-1, cless);
            //insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "quickR")){
            quick_sortR(v, 0, n-1, cless);
            //insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "quickL")){
            quick_sortL(v, 0, n-1, cless);
            //insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "quickM3")){
            quick_sortM3(v, 0, n-1, cless);
            //insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "quickM3I")){
            quick_sortM3I(v, 0, n-1, cless);
            //insertion_sort(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "heap")){
            heap_sort(v, 0, n-1); 
        }
        else if(!strcmp(argv[1], "intro")){
            intro_sort(v, 0, n-1, cless); 
        }
        else if(!strcmp(argv[1], "radix")){
            radix_sortLSD(v, 0, n-1);
        }
        else if(!strcmp(argv[1], "radixMSD")){
            radix_sortMSD(s, 0, n-1, 0);

        }
        else if(!strcmp(argv[1], "radixMSDI")){
            radix_sortMSDI(v, 0, n-1, bytesword-1);
        }
        
    }
    
    if(n<50) 
        show(v, 0, n-1);

    if(is_sorted(v, 0, n-1)) printf("ordenado.\n");
    else printf("não ordenado.\n");

    
    return 0;
}



