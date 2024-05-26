#include <stdio.h>
#include <stdlib.h>
#include "conjuntosADT.h"


#define BLOCK 20

// Como los elementos del conjunto no estan ordenados, voy a usar un array en vez de listas.

struct setCDT{
    Array conjunto;
    size_t size;
    size_t allocSize;
    compare cmp;
};

static void reallocateMemo(setADT set){
    set->allocSize =+ BLOCK;
    set->conjunto = realloc(set->conjunto, set->allocSize * sizeof(*set->conjunto));
}

setADT newSet(compare func){
    setADT newArray = calloc(BLOCK, sizeof(elemType));
    newArray->cmp = func;
    return newArray;
}


void freeSet(setADT set){  // chequear
    free(set->conjunto);
    free(set);
}

int isEmptySet(setADT set){
    return !(set->size);
}



int addElement(setADT set, elemType elem){
    int found = setContains(set, elem);
    if(!found){
        if(set->size == set->allocSize){
            reallocateMemo(set);
        }
        set->conjunto[set->size++] = elem;
    }
    return !found;
}

int deleteElement(setADT set, elemType element){
    char found = 0;
    for(int i = 0; i < set->size; i++){
        int c = set->cmp(set->conjunto[i], element);
        if(c == 0){
            found = 1;
            elemType aux = set->conjunto[i];
            set->conjunto[i] = set->conjunto[set->size];
            set->conjunto[set->size--] = aux;
        }
    }
    return found;
}


// Devuelve 1 si contiene al elemento y 0 si no lo contiene
int setContains(const setADT set, elemType element){
    char found = 0;
    for(int i = 0; i < set->size; i++){
        int c = set->cmp(set->conjunto[i], element);
        if(c == 0){
            found = 1;
        }
    }
    return found;
}

int sizeSet(const setADT set){
    return set->size;
}


setADT unionSet(setADT set1, setADT set2){
    setADT uSet = newSet(set1->cmp);
    for(int i = 0; i < set1->size; i++){
        if(uSet->size == uSet->allocSize){
            reallocateMemo(uSet);
        }
        uSet->conjunto[uSet->size++] = set1->conjunto[i];
    }
    for(int i = 0; i < set2->size; i ++){
        int found = 0, j = 0;
        for(j = 0; j < uSet->size; j++){
            int c = uSet->cmp(uSet->conjunto[j], set2->conjunto[i]);
            // Aca podria trabajar solo con el valor de c, y no meter esa auxiliar found
            if(c == 0){
                found = 1;
            }
        }
        if(!found){     // Si no dio cero en todo el recorrido, entonces no estaba antes -> lo agrego
            uSet->conjunto[uSet->size++] = set2->conjunto[i];
        }
    }
    return uSet;
}


setADT intersectionSet(setADT set1, setADT set2){
    setADT iSet = newSet(set1->cmp);
    for(int i = 0; i < set1->size; i++){
        if(setContains(set2, set1->conjunto[i])){
            if(iSet->size == iSet->allocSize){
                reallocateMemo(iSet);
            }
            iSet->conjunto[iSet->size++] = set1->conjunto[i];
        }
    }
    return iSet;
}


setADT diffSet(setADT set1, setADT set2){
    setADT dSet = newSet(set1->cmp);
    for(int i = 0; i < set1->size; i++){
        if(!setContains(set2, set1->conjunto[i])){
            if(dSet->size == dSet->allocSize){
                reallocateMemo(dSet);
            }
            dSet->conjunto[dSet->size++] = set1->conjunto[i];
        }
    }
    return dSet;
}
