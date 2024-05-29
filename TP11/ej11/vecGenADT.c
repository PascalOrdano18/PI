#include <stdio.h>
#include <stdlib.h>
#include "vecGenADT.h"

#define BLOCK 20

typedef struct vElem{
    elemType elem;
    char isOccupied;
} Telem;

typedef Telem* Tvector;

struct vectorCDT{
    Tvector vector;
    compare cmp;
    size_t allocSize;
    size_t size;
};


vectorADT newVector(compare cmp){
    vectorADT newV = calloc(1, sizeof(struct vectorCDT));
    newV->cmp = cmp;
    return newV;
}

void freeVector(vectorADT v){
    free(v->vector);
    free(v);
}

int getIdx(vectorADT v, elemType elem){
    for(int i = 0; i < v->allocSize; i++){
        if(v->vector[i].isOccupied && v->vector[i].elem == elem){
            return i;
        }
    }
    return -1;
}


void deleteElement(vectorADT v, size_t index){
    if(index <= v->size && v->vector[index].isOccupied){
        v->vector[index].isOccupied = 0;
        v->size--;
    }
}


int elementCount(vectorADT v){
    int count = 0;
    for(int i = 0; i < v->allocSize; i++){
        count += v->vector[i].isOccupied;
    }
    return count;
}


size_t put(vectorADT v, elemType *elems, size_t dim, size_t index){
    if (dim <= 0 || index < 0 || elems == NULL){
        return 0;
    }
    if(v->allocSize <= index + dim){
        int prev = v->allocSize;
        v->allocSize += (index+dim);
        v->vector = realloc(v->vector, v->allocSize * sizeof(Telem));

        //Aca tengo que poner todos los isOccupied en 0
        for(int t = prev; t < v->allocSize; t++){
            v->vector[t].isOccupied = 0;
        }
    }
    int counter = 0;
    for(int i = index, j = 0; (i < index + dim) && j < dim; i++, j++){
        if(v->vector[i].isOccupied == 0){
            v->vector[i].elem = elems[j];
            v->vector[i].isOccupied = 1;
            v->size++;
            counter++;
        }
    }

    return counter;
}
