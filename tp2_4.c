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

void mostrarOpciones();
void cargarComputadoras(computadora *computadora, int cantidad, char tipos[C][L]);
void mostrarComputadoras(computadora *computadora, int cantidad);
void mostrarComputadoraVieja(computadora *computadora, int cantidad);
void mostrarComputadoraRapida(computadora *computadora, int cantidad);

void main(){
    int cantidad = 0, opcion = 0;
    char tipos[C][L]= {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    srand(time(NULL));
    printf("Ingrese la cantidad de computadoras a generar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    computadora *computadora = malloc(cantidad*sizeof(computadora));
    cargarComputadoras(computadora, cantidad, tipos);
    while (opcion != 4){
        mostrarOpciones();
        scanf("%d", &opcion);
        fflush(stdin);
        if (opcion == 1){
            mostrarComputadoras(computadora, cantidad);
        }else if(opcion == 2){
            mostrarComputadoraVieja(computadora, cantidad);
        }else{
            mostrarComputadoraRapida(computadora, cantidad);
        }
    }
    free(computadora);
}

void mostrarOpciones(){
    printf("\n----------OPCIONES----------\n(1)Mostrar Computadoras\n(2)Mostrar computadora mas vieja\n(3)Mostrar computadora mas rapida\n(4)Salir");
}
void cargarComputadoras(computadora *computadora, int cantidad, char tipos[C][L]){
    for (int i = 0; i < cantidad; i++){
        (computadora+i)->velocidad = 1 + rand()%3;
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
void mostrarComputadoraVieja(computadora *computadora, int cantidad){
    int i = 0, numero = 0, anio = 0;
    anio = (computadora+i)->anio;
    for (i; i < cantidad; i++){
        if (anio >= ((computadora+i)->anio)){
            anio = (computadora+i)->anio;
            numero = i;
        }
    }
    printf("\nEl tipo de CPU de la computadora es %s", (computadora+numero)->tipo_cpu);
    printf("\nLa velocidad de la computadora es de %d GhZ", (computadora+numero)->velocidad);
    printf("\nPosee %d nucleos", (computadora+numero)->cantidad);
    printf("\nLa computadora es del anio %d", (computadora+numero)->anio);
}
void mostrarComputadoraRapida(computadora *computadora, int cantidad){
    int i = 0, numero = 0, velocidad = 0;
    velocidad = (computadora+i)->velocidad;
    for (i; i < cantidad; i++){
        if (velocidad <= ((computadora+i)->velocidad)){
            velocidad = (computadora+i)->velocidad;
            numero = i;
        }
    }
    printf("\nEl tipo de CPU de la computadora es %s", (computadora+numero)->tipo_cpu);
    printf("\nLa velocidad de la computadora es de %d GhZ", (computadora+numero)->velocidad);
    printf("\nPosee %d nucleos", (computadora+numero)->cantidad);
    printf("\nLa computadora es del anio %d", (computadora+numero)->anio);
}