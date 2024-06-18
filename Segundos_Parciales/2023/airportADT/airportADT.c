#include "airportADT.h"
#include <stdlib.h>
#include <string.h>

typedef struct airplane{
    char* registration;
    struct airplane* tail;
} airplane;
typedef airplane* TAirplane;

typedef struct runway{
    TAirplane first;
    size_t amountAirplanes;
} runway;

struct airportCDT{        // Arreglo de runways, donde cada runway tiene una lista de aviones waiting for takeoff
    runway* runwayArray;
    char* occupiedRunway;    // Array para ver si un runway esta ocupado o no
    size_t runWaysAmount;
    size_t allocRunWaysAmount;
};

airportADT newAirport(void){
    airportADT new = calloc(1, sizeof(struct airportCDT));
    return new;
}


int addRunway(airportADT airportAdt, size_t runwayId){
    if(runwayId > airportAdt->allocRunWaysAmount){
        airportAdt->allocRunWaysAmount = runwayId;
        airportAdt->occupiedRunway = realloc(airportAdt->occupiedRunway, runwayId * sizeof(*airportAdt->occupiedRunway));
        airportAdt->runwayArray = realloc(airportAdt->runwayArray, runwayId * sizeof(*airportAdt->runwayArray));
    } else if(runwayId <= 0 || airportAdt->occupiedRunway[runwayId - 1] == 1){
        return -1;        // Falla, pues ya habia un runway con ese id
    }
    airportAdt->occupiedRunway[runwayId - 1] = 1;
    airportAdt->runWaysAmount++;
    return airportAdt->runWaysAmount;
}



static void addPlaneRec(TAirplane plane, const char* registration){
    if(plane->tail == NULL){
        TAirplane new = calloc(1, sizeof(*new));
        new->tail = NULL;
        strcpy(new->registration, registration);
        plane->tail = new;
        return ;
    }
    addPlaneRec(plane->tail, registration);
    return ;
}

int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char *registration){
    if(runwayId <= 0 || runwayId > airportAdt->allocRunWaysAmount || airportAdt->occupiedRunway[runwayId - 1] == 0){
        return -1;
    }

    if(airportAdt->runwayArray[runwayId - 1].first == NULL){
        TAirplane new = calloc(1, sizeof(*new));
        new->tail = NULL;
        strcpy(new->registration, registration);
        airportAdt->runwayArray[runwayId - 1].first = new;
    } else {
        addPlaneRec(airportAdt->runwayArray[runwayId - 1].first, registration);
    }

    airportAdt->runwayArray[runwayId - 1].amountAirplanes++;
    return airportAdt->runwayArray[runwayId - 1].amountAirplanes;
}

char* takeOff(airportADT airportAdt, size_t runwayId){
    if(runwayId <= 0 || runwayId > airportAdt->allocRunWaysAmount || airportAdt->occupiedRunway[runwayId - 1] == 0){
        return NULL;
    }
    TAirplane aux = airportAdt->runwayArray[runwayId - 1].first;
    char* res = aux->registration;
    airportAdt->runwayArray[runwayId - 1].first = aux->tail;
    free(aux);
    return res;
}



char ** pendingFlights(airportADT airportAdt, size_t runwayId){
    if(runwayId <= 0 || runwayId > airportAdt->allocRunWaysAmount || airportAdt->occupiedRunway[runwayId - 1] == 0){
        return NULL;
    }
    char** res = calloc(airportAdt->runwayArray[runwayId - 1].amountAirplanes, sizeof(*res));

    TAirplane current = airportAdt->runwayArray[runwayId - 1].first;

    for(int i = airportAdt->runwayArray[runwayId - 1].amountAirplanes -1; i >= 0; i--){
        strcpy(*res, current->registration);
        current = current->tail;
    }
    return res;
}


void freePlaneRec(TAirplane plane){
    if(plane == NULL){
        return ;
    }
    freePlaneRec(plane->tail);
    free(plane);
}


void freeAirport(airportADT airportAdt){
    for(int i = 0; i < airportAdt->allocRunWaysAmount; i++){
        if(airportAdt->occupiedRunway[i]){
            freePlaneRec(airportAdt->runwayArray[i].first);
        }
    }
    free(airportAdt->occupiedRunway);
    free(airportAdt->runwayArray);
    free(airportAdt);
}
