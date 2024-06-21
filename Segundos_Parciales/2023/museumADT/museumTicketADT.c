#include "museumTicketADT.h"

#define DAYS_IN_YEARB 366
#define DAY_IN_RANGE(day) (((day) == 0) || ((day) > DAYS_IN_YEARB)) 



typedef struct visitor{
    char* name;
    struct visitor* tail;
} visitor;
typedef visitor* TVisitor;

typedef struct day{
    TVisitor first;       // Primer visitor en la lista
    TVisitor current;     // Nodo para los iteradores
    size_t dayTickets;    // Tickets vendidos ese dia = cantidad de personas en la lista
} day;

struct museumTicketCDT{
    day* dayArray;        // Array de structs day
    size_t yearTickets;
};


museumTicketADT newMuseumTicket(void){
    museumTicketADT new = malloc(sizeof(struct museumTicketCDT));
    new->dayArray = calloc(DAYS_IN_YEARB, sizeof(day));    // Ya creo el array pues se exactamente la cantidad de dias que habra. Lo creo en el heap para que persista la memoria dinamica y no se borre
    new->yearTickets = 0;
    return new;
}


// Agrega al visitor si no estaba registrado antes. Si estaba registrado no hace nada y cambia el flag
static TVisitor addVisitor(TVisitor visitor, const char* targetVisitor, int* exists){
    int c;
    if (visitor == NULL || (c = strcasecmp(visitor->name, targetVisitor)) > 0){
        TVisitor new = malloc(sizeof(*new));
        new->name = malloc(strlen(targetVisitor) + 1);
        strcpy(new->name, targetVisitor);
        new->tail = visitor;
        return new;
    }
    if (c == 0){
        *exists = 1;
        return visitor;
    }

    visitor->tail = addVisitor(visitor->tail, targetVisitor, exists);
    return visitor;
}


int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear, const char* visitor){
    if (DAY_IN_RANGE(dayOfYear)){
        return 0;
    }
    int exists = 0;
    museumTicketADT->dayArray[dayOfYear - 1].first = addVisitor(museumTicketADT->dayArray[dayOfYear - 1].first, visitor, &exists);

    if (exists){
        return 0;
    }
    museumTicketADT->dayArray[dayOfYear - 1].dayTickets++;
    museumTicketADT->yearTickets++;
    return museumTicketADT->dayArray[dayOfYear - 1].dayTickets;
}

int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_IN_RANGE(dayOfYear)){
        return -1;
    }
    return museumTicketADT->dayArray[dayOfYear - 1].dayTickets;
}

int yearTickets(const museumTicketADT museumTicketADT){
    return museumTicketADT->yearTickets;
}


void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_IN_RANGE(dayOfYear))
        exit(1);
    museumTicketADT->dayArray[dayOfYear - 1].current = museumTicketADT->dayArray[dayOfYear - 1].first;
}

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_IN_RANGE(dayOfYear))
        exit(1);
    return museumTicketADT->dayArray[dayOfYear - 1].current != NULL;
}

char* nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_IN_RANGE(dayOfYear) || !hasNextByDay(museumTicketADT, dayOfYear)){
        exit(1);
    }
    char* res = museumTicketADT->dayArray[dayOfYear - 1].current->name;
    museumTicketADT->dayArray[dayOfYear - 1].current = museumTicketADT->dayArray[dayOfYear - 1].current->tail;
    return res;
}


void freeVisitorsRec(TVisitor visitor){
    if (visitor == NULL){
        return;
    }
    freeVisitorsRec(visitor->tail);
    free(visitor->name);
    free(visitor);
}

void freeMuseumTicket(museumTicketADT museumTicketADT){
    for (int i = 0; i < DAYS_IN_YEARB; i++){
        freeVisitorsRec(museumTicketADT->dayArray[i].first);
    }
    free(museumTicketADT->dayArray);
    free(museumTicketADT);
}



