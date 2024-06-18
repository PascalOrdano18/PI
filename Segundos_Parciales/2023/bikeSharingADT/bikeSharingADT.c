#include "bikeSharingADT.h"



typedef struct stations{
    char* docks;
    size_t docksCount;   // Cantidad total de docks
    size_t docksUsed;   // Docks con bicicletas
} stations;


struct bikeSharingCDT{
    stations* stationArray;
    size_t stationsCount;
    size_t maxStationsCount;
};


bikeSharingADT newBikeSharing(size_t maxStationsCount){
    bikeSharingADT new = malloc(sizeof(struct bikeSharingCDT));
    new->maxStationsCount = maxStationsCount;
    new->stationsCount = 0;
    new->stationArray = calloc(maxStationsCount, sizeof(stations));
    return new;
}


int addStation(bikeSharingADT bikeSharingAdt, size_t stationId, size_t docksCount){
    if(stationId < 1 || stationId > bikeSharingAdt->maxStationsCount || bikeSharingAdt->stationArray[stationId - 1].docks != NULL){
        return -1;
    }
    bikeSharingAdt->stationArray[stationId - 1].docks = malloc(docksCount);
    bikeSharingAdt->stationArray[stationId - 1].docksUsed = docksCount;
    bikeSharingAdt->stationArray[stationId - 1].docksCount = docksCount;
    bikeSharingAdt->stationsCount++;
    for(int i = 0; i < docksCount; i++){
        bikeSharingAdt->stationArray[stationId - 1].docks[i] = 1;      // Cargo el dok con bicicletas
    }
    return bikeSharingAdt->stationsCount;
}



size_t rentBike(bikeSharingADT bikeSharingAdt, size_t stationId, size_t dockId){
    if(stationId < 1 || stationId > bikeSharingAdt->maxStationsCount || dockId < 0 || dockId >= bikeSharingAdt->stationArray[stationId - 1].docksCount || bikeSharingAdt->stationArray[stationId - 1].docks == NULL || bikeSharingAdt->stationArray[stationId - 1].docks[dockId] == 0){
        return -1;
    }

    bikeSharingAdt->stationArray[stationId - 1].docks[dockId] = 0;
    bikeSharingAdt->stationArray[stationId - 1].docksUsed--;
    return 0;
}


size_t bikesAvailable(bikeSharingADT bikeSharingAdt, size_t stationId){
    if(stationId < 1 || stationId > bikeSharingAdt->maxStationsCount){
        return -1;
    }
    return bikeSharingAdt->stationArray[stationId - 1].docksUsed;
}


size_t returnBike(bikeSharingADT bikeSharingAdt, size_t stationId, size_t dockId){
    if(stationId < 1 || stationId > bikeSharingAdt->maxStationsCount || bikeSharingAdt->stationArray[stationId - 1].docks == NULL || bikeSharingAdt->stationArray[stationId - 1].docks[dockId] == 1){
        return -1;
    }
    bikeSharingAdt->stationArray[stationId - 1].docksUsed++;
    bikeSharingAdt->stationArray[stationId - 1].docks[dockId] = 1;
    return 0;
}

size_t docksAvailable(bikeSharingADT bikeSharingAdt, size_t stationId){
    if(stationId < 1 || stationId > bikeSharingAdt->maxStationsCount){
        return -1;
    }
    return bikeSharingAdt->stationArray[stationId - 1].docksCount - bikeSharingAdt->stationArray[stationId - 1].docksUsed;
}

void freeBikeSharing(bikeSharingADT bikeSharingAdt){
    for(int i = 0; i < bikeSharingAdt->maxStationsCount; i++){
        if(bikeSharingAdt->stationArray[i].docks != NULL){
            free(bikeSharingAdt->stationArray[i].docks);
        }
    }
    free(bikeSharingAdt->stationArray);
    free(bikeSharingAdt);
}
