#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"


#define BLOQUE 10

int main(void){
    int dim;
    int* arr;
    arr = cargarNumeros(&dim);
    for(int i = 0; i < dim; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}


int* cargarNumeros(int* dim){

    *dim = 0;
    int* arreglo = NULL;

    int aparecio = 1;
    int i = 0;

    while(aparecio){
        int last = getint("Ingrese un entero: \n");
        apariciones(arreglo, &aparecio, *dim, last);
        if(aparecio){
            *(arreglo + i) = last;
            *(dim++);
            i++;

            if(*dim % BLOQUE == 0){
                arreglo = realloc(arreglo, (*dim + BLOQUE) * sizeof(*arreglo));
            }
        }
    }   
    //chequeo si me pase de memoria necesaria, en ese caso la quito
    arreglo = realloc(arreglo, *dim * sizeof(*arreglo));

    return arreglo;
}

int apariciones(int* arreglo, int* aparecio, int dim, int last){
    for(int i = 0; i < dim; i++){
        if(arreglo[i] == last){
            *aparecio = 0;
        }
    }
    return 0;
}

