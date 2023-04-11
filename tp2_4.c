#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define C 6
#define L 10

struct{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
}typedef computadora;

void cargarComputadoras(computadora *computadora, int cantidad, char tipos[C][L]);
void mostrarComputadoras(computadora *computadora, int cantidad);

void main(){
    int cantidad = 0;
    char tipos[C][L]= {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    srand(time(NULL));
    printf("Ingrese la cantidad de computadoras a generar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    computadora *computadora = malloc(cantidad*sizeof(computadora));
    cargarComputadoras(computadora, cantidad, tipos);
    mostrarComputadoras(computadora, cantidad);
    free(computadora);
}

void cargarComputadoras(computadora *computadora, int cantidad, char tipos[C][L]){
    for (int i = 0; i < cantidad; i++){
        (computadora+i)->velocidad = rand()%4;
        (computadora+i)->anio = 2015 + rand()%8;
        (computadora+i)->cantidad = 1 + rand()%9;
        (computadora+i)->tipo_cpu = tipos[rand()%C];
    }
}
void mostrarComputadoras(computadora *computadora, int cantidad){
    for (int i = 0; i < cantidad; i++){
        printf("\n----------COMPUTADORA N %d----------", (i+1));
        printf("\nEl tipo de CPU de la computadora es %s", (computadora+i)->tipo_cpu);
        printf("\nLa velocidad de la computadora es de %d GhZ", (computadora+i)->velocidad);
        printf("\nPosee %d nucleos", (computadora+i)->cantidad);
        printf("\nLa computadora es del anio %d", (computadora+i)->anio);
    }
}