void selection(Item v[], int l, int r)
{
    int menor;
    for(int i=l; i<r; i++) {
        menor = i;
        for(int j=i+1; j<=r; j++)
            if(v[j] < v[menor])
                menor = j;

        if(i != menor) exch(v[i], v[menor])
        show(v,l,r);
    }
    
}

void selection_r(Item v[], int l, int r)
{
    if(l>r) return;

    int menor = l;
    for(int j=l+1; j<=r; j++)
        if(v[j] < v[menor])
            menor = j;
        
    if(l != menor) exch(v[l], v[menor])

    selection_r(v, l+1, r);
}

void bubble(Item v[], int l, int r)
{
    int swap = 1;
    for(; r>l && swap; r--){
        swap = 0;
        for(int j=l; j<r; j++) {
            if(v[j] > v[j+1]){ 
                exch(v[j], v[j+1])
                swap = 1;
            }
        }
        if(swap) show(v,l,r);
    }
}


void shaker(Item v[], int l, int r)
{

    int swap = 1;
    for(; swap && l<=r; l++, r--){
        swap = 0;
        for(int j=l; j<r; j++) {
            if(v[j] > v[j+1]){ 
                exch(v[j], v[j+1])
                swap = 1;
            }
        }

        for(int j=r; j>l; j--) {
            if(v[j] < v[j-1]){ 
                exch(v[j], v[j-1])
                swap = 1;
            }
        }
    }
}


void insertion_simples(Item v[], int l, int r)
{
    for(int i=l+1; i<=r; i++){
        for(int j=i; j>l && v[j]<v[j-1]; j--)
            exch(v[j], v[j-1])
    }
}

void insertion_otimizado(Item v[], int l, int r)
{
    Item elem;
    int i, j;
    for(i=l+1; i<=r; i++)
    {
        elem = v[i];
        for(j=i; j>l && elem < v[j-1]; j--)
            v[j] = v[j-1]; //puxando o maior
        
        v[j] = elem;          
        //if(i!=j)  show(v, l, r);
    }
}

void insertion_otimizado_pre(Item v[], int l, int r)
{
    Item elem;
    int i, j;

    for(i=r; i>l; i--){
        if(less(v[i], v[l])) exch(v[l],v[i])
    }
      
    for(i=l+2; i<=r; i++)
    {
        elem = v[i];
        for(j=i; elem < v[j-1]; j--)
            v[j] = v[j-1]; 
        
        v[j] = elem; 
    }   
}

void shell(Item v[], int l, int r)
{
    int h = 1, i, j;
    Item elem;  
    while(h < (r-l+1)/3) h = 3*h+1;

    while(h>=1){
        for(i=l+h; i<=r; i++)
        {
            elem = v[i];
            for(j=i; j>=l+h && elem<v[j-h]; j-=h)
            {
                v[j] = v[j-h];
            }
            v[j] = elem;
        }
        h = h/3;
    }
}
