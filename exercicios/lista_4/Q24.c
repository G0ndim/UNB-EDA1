#include <stdio.h>
#include <stdlib.h>

typedef struct coord{
    int x,y;
}coord;

typedef struct celula{
    char tipo;
    int altura;
} celula;

int cord_valida(int x, int y, int n, int m){
    return ((x >= 0 && x < n ) && (y >= 0 && y < m));
}

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    celula matriz[n][m];

    coord *cord_t = calloc(n * m, sizeof(coord));
    int num_torres = 0;
    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &matriz[i][j].tipo);
            matriz[i][j].altura = 0;
            if (matriz[i][j].tipo == 't')
            {
                coord torre = {i, j};
                cord_t[num_torres++] = torre;
            }   
        }
    }

    for (int i = 0; i < num_torres; i++)
    {
        coord torre = cord_t[i];
        scanf("%d", &matriz[torre.x][torre.y].altura);
    }

    int cont = 0;

    for (int i = 0; i < num_torres; i++)
    {
        int x = cord_t[i].x;
        int y = cord_t[i].y;
        for (int j = x - matriz[x][y].altura; j <= x + matriz[x][y].altura; j++)
        {
            for (int k = y - matriz[x][y].altura; k <= y + matriz[x][y].altura; k++)
            {
                if (!cord_valida(j,k,n,m)) continue;
                
                if (matriz[j][k].tipo == '#')
                {
                    cont++;
                    matriz[j][k].tipo = '.';
                }
                
            }
            
        }
        
    }
    printf("%d\n", cont);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", matriz[i][j].tipo);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}