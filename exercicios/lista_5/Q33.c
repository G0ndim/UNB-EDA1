#include <stdio.h>

int n,m;
long long int r[100010];

int busca_bin(long long int val){
	int start = 1;
	int end = n;
	if(val > r[n])	return 0;
	
	while(start < end){
		int meio = (start + end) / 2;
		
		if(r[meio] >= val){
			end = meio;
		}
		else{
			start = meio+1;
		}
	}
	return n + 1 - end;
}


int main(){
  
	scanf("%d %d",&n, &m);
	
	for(int i = 1; i <= n; i++){
		scanf("%lld",&r[i]);
		r[i] = r[i] * r[i];
	}
	
	long long int resp = 0;
	
	for(int i = 1; i <= m; i++){	
		long long int x,y;
		scanf("%lld %lld",&x,&y);

		resp += busca_bin(x*x+y*y);
	}

	printf("%lld\n",resp);

	return 0;
}
