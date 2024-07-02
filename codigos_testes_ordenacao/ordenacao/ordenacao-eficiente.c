void merge(Item *v,  int l, int m, int r)
{
    int tam = r+1-l;
    Item *aux = malloc(sizeof(Item)*tam);
    
    int i=l; 
    int j=m+1;
    int k=0; 
    
    while(i<=m && j<=r) {
        if(v[i] <= v[j]) 
            aux[k++] = v[i++];
        else 
            aux[k++] = v[j++];
    }

    while(i<=m) aux[k++] = v[i++];
    while(j<=r) aux[k++] = v[j++];

    /*
        while(k<tam) {
            if(i>m)
                aux[k++] = v[j++];

            else if (j>r)
                aux[k++] = v[i++];

            else if (v[i] <= v[j])
                aux[k++] = v[i++];
            else
                aux[k++] = v[j++];
        }
    */

    for(k=0, i=l; i<=r; i++, k++)
        v[i] = aux[k];
        
    free(aux);
}

void merge_sort(Item *v, int l, int r)
{

    if (l >= r) return;
    //if (r-l <= 15) {
      //  insertion_otimizado(v, l, r);
      //  return;
   // }
    int m = (r+l)/2;
    
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    
    if(v[m]>v[m+1]) 
        merge(v, l, m, r); 
}

void mergeBU_sort(Item *v, int l, int r)
{    
    int tam = (r-l+1);

    for (int sz=1; sz<tam; sz=sz+sz)
    {
        for (int lo=l; lo<tam-sz; lo+=sz+sz)
        {
            int hi = lo+sz+sz-1;
            if(hi>tam-1) hi = tam-1;

            merge(v, lo, lo+sz-1, hi); 
        }
    }
}


int partitionCORMEM(Item *v, int l, int r, int (*comp)(const void*, const void*))
{
    Item pivot = v[r];
    int j = l;
    for(int i=l; i<r; i++)
    {
        if(comp(&v[i],&pivot)){
            exch(v[i], v[j]);
            j++;
        }
    }

    exch(v[r], v[j]);

    return j;
}

int partitionRSEDGEWICK(Item *v, int l, int r, int (*comp)(const void*, const void*))
{
    int i=l-1, j=r;
    Item pivot = v[r];
    
    /*while(1)
    {
        while(comp(v[++i], pivot));
        while(comp(pivot, v[--j])) if(j==l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }*/
    while(i<j)
    {
        while(comp(&v[++i], &pivot) && i<r);
        while(comp(&pivot, &v[--j]) && j>l);
        if(i<j) exch(v[i], v[j]);
        //show(v,l,r);
    }
    exch(v[i], v[r]);
    
    return i;
}

