#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7

void main(){
    srand(time(NULL));
    int i,j;
    int *punt=(int *)malloc(N*M*sizeof(int));
   
    //creo matriz
    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
             *(punt + i * M + j) = 1 + rand() % 100; 
        }
    }
    //muestro matriz
    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
            printf("%d  ", *(punt + i * M + j));
        }
        printf("\n");
    }
    free(punt); 
}
