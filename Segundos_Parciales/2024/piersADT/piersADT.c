#include "piersADT.h"
#include <alloca.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>

typedef struct ports{
    char* dockArray;   // Aqui cada posicion representara un barco un el dock
    char* dockExistanceArray;   // Aqui cada posicion representara si existe el dock o no
    size_t allocDocksAmount;
    size_t docksAmount;
    size_t shipsAmount;
} ports;

struct piersCDT{
    ports* portArray;
    char* portExistanceArray;
    size_t allocPortsAmount;
    size_t portsAmount;
};

piersADT newPiers(void){
    piersADT new = calloc(1, sizeof(struct piersCDT));
    return new;
}

size_t addPier(piersADT piers, size_t pierNumber){
    if(piers->allocPortsAmount >= pierNumber && piers->portExistanceArray[pierNumber] == 1){
        return 0;
    }
    if(pierNumber > piers->allocPortsAmount){
        piers->portExistanceArray = realloc(piers->portExistanceArray, pierNumber + 1);
        piers->portArray = realloc(piers->portArray, (pierNumber + 1) * sizeof(*piers->portArray));
        for(int i = piers->allocPortsAmount; i < pierNumber; i++){
            piers->portExistanceArray[i] = 0;
        }
        piers->allocPortsAmount = pierNumber;
    }
    piers->portExistanceArray[pierNumber] = 1;
    piers->portsAmount++;
    return 1;
}


size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->allocPortsAmount <= pierNumber || piers->portExistanceArray[pierNumber] == 0 || (piers->portArray[pierNumber].allocDocksAmount >= dockNumber && piers->portArray[pierNumber].dockExistanceArray[dockNumber] == 1)){
        return 0;
    }
    if(piers->portArray[pierNumber].allocDocksAmount < dockNumber){
        piers->portArray[pierNumber].dockExistanceArray = realloc(piers->portArray[pierNumber].dockExistanceArray, (dockNumber + 1) * sizeof(*piers->portArray[pierNumber].dockExistanceArray));
        piers->portArray[pierNumber].dockArray = realloc(piers->portArray[pierNumber].dockArray, (dockNumber + 1) * sizeof(*piers->portArray[pierNumber].dockArray));
        for(int i = piers->portArray[pierNumber].allocDocksAmount; i < dockNumber; i++){
            piers->portArray[pierNumber].dockExistanceArray[i] = 0;
        }
        piers->portArray[pierNumber].allocDocksAmount = dockNumber;
    }
    piers->portArray[pierNumber].dockExistanceArray[dockNumber] = 1;
    piers->portArray[pierNumber].docksAmount++;
    return 1;
}

size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->allocPortsAmount <= pierNumber || piers->portExistanceArray[pierNumber] == 0 || piers->portArray[pierNumber].allocDocksAmount < dockNumber || piers->portArray[pierNumber].dockExistanceArray[dockNumber] == 0 || piers->portArray[pierNumber].dockArray[dockNumber] == 1){
        return 0;
    }
    piers->portArray[pierNumber].dockArray[dockNumber] = 1;
    piers->portArray[pierNumber].shipsAmount++;
    return 1;
}

int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->allocPortsAmount <= pierNumber || piers->portExistanceArray[pierNumber] == 0 || piers->portArray[pierNumber].allocDocksAmount < dockNumber || piers->portArray[pierNumber].dockExistanceArray[dockNumber] == 0){
        return -1;
    }
    return piers->portArray[pierNumber].dockArray[dockNumber];
}


size_t pierShips(const piersADT piers, size_t pierNumber){
    if(pierNumber >= piers->allocPortsAmount || piers->portExistanceArray[pierNumber] == 0){
        return -1;
    }
    return piers->portArray[pierNumber].shipsAmount;
}

size_t undockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(pierNumber >= piers->allocPortsAmount || piers->portExistanceArray[pierNumber] == 0 || dockNumber > piers->portArray[pierNumber].allocDocksAmount || piers->portArray[pierNumber].dockExistanceArray[dockNumber] == 0 || piers->portArray[pierNumber].dockArray[dockNumber] == 0){
        return 0;
    }
    piers->portArray[pierNumber].dockArray[dockNumber] = 0;
    piers->portArray[pierNumber].shipsAmount--;
    return 1;
}

void freePiers(piersADT piers){
    for(int i = 0; i < piers->allocPortsAmount; i ++){
        if(piers->portExistanceArray[i] == 1){
            free(piers->portArray[i].dockArray);
            free(piers->portArray[i].dockExistanceArray);
        }
    }
    free(piers->portArray);
    free(piers->portExistanceArray);
    free(piers);
}
