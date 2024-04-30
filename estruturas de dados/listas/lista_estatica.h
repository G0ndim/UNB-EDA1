#ifndef VETOR
#define VETOR

// procura x em um vetor v[] de tamanho n
int busca_v (int x, int v[], int n){
  int k = n - 1;
  while (k >= 0 && v[k] != x) k--;
  return k;
}
// versao recursiva
int busca_v_r(int x, int v[], int n){
  if (n == 0) return -1;
  if (x == v [n - 1]) return n-1;
  
  return busca_v_r (x, v, n-1);
}


// remove o v[k] e o retorna
int remove_v(int k , int v[], int n){
  int x = v[k], j;

  for(j = k+1; j < n; j++){
    v[j-1] = v[j];
  }

  return x;
}

// versao recursiva
int remove_v_r(int k, int v[], int n){
  int x = v[k];
  if(k < n -1){
    v[k] = remove_v_r(k+1, v, n);
  }
  return x;
}


// Insere x em v[k] de tamanho n. Obs: o vetor nn pode estar cheio 
void insere_v(int x, int k, int v[], int n){
  for(int j = n-1; j > k; --j){
    v[j] = v[j-1];
  }

  v[k] = x;
}

// versao recursiva
void insere_v_r(int x, int k, int v[], int n){
  if(k == n-1){
    v[k] = x;
  }
  else{
    v[n-1] = v[n-2];
    insere_v_r(k, x, v, n - 1);
  }
}


// exercicios

/*
Um subvetor de um vetor v é o que sobra depois que
alguns dos elementos de v são apagados.
2 Por exemplo , 12 13 10 3 é um subvetor de 11 12 13
11 10 9 7 3 3 mas não de 11 12 10 11 13 9 7 3 3.
3 Escreva uma função que decida se x [0.. m - 1] é subvetor
de v [0.. n - 1]. 
*/

int subvetor(int v[], int n, int x[], int m);


/*
Suponha que um vetor v [1.. n ] cont é m uma permutação de 1.. n .
2 Escreva uma função que inverta essa permuta ç ã o : se v
[ i ] = j no vetor original ,queremos ter v[j] = i no
fim da execução da função .
*/

void inverte(int i, int v[], int tamanho_maximo);

#endif