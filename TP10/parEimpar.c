#include <stdio.h>
#include <stdlib.h>
#define BLOQUE 10

int* pares(int* conj, size_t dim, size_t* nuevaDim);

int main(void){
    int dim = 10;
    int conj[] = {1,2,3,4,5,6,7,8,9,10};    

    size_t nuevaDim;

    pares(conj, dim, nuevaDim);

    return 0;
}

int* pares(int* conj, size_t dim, size_t* nuevaDim){

    int* newConj = NULL;

    *nuevaDim = 0;
    for(int i = 0; i < dim; i++){
        if(conj[i] % 2 == 0){
            if(BLOQUE % *nuevaDim == 0){
                newConj = realloc(newConj, (*nuevaDim + BLOQUE) * sizeof(*newConj));
            } 
            newConj[*nuevaDim] = conj[i];
            (*nuevaDim)++;
        }
    }
    newConj = realloc(newConj, *nuevaDim * sizeof(*newConj));
    return newConj;
}