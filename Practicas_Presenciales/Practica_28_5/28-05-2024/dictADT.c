#include "dictADT.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LETRAS ('z' - 'a' + 1)
#define GETIDX(c) (tolower(c) - 'a')

// TODO Terminar la implementación

struct wordNode {
    char * word;
    size_t wordLength;
    char * definition;
    size_t definitionLength;
    struct wordNode * tail;
};

typedef struct wordNode * wordList;

struct wordLetter {
    wordList first;
    size_t size;
};

struct dictCDT {
    struct wordLetter vec[LETRAS];
    size_t wordCount;
};

dictADT
newDict(void) {
    return calloc(1, sizeof(struct dictCDT));
}

static wordList
addDefinitionRec(wordList l, const char * word, const char * deff, size_t * added) {
    int c;
    if(l == NULL || (c = strcmp(word, l->word)) < 0) {
        wordList aux = malloc(sizeof(struct wordNode));
        aux->wordLength = strlen(word);
        aux->word = strcpy(malloc(aux->wordLength + 1), word);
        aux->definitionLength = strlen(deff);
        aux->definition = strcpy(malloc(aux->definitionLength + 1), deff);
        aux->tail = l;
        *added = 1;
        return aux;
    }
    if(c == 0) {
        int newLength = l->definitionLength + strlen(deff);
        l->definition = realloc(l->definition, newLength + 1);
        strcpy(l->definition + l->definitionLength, deff);
        l->definitionLength = newLength;
        return l;
    }
    l->tail = addDefinitionRec(l->tail, word, deff, added);
    return l;
}

void
addDefinition(dictADT dict, const char * word, const char * deff) {
    int firstLetter = GETIDX(word[0]);
    wordList first = dict->vec[firstLetter].first;
    size_t added = 0;
    dict->vec[firstLetter].first = addDefinitionRec(first, word, deff, &added);
    dict->vec[firstLetter].size += added;
    dict->wordCount += added;
}