int partitionLSEDGEWICK(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{  
	int i = l;
	int j = r+1;
	Item pivo = v[l];

    /*while (1)
    {
        while (comp(v[++i], pivo)) if (i == r) break;
        while (comp(pivo, v[--j])) if (j == l) break;
        if (i >= j) break;
        
        exch(v[i], v[j]);
    }*/
    while (i < j)
    {
        while (comp(&v[++i], &pivo) && i < r);
        while (comp(&pivo, &v[--j]));
        
        if (i < j)
          exch(v[i], v[j]);
    }
    exch(v[l], v[j]);//atualiza a posicao do pivot

    return j;

}


void quick_sortC(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{
    if(r<=l) return;
    //if(r-l<=15) return; 
    //if(r-l<=15) return insertion_sort(v, l, r);

    int p = partitionCORMEM(v, l, r, comp);
    
	quick_sortC(v, l, p-1, comp);
	quick_sortC(v, p+1, r, comp);
}

void quick_sortR(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{
    if(r<=l) return;
    //if(r-l<=15) return;
    //if(r-l<=15) return insertion_sort(v, l, r);

    int p = partitionRSEDGEWICK(v, l, r, comp);
    
	quick_sortR(v, l, p-1, comp);
	quick_sortR(v, p+1, r, comp);
}


void quick_sortL(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{
    if(r<=l) return;
    //if(r-l<=15) return;
    //if(r-l<=15) return insertion_sort(v, l, r);

    int p = partitionLSEDGEWICK(v, l, r, comp);
    
	quick_sortL(v, l, p-1, comp);
	quick_sortL(v, p+1, r, comp);
}


void quick_sortM3(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{
    if(r<=l) return;
    //if(r-l<=15) return;
    //if(r-l<=15) return insertion_sort(v, l, r);

    compexch(v[l], v[(l+r)/2]);
    compexch(v[l], v[r]);
    compexch(v[r], v[(l+r)/2]);

    int p = partitionRSEDGEWICK(v, l, r, comp);

	quick_sortM3(v, l, p-1, comp);
	quick_sortM3(v, p+1, r, comp);
}


void quick_sortM3I(Item *v,  int l, int r, int (*comp)(const void*, const void*))
{
    //if(r<=l) return;
    //if(r-l<=15) return;
    if(r-l<=15) return insertion_sort(v, l, r);
    
    exch(v[(l+r)/2], v[r-1]);
    compexch(v[l], v[r-1]);
    compexch(v[l], v[r]);
    compexch(v[r-1], v[r]);

    int p = partitionRSEDGEWICK(v, l+1, r-1, comp);
	quick_sortM3I(v, l, p-1, comp);
	quick_sortM3I(v, p+1, r, comp);
}


void fixDown(int k, int N)
{
    int j;    
    while(2*k <= N) {
        j = 2*k;

        if(j<N && less(pq[j], pq[j+1])) j++;
        if(!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}


void heap_sort(Item *v, int l, int r)
{
    pq = v+l-1;
    N = r-l+1;
    for(int k=N/2; k>=1; k--) {
        fixDown(k, N);
    }
    
    while(N>1) {
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}


void intro(Item *v,  int l, int r, int maxdepth, int (*comp)(const void*, const void*)){ 
    if(r-l<=15){
        insertion_sort(v, l, r);
        return;
    }
    if(maxdepth == 0) {
         merge_sort(v, l, r);
        //heap_sort(v, l, r);

    } else {
        exch(v[(l+r)/2], v[r-1]);
        compexch(v[l], v[r-1]);
        compexch(v[l], v[r]);
        compexch(v[r-1], v[r]);

        int p = partitionRSEDGEWICK(v, l+1, r-1, comp);
	
        intro(v, l, p-1, maxdepth-1, comp);
        intro(v, p+1, r, maxdepth-1, comp);
    }
}

void intro_sort(Item *v,  int l, int r, int (*comp)(const void*, const void*)){
    int maxdepth = 2*((int)log2((double)(r-l+1)));
    //int maxdepth = ((int)log2((double)(r-l+1)));
    intro(v, l, r, maxdepth, comp);
    //insertion_sort(v, l, r);
}

void radix_sortLSD(Item *v, int l, int r)
{   
    Item *aux = malloc((r-l+1)*sizeof(Item));
    
    int i, w;
    int count[R+1];
    
    //w -> deslocamento de bytes
    //for(w=bytesword-1; w>=0; w--){
    for(w=0; w<bytesword; w++){
        //memset(count, 0, sizeof(int)*(R+1));
        for(i=0; i<R; i++) count[i] = 0;

        for(i=l; i<=r; i++)
            count[digit(v[i], w)+1]++;   

        for(i=0; i<R; i++)
            count[i+1] += count[i];
        

        for(i=l; i<=r; i++)
            aux[count[digit(v[i], w)]++] = v[i];

        for(i=l; i<=r; i++)
            v[i] = aux[i-l]; 
    }
    //for(i=l; i<=r; i++){
      //  printf("%ld\n", v[i]);
   // }
}

//Inteiros: ordena o w-ésimo byte
void radix_sortMSDI(Item *v,  int l, int r, int w) {
    if(r<=l || w<0) return;
    int i, count[R+2];
    Item *aux = malloc((r-l+1)*sizeof(Item));
    memset(count, 0, sizeof(int)*(R+2));
    
    for(i=l; i<=r; i++)
        count[digit(v[i], w)+2]++;
    
    for(i=0; i<R+1; i++)
        count[i+1] += count[i];

    for(i=l; i<=r; i++)
        aux[count[digit(v[i], w)+1]++] = v[i];

    for(i=l; i<=r; i++) v[i] = aux[i-l];
  
    for (i = 0; i < R; i++)
      radix_sortMSDI(v, l + count[i], l + count[i+1]-1, w-1);
}

//Sem identificação de fim de string
int charAt(char s[], int d) {
  if (d < strlen(s)) 
    return s[d]; //d-ésimo caractere
  else 
    return -1; //count[-1 + 1] = count[0]
               //count[0] = qtde. de palavras menores que d
}

void radix_sortMSD(char *v[], int l, int r, int w) 
{ 
    if(r<=l) return;

    int i, count[R+2];
    char **aux = malloc((r-l+1)*sizeof(char*));

    memset(count, 0, sizeof(int)*(R+2));

    for(i=l; i<=r; i++){
        count[v[i][w]+2]++;
    }

    for(i=0; i<R; i++){
        count[i+1] += count[i];
    }

    for(i=l; i<=r; i++){
        aux[count[v[i][w]+1]] = malloc(101*sizeof(char));
        strcpy(aux[ count[ v[i][w]+1 ]++], v[i]);
    }
    
    for(i=l; i<=r; i++){
        strcpy(v[i], aux[i-l]);
        free(aux[i-l]);
    }
    free(aux);
    
    for (i = 1; i <R; i++){
        radix_sortMSD(v, l + count[i], l + count[i+1]-1, w+1);
    }
    
}
