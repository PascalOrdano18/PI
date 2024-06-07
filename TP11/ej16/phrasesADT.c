#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "phrasesADT.h"


#define BLOCK 50
#define INDEX(key, keyFrom) ((key) - (keyFrom))


typedef struct elem{
    char* phrase;
    size_t size;
} elem;

typedef elem* pElem;

struct phrasesCDT{
    pElem arrayElems;
    size_t keyFrom;
    size_t keyTo;
    size_t size;   // Cantidad de keys con frases almacenadas
};


phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if(keyTo < keyFrom){
        return NULL;
    }
    phrasesADT newP = malloc(sizeof(struct phrasesCDT));
    newP->keyFrom = keyFrom;
    newP->keyTo = keyTo;
    newP->size = 0;
    newP->arrayElems = calloc(keyTo - keyFrom + 1, sizeof(*(newP->arrayElems)));
    return newP;
}

int put(phrasesADT ph, size_t key, const char *phrase){
    if(key > ph->keyTo || key < ph->keyFrom)
        return 0;
    size_t index = INDEX(key, ph->keyFrom);

    if(ph->arrayElems[index].size == 0){
        ph->size++;
    }

    int i;
    for(i = 0; phrase[i] != '\0'; i++){
        if(i == ph->arrayElems[index].size){
            ph->arrayElems[index].size += BLOCK;
            ph->arrayElems[index].phrase = realloc(ph->arrayElems[index].phrase, ph->arrayElems[index].size);
        }
        ph->arrayElems[index].phrase[i] = phrase[i];
    }
    ph->arrayElems[index].size = i;
    ph->arrayElems[index].phrase = realloc(ph->arrayElems[index].phrase, ph->arrayElems[index].size + 1);
    ph->arrayElems[index].phrase[ph->arrayElems[index].size] = '\0';
    return 1;
}


size_t size(const phrasesADT ph){
    return ph->size;
}


char* get(const phrasesADT ph, size_t key){
    size_t index = INDEX(key, ph->keyFrom);
    if(key < ph->keyFrom || key > ph->keyTo || ph->arrayElems[index].size == 0){
        return NULL;
    }
    char* string = malloc(ph->arrayElems[index].size + 1);
    for(int i = 0; ph->arrayElems[index].phrase[i] != '\0'; i++){
        string[i] = ph->arrayElems[index].phrase[i];
    }
    string[ph->arrayElems[index].size] = '\0';
    return string;
}


char* concatAll(const phrasesADT ph){
    return concat(ph, ph->keyFrom, ph->keyTo);
}

char* concat(const phrasesADT ph, size_t from, size_t to){
    if(from > to || ph->keyFrom > from || ph->keyTo < to)
        return NULL;
    char* string = calloc(1, 1);

    int space = 0;
    for(int i = INDEX(from, ph->keyFrom); i <= INDEX(to, ph->keyFrom); i++){   // itero sobre el array de structs
        if(ph->arrayElems[i].size != 0){
            space += ph->arrayElems[i].size;
            string = realloc(string, space + 1);
            strcat(string, ph->arrayElems[i].phrase);
        }
    }
    return string;
}

void freePhrases(phrasesADT ph){
    for(int i = 0; i <= INDEX(ph->keyTo, ph->keyFrom); i++){
        free(ph->arrayElems[i].phrase);
    }
    free(ph->arrayElems);
    free(ph);
}
