#include <stdio.h>
#include <stdlib.h>
#include "conjuntosADT.h"


#define BLOCK 20

// Como los elementos del conjunto no estan ordenados, voy a usar un array en vez de listas.

struct conjuntoCDT{
    Array conjunto;
    size_t size;
    compare cmp;
};




conjuntoADT newSet(compare func){
    conjuntoADT newArray = calloc(BLOCK, sizeof(elemType));
    newArray->cmp = func;
    newArray->size = 0;
    return newArray;
}


static int addElemRec(conjuntoADT conjuntoC, elemType elem){

    for(int i = 0; i < conjuntoC->size; i++){
        int c = conjuntoC->cmp(conjuntoC->conjunto[i], elem);
        if(conjuntoC->conjunto[i] == NULL || c > 0 ){
            // add?
        }
        else if(c == 0 ){
            return 0; // No lo pudo agregar, pues ya estaba y no acepta repetidos
        }
    }
}


int addElement(conjuntoADT conjuntoC, elemType elem){
    return addElemRec(conjuntoC, elem);
}
