#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#include "socialADT.h"


#define NAME_LENGTH 21


typedef struct allegados{
    struct allegados* tail;  // Siguiente nodo, siguiente allegado. Lo hago con listas porque necesito orden alfabetico
    char name[NAME_LENGTH];
    size_t sizeAllegados;
} tAllegados;

typedef tAllegados* Allegados;

typedef struct persona{
    struct persona* tail;   // Siguiente nodo, siguiente persona. Lo hago con listas porque necesito orden alfabetico
    char name[NAME_LENGTH];
    Allegados allegados;
} tPerson;

typedef tPerson* Personas;   // Array de structs tPerson, donde cada elemento del array es un struct que tiene el nombre de la persona y un array de todos sus allegados.

typedef struct socialCDT{
    Personas primerPersona;   // Puntero a la primer persona en la lista
    size_t size;    // Cantidad de personas
} socialCDT;



socialADT newSocial(void){
    socialADT newS = calloc(1, sizeof(*newS));
    return newS;
}

static void freeAllegadosRec(Allegados allegado){
    if(allegado == NULL)
        return ;
    free(allegado->tail);
    free(allegado);
}
static void freePeopleRec(Personas person){     // CHEQUEAR
    if(person == NULL)
        return ;
    freeAllegadosRec(person->allegados);
    free(person->tail);
    free(person);
}
void freeSocial(socialADT soc){
    if(soc == NULL)
        return ;
    freePeopleRec(soc->primerPersona);
    free(soc);
}


static Personas getPersonByName(Personas p, const char* name){
    if(p == NULL)
        return NULL;
    if(strcmp(p->name, name))
        return p;
    return getPersonByName(p->tail, name);
}

static int compareASCIIsRec(char* letterP, const char* letterN){    // Lo subraya porque no le puse const, es al pedo
    if(letterP == NULL || letterN == NULL)
        return 0;
    if(*letterP > *letterN)
        return 1;
    if(*letterP < *letterN)
        return -1;
    return compareASCIIsRec(letterP+1, letterN+1);   // Si son iguales comparo con la siguiente letra
}

static Personas addPersonRec(Personas person, const char* name){
    if(person == NULL){
        return NULL;
    }
    if(compareASCIIsRec(person->name, name) > 0){    // Si la letra de persona->name es mayor que la letra de name, en este nodo va name
        // Name va exactamente en este nodo
        Personas newP = calloc(1, sizeof(*newP));
        strcpy(newP->name, name);    // Guardo una copia, no el puntero.
        newP->tail = person;
        return newP;
    }
    person->tail =  addPersonRec(person->tail, name);      // Si no entro al if -> el resultado dio -1 -> comparo con el nombre de la siguiente persona en la lista
    return person;
}

void addPerson(socialADT soc, const char* name){
    if(getPersonByName(soc->primerPersona, name) == NULL)
        addPersonRec(soc->primerPersona, name);
}

static Allegados addRelatedRec(Allegados allegados, const char* related){
    if(allegados == NULL){
        return NULL;
    }
    if(compareASCIIsRec(allegados->name, related) > 0){    // Si la letra de allegados->name es mayor que la letra de related, en este nodo va related
        // Related va exactamente en este nodo
        Allegados newA = calloc(1, sizeof(*newA));
        strcpy(newA->name, related);    // Guardo una copia, no el puntero.
        newA->tail = allegados;
        allegados->sizeAllegados++;
        return newA;
    }
    allegados->tail = addRelatedRec(allegados->tail, related);      // Si no entro al if -> el resultado dio -1 -> comparo con el nombre del siguiente allegado en la lista
    return allegados;
}

void addRelated(socialADT soc, const char* name, const char* related){
    if(soc == NULL)
        return ;
    Personas p = getPersonByName(soc->primerPersona, name);
    if(p == NULL)  // Si la persona no existe no hace nada
        return ;
    addRelatedRec(p->allegados, related);
}


static char** relatedIt(Personas p, const char* name){
    char** relatedVec = malloc((p->allegados->sizeAllegados + 1) * sizeof(*relatedVec));
    int i;
    for(i = 0; i < p->allegados->sizeAllegados; i++){
        strcpy(relatedVec[i], p->allegados->name);
    }
    relatedVec[i] = NULL;
    return relatedVec;
}

char** related(const socialADT soc, const char* person){
    if(soc == NULL){
        return calloc(1, sizeof(void *));    // Retorna array con NULL como unico elemento
    }
    Personas p = getPersonByName(soc->primerPersona, person);
    return relatedIt(p, person);
}



static char** personsIT(Personas p, size_t size){
    if(p == NULL){
        return calloc(1, sizeof(void *));  // Debe retornar un array con NULL como unico elemento
    }
    char** personsVec = malloc((size + 1) * sizeof(*personsVec));
    int i;
    for(i = 0; i < size; i++){
        strcpy(personsVec[i], p->name);
    }
    personsVec[i] = NULL;
    return personsVec;
}

char** persons(const socialADT soc){
    if(soc == NULL){
        return NULL;
    }
    return personsIT(soc->primerPersona, soc->size);
}
