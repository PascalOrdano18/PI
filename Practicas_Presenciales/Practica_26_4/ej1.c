#include <stdio.h>
#include <stdlib.h>

#define TAM 10  

int main(void){

    int * arr;


    //1
    int i;
    arr = malloc(TAM * sizeof(int));
    for(i = 0; i < TAM; i++){
        arr[i] = 0;
    }
    mostrarArreglo(arr, TAM);
    free(arr);

    //2
    arr = NULL;
    arr = realloc(arr, TAM * sizeof(int));
    for(int j = 0; j < TAM; j++){
        arr[j] = 0;
    }

    //3
    arr = calloc(TAM, sizeof(int));
    free(arr);

    return 0;
}