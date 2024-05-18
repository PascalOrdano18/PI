#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int obtenerAprobados(char* arrNombres[], int tam, char* aprobados[], int notas[]);
void printAprobados(char* aprobados, int dimAprobados);


int main(void){

    int tam = 4;
    char* arrNombres[] = {"Pepe, Juan, Fer, Mia"};
    char* aprobados[tam];
    int notas[] = {10, 3, 8, 4};
    int dimAprobados = obtenerAprobados(arrNombres, tam, aprobados, notas);

    for(int i = 0; i < dimAprobados; i++){
        free(aprobados[i]);
    }

    return 0;
}

int obtenerAprobados(char* arrNombres[], int tam, char* aprobados[], int notas[]){

    int indexAprob = 0;

    for(int i = 0; i < tam; i++){   
        if(notas[i] >= 6){
            aprobados[indexAprob] = malloc(strlen(arrNombres[i]) + 1);
            strcpy(aprobados[indexAprob++], arrNombres[i]);
        }
    }

    return indexAprob;
}
void printAprobados(char* aprobados, int dimAprobados){
    printf("Los aprobados son:\n");
    for(int i = 0; i < dimAprobados; i++){
        printf("%s", aprobados[i]);
    }

    return ;
}


