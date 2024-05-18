#include <stdio.h>
#include <stdlib.h>

#define BLOQUE 10

int* cargarNumeros(int* dim);

int main(void){
    int dim;
    int* arr;
    arr = cargarNumeros(&dim);
    for(int i = 0; i < dim; i++){
        printf("%c ", arr[i]);
    }

    free(arr);
    return 0;
}

int* cargarNumeros(int* dim){

    *dim = 0;
    int* arreglo = NULL;

    int counter = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n'){
        if(counter % BLOQUE == 0){
            arreglo = realloc(arreglo, (counter + BLOQUE) * sizeof(*arreglo));
        }
        arreglo[counter++] = c;
    }
    arreglo = realloc(arreglo, (counter + BLOQUE) * sizeof(*arreglo));
    *dim = counter;
    return arreglo;
}


