#include <stdio.h>
#include <stdlib.h>

void ultrapassa(int v[], int tam, int vc){
  int soma = 0;
  int ultimo[tam];
  int index = 0;

  for(int i = 0; i < tam; i++){
    ultimo[i] = 0;
  }

  for(int i=0; i < tam; i++){
    soma += v[i];
    
    if(soma > vc){
      ultimo[index] = v[i];
      index++;
      soma = 0;
    }
  }

  for(int i=tam-1; i >= 0; i--){
    if(ultimo[i] != 0){
      printf("%d\n", ultimo[i]);
    }
  }

}


int main(){

  int *v;

  v = (int *) malloc(sizeof(int));

  int valor, tamanho = 0;
  do {
        scanf("%d", &valor);
        if (valor != 0) {
            tamanho++; // Incrementa o tamanho do vetor
            v = (int*)realloc(v, tamanho * sizeof(int)); // Realoca memória para acomodar o novo valor
            v[tamanho - 1] = valor; // Armazena o valor no vetor
        }
    } while (valor != 0);

  int valor_2;
  scanf("%d", &valor_2);

  ultrapassa(v, tamanho, valor_2);

  free(v);
  return 0;
}