#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
#define M 7

void main(){
    int matriz[N][M];
    int *punteroMatriz;
    punteroMatriz = &matriz[0][0];
    srand(time(NULL));
    for(int i = 0;i<N; i++){
        for(int j = 0;j<M; j++){
            *(punteroMatriz) = 1+rand()%100;
            printf(" %d ", *(punteroMatriz));
            punteroMatriz++;
        }
        printf("\n");
    }
}