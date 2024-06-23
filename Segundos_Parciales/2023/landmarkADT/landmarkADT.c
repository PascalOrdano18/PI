#include "landmarkADT.h"
#include <stdio.h>

#define STEP 100
#define INDEX(m) ((m) / 100)

typedef struct landm{
    landmarkType elem;
    char exists;
} landM;

struct landmarkCDT{
    landM* array;
    compare cmp;
    size_t allocAmount;
    size_t landmarkAmount;
};


landmarkADT newLandmark(compare cmp){
    landmarkADT new = malloc(sizeof(struct landmarkCDT));
    new->array = NULL;
    new->cmp = cmp;
    new->landmarkAmount = 0;
    new->allocAmount = 0;
    return new;
}

void addLandmark(landmarkADT landmark, size_t meters, landmarkType site){
    int index = INDEX(meters);
    if(landmark->array == NULL || landmark->allocAmount <= index){
        landmark->array = realloc(landmark->array, (index + 1) * sizeof(*landmark->array));
        for(int i = landmark->allocAmount; i < (index + 1); i++){
            landmark->array[i].elem = NULL;
            landmark->array[i].exists = 0;
        }
        landmark->allocAmount = index + 1;
    }
    if(landmark->array[index].exists == 0){
        landmark->landmarkAmount++;
        landmark->array[index].exists = 1;
    }
    landmark->array[index].elem = site;
}


int hasLandmark(const landmarkADT landmark, size_t meters){
    return landmark->array[INDEX(meters)].exists;
}

int distance(const landmarkADT landmark, landmarkType site){
    for(int i = 0; i < landmark->allocAmount; i++){

        if(landmark->array[i].exists && landmark->cmp(landmark->array[i].elem, site) == 0){
            return i * STEP;
        }
    }
    return -1;
}

size_t landmarkCount(const landmarkADT landmark){
    return landmark->landmarkAmount;
}


landmarkType* landmarks(const landmarkADT landmark){
    size_t dim;
    return landmarksBetween(landmark, 0, (landmark->allocAmount * STEP), &dim);
}


landmarkType* landmarksBetween(const landmarkADT landmark, size_t from, size_t to, size_t* dim){
    int fromN = INDEX(from), toN = INDEX(to);
    if(fromN > toN){
        *dim = 0;
        return NULL;
    }
    landmarkType* res = malloc(sizeof(*res) * landmark->landmarkAmount);
    *dim = 0;
    for(int i = fromN; i <= toN && i < landmark->allocAmount; i++){
        if(landmark->array[i].exists == 1){
            res[*dim] = landmark->array[i].elem;
            (*dim)++;
        }
    }
    if(*dim == 0){
        return NULL;
    }
    if(*dim != landmark->landmarkAmount){
        res = realloc(res, *dim * sizeof(*res));
    }
    return res;
}

void freeLandmark(landmarkADT landmark){
    free(landmark->array);
    free(landmark);
}
