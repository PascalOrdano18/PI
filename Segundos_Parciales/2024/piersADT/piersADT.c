#include "piersADT.h"
#include <stdlib.h>


typedef struct puertos{
    char** arrMuelles;  // existe si no es NULL
    size_t docksSize;
    size_t docksAlloc;
    char exists;  // 1 si existe 0 si no
    size_t shipsInPier;  // cantidad de embarcaciones en todos los muelles del puerto
} puertos;

struct piersCDT{
    puertos* arrPuertos;
    size_t piersSize;
    size_t piersAlloc;
};


piersADT newPiers(void){
    piersADT new = calloc(1, sizeof(struct piersCDT));
    return new;
}

size_t addPier(piersADT piers, size_t pierNumber){
    if(piers->piersAlloc <= pierNumber){
        piers->arrPuertos = realloc(piers->arrPuertos, (pierNumber + 1) * sizeof(puertos));    // DEBE SER PIERNUMBER + 1
        for(int i = piers->piersAlloc; i < pierNumber + 1; i++){
            piers->arrPuertos[i].shipsInPier = 0;
            piers->arrPuertos[i].docksSize = 0;
            piers->arrPuertos[i].exists = 0;
            piers->arrPuertos[i].docksAlloc = 0 ;
            piers->arrPuertos[i].arrMuelles = NULL;
        }
        piers->piersAlloc = pierNumber + 1;   // Pues quieo poder acceder a pierNumber
    }

    if(piers->arrPuertos[pierNumber].exists == 1){     // - 1 pues se empieza a contar de 0.
        return 0;
    }
    piers->arrPuertos[pierNumber].exists = 1;
    piers->piersSize++;
    return 1;
}


size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->piersAlloc <= pierNumber || piers->arrPuertos[pierNumber].exists == 0){
        return 0;
    }
    if(piers->arrPuertos[pierNumber].docksAlloc <= dockNumber){
        piers->arrPuertos[pierNumber].arrMuelles = realloc(piers->arrPuertos[pierNumber].arrMuelles, (dockNumber + 1) * sizeof(*piers->arrPuertos[pierNumber].arrMuelles));
        for(int i = piers->arrPuertos[pierNumber].docksAlloc; i < dockNumber + 1; i++){
            piers->arrPuertos[pierNumber].arrMuelles[i] = NULL;
        }
        piers->arrPuertos[pierNumber].docksAlloc = dockNumber + 1;
    }
    if(piers->arrPuertos[pierNumber].arrMuelles[dockNumber] != NULL){
        return 0;
    }
    piers->arrPuertos[pierNumber].arrMuelles[dockNumber] = calloc(1, sizeof(*piers->arrPuertos[pierNumber].arrMuelles[dockNumber]));  // arranca sin embarcaciones;
    return 1;
}

size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->piersAlloc <= pierNumber || piers->arrPuertos[pierNumber].exists == 0 || piers->arrPuertos[pierNumber].arrMuelles == NULL){
        return 0;
    }
    *piers->arrPuertos[pierNumber].arrMuelles[dockNumber] = 1;
    piers->arrPuertos[pierNumber].shipsInPier++;
    return 1;
}

int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->piersAlloc <= pierNumber || piers->arrPuertos[pierNumber].exists == 0 || piers->arrPuertos[pierNumber].arrMuelles == NULL){
        return -1;
    }
    return *piers->arrPuertos[pierNumber].arrMuelles[dockNumber];
}

size_t pierShips(const piersADT piers, size_t pierNumber){
    if(piers->piersAlloc <= pierNumber || piers->arrPuertos[pierNumber].exists == 0){
        return -1;
    }
    return piers->arrPuertos[pierNumber].shipsInPier;
}

size_t undockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
    if(piers->piersAlloc <= pierNumber || piers->arrPuertos[pierNumber].exists == 0 || piers->arrPuertos[pierNumber].arrMuelles == NULL || *piers->arrPuertos[pierNumber].arrMuelles[dockNumber] == 0){
        exit(1);
    }
    *piers->arrPuertos[pierNumber].arrMuelles[dockNumber] = 0;
    piers->arrPuertos[pierNumber].shipsInPier--;
    return 1;
}

void freePiers(piersADT piers){
    for(int i = 0; i < piers->piersAlloc; i++){
        free(piers->arrPuertos[i].arrMuelles);
    }
    free(piers->arrPuertos);
    free(piers);
}
