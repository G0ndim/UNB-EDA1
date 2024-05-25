#include<stdio.h>


int main(){
    int caminhao, stack[1001], topo=-1, i;
    int n,exp=1;
    
    char ans;
    
    while(1){
    ans='y';topo=-1;
    exp=1;
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<n;i++){
        scanf("%d",&caminhao);
        if(caminhao!=exp){
        stack[++topo]=caminhao;
        }
        else{
        exp++;
        if(topo!=-1){
            while(stack[topo]==exp){
            exp++;topo--;
            if(topo==-1)break;
            }
        }
        }
    }
    while(topo>=0){
        if(stack[topo]!=exp) ans='n';
        topo--;
        exp++;
    }
    if (ans=='y')printf("yes\n");
    else printf("no\n");
    }
    
    return 0;
}