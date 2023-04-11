#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 20

void main(){
    int i;
    double vt[N], *punteroVt;
    punteroVt = vt;
    srand(time(NULL));
    for(i = 0;i<N; i++){
        *(punteroVt)=1+rand()%100;
        printf("\n%.2f", *(punteroVt));
        punteroVt++;
    }
}