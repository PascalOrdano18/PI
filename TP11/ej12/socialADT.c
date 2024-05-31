#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/_types/_size_t.h>
#include <sys/wait.h>
#include "socialADT.h"


#define NAME_LENGTH 21


typedef struct allegados{
    struct allegados* tail;  // Siguiente nodo, siguiente allegado. Lo hago con listas porque necesito orden alfabetico
    char name[NAME_LENGTH];
} tAllegados;

typedef tAllegados* Allegados;

typedef struct persona{
    struct persona* tail;   // Siguiente nodo, siguiente persona. Lo hago con listas porque necesito orden alfabetico
    char name[NAME_LENGTH];
    Allegados allegados;
    size_t sizeAllegados;
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
    freeAllegadosRec(allegado->tail);
    free(allegado);
}
static void freePeopleRec(Personas person){     // CHEQUEAR
    if(person == NULL)
        return ;
    freePeopleRec(person->tail);
    freeAllegadosRec(person->allegados);
    free(person);
}
void freeSocial(socialADT soc){
    if(soc == NULL)
        return ;
    freePeopleRec(soc->primerPersona);
    free(soc);
}

static Personas getPersonByName(Personas p, const char* name){
    int c;
    if(p == NULL || (c = strcmp(p->name, name)) > 0){
        return NULL;
    }
    if(c < 0){
        return getPersonByName(p->tail, name);
    }
    return p;
}

static Personas addPersonRec(Personas person, const char* name, size_t* size){
    if(person == NULL || strcmp(person->name, name) >= 0){    // Si la letra de persona->name es mayor que la letra de name, en este nodo va name
        Personas newP = calloc(1, sizeof(*newP));
        strncpy(newP->name, name, NAME_LENGTH);    // Guardo una copia, no el puntero.
        newP->tail = person;
        (*size)++;
        return newP;
    }
    person->tail =  addPersonRec(person->tail, name, size);      // Si no entro al if -> el resultado dio -1 -> comparo con el nombre de la siguiente persona en la lista
    return person;
}

void addPerson(socialADT soc, const char* name){
    if(getPersonByName(soc->primerPersona, name) == NULL){
        soc->primerPersona = addPersonRec(soc->primerPersona, name, &soc->size);
    }
}

static Allegados addRelatedRec(Allegados allegados, const char* related, size_t* size){

    if(allegados == NULL || strcmp(allegados->name, related) > 0){    // Si la letra de allegados->name es mayor que la letra de related, en este nodo va related
        // Related va exactamente en este nodo
        Allegados newA = calloc(1, sizeof(*newA));
        strncpy(newA->name, related, NAME_LENGTH);    // Guardo una copia, no el puntero.
        newA->tail = allegados;
        (*size)++;
        return newA;
    }
    allegados->tail = addRelatedRec(allegados->tail, related, size);      // Si no entro al if -> el resultado dio -1 -> comparo con el nombre del siguiente allegado en la lista
    return allegados;
}

void addRelated(socialADT soc, const char* name, const char* related){
    Personas p = getPersonByName(soc->primerPersona, name);
    if(p == NULL)  // Si la persona no existe no hace nada
        return ;
    p->allegados = addRelatedRec(p->allegados, related, &p->sizeAllegados);
}

static void relatedRec(Allegados a, char** relatedVec, size_t size){
    if(size == 0){
        *relatedVec = NULL;
        return ;
    }
    *relatedVec = malloc((NAME_LENGTH + 1) * sizeof(**relatedVec));
    strcpy(*relatedVec, a->name);
    relatedRec(a->tail, relatedVec + 1, size-1);
}

char** related(const socialADT soc, const char* person){
    Personas p = getPersonByName(soc->primerPersona, person);
    if(p == NULL){
        return calloc(1, sizeof(char*));
    }
    char** relatedVec = malloc((p->sizeAllegados + 1) * sizeof(*relatedVec));
    relatedRec(p->allegados, relatedVec, p->sizeAllegados);
    return relatedVec;
}

static void personsRec(Personas p, size_t size, char** personsVec){
    if(size == 0){
        *personsVec = NULL;  // El ultimo elemento es NULL
        return ;
    }
    *personsVec = malloc((NAME_LENGTH + 1) * sizeof(**personsVec));
    strcpy(*personsVec, p->name);
    personsRec(p->tail, size - 1, personsVec+1);
    return ;
}

char** persons(const socialADT soc){
    if(soc->primerPersona == NULL){
        return calloc(1, sizeof(void *));  // Debe retornar un array con NULL como unico elemento
    }
    char** personsVec = malloc((soc->size + 1) * sizeof(*personsVec));
    personsRec(soc->primerPersona, soc->size, personsVec);
    return personsVec;
}
