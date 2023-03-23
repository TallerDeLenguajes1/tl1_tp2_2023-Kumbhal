#include <stdio.h>
#define N 20

void main(){
    int i;
    double vt[N];
    double *punt = vt;

    for(i = 0;i<N; i++){
        *punt=1+rand()%100;
        printf("%f  ", *punt);
        punt++;
    }
}