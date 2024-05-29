#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictADT.h"


#define LETRAS 'z' - 'a' - 1
#define GETIDX(c) (tolower(c) - 'a')


struct wordNode {
    char* word;
    char* definition;
    size_t wordLength;
    size_t definitionLength;
    struct wordNode* tail;
};

typedef struct wordNode* wordList;

struct wordLetter{
    wordList first;
    size_t size;
};

struct dictCDT{
    struct wordLetter vec[LETRAS];
};



dictADT newDict(void){
    return calloc(1, sizeof(struct dictCDT));
}



static wordList addDefinitionRec(wordList l, const char* word, const char* deff){
    int c;
    if(l == NULL || (c = strcmp(word, l->word)) < 0){
        wordList aux = malloc(sizeof(struct wordNode));
        aux->wordLength = strlen(word) + 1;
        aux->word = strcpy(malloc(strlen(word) + 1), word);
        aux->definitionLength = strlen(deff);
        aux->definition = strcpy(malloc(aux->definitionLength + 1), deff);
        aux->tail = NULL;
        return aux;
    }
    if(c == 0){
        l->wordLength += strlen(deff);
        l->definition = realloc(l->definition, l->wordLength);
    }
}


void addDefinition(dictADT dict, const char* word, const char* deff){
    int firstLetter = GETIDX(word[0]);
    wordList first = dict->vec[firstLetter].first;

    dict->vec[firstLetter].first = addDefinition(first, word, deff);
}
