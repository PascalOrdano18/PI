#include "countersADT.h"
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char* name;
    struct person* tail;
} person;
typedef person* TPerson;

typedef struct counter{
    TPerson current;   // Nodo para los iteradores
    TPerson first;
    TPerson last;
    size_t dim;
} counter;

struct countersCDT{
    counter* counterArr;
    size_t maxCounters;
};

countersADT newCounters(size_t maxCounters){
    countersADT new = malloc(sizeof(struct countersCDT));
    new->counterArr = calloc(maxCounters, sizeof(counter));
    new->maxCounters = maxCounters;
    return new;
}

void enterCounter(countersADT counters, size_t counterNumber, const char *passenger){
    if(counterNumber >= counters->maxCounters || counterNumber < 0){
        exit(1);
    }
    TPerson new = malloc(sizeof(*new));
    new->name = malloc(strlen(passenger) + 1);
    strcpy(new->name, passenger);
    new->tail = NULL;
    if(counters->counterArr[counterNumber].first == NULL){
        counters->counterArr[counterNumber].first = new;
    }else{
        counters->counterArr[counterNumber].last->tail = new;
    }
    counters->counterArr[counterNumber].last = new;
    counters->counterArr[counterNumber].dim++;
}

void toBeginByCounter(countersADT counters, size_t counterNumber){
    if(counterNumber >= counters->maxCounters){
        return;
    }
    counters->counterArr[counterNumber].current = counters->counterArr[counterNumber].first;
}


size_t hasNextByCounter(const countersADT counters, size_t counterNumber){
    if(counterNumber >= counters->maxCounters)
        return 0;
    return counters->counterArr[counterNumber].current != NULL;
}

const char * nextByCounter(countersADT counters, size_t counterNumber){
    if(!hasNextByCounter(counters, counterNumber)){
        exit(1);
    }
    char* res = counters->counterArr[counterNumber].current->name;
    counters->counterArr[counterNumber].current = counters->counterArr[counterNumber].current->tail;
    return res;
}


struct checkInResult * checkInCounters(countersADT counters, size_t * checkInResultDim){
    struct checkInResult* res = calloc(counters->maxCounters, sizeof(struct checkInResult));
    *checkInResultDim = 0;
    for(int i = 0; i < counters->maxCounters; i++){
        if(counters->counterArr[i].first != NULL){
            res[*checkInResultDim].counterNumber = i;

            res[*checkInResultDim].checkedInPassenger = malloc(strlen(counters->counterArr[i].first->name) + 1);
            strcpy(res[*checkInResultDim].checkedInPassenger, counters->counterArr[i].first->name);
            res[*checkInResultDim].waitingPassengers = counters->counterArr[i].dim - 1;  // menos 1, pues quite una persona de la cola

            TPerson aux = counters->counterArr[i].first->tail;
            free(counters->counterArr[i].first->name);
            free(counters->counterArr[i].first);

            counters->counterArr[i].first = aux;
            counters->counterArr[i].dim--;
            (*checkInResultDim)++;
        }
    }

    res = realloc(res, *checkInResultDim * sizeof(struct checkInResult));
    return res;
}


void freeRec(TPerson person){
    if(person == NULL)
        return ;
    freeRec(person->tail);
    free(person->name);
    free(person);
}

void freeCounters(countersADT counters){
    for(int i = 0; i < counters->maxCounters; i++){
        freeRec(counters->counterArr[i].first);
    }
    free(counters->counterArr);
    free(counters);
}
