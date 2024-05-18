#include <stdio.h>
#include <assert.h>

#define MAX 10

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void reemplazar(int matriz[][MAX], int dim, int fil, int col, int dir[]);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         printf("%d", m[i][j]);
    //     }
    //     printf("\n");
    // }

  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}


void reemplazo(int matriz[][MAX], int dim, int fil, int col){
  if(dim < 1){
    return ;
  }
  matriz[fil][col] = 1 - matriz[fil][col];

  int directions[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
  for(int i = 0; i < 4; i++){
    reemplazar(matriz, dim, fil, col, directions[i]);
  }
}


void reemplazar(int matriz[][MAX], int dim, int fil, int col, int dir[]){

  if(fil < 0 || col < 0 || fil >= dim || col >= dim){
    return ;
  }
  matriz[fil][col] = 1 - matriz[fil][col];
  reemplazar(matriz, dim, fil + dir[0], col + dir[1], dir);
}


