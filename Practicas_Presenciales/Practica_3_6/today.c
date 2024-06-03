//
// Created on 29/05/2024.
//
#include "dict.h"
#include <strings.h>   // para usar strcasecmp
#include <ctype.h>

#define LETTERS ('Z'-'A'+1)

typedef struct node {
    char * word;
    char * def;
    size_t lenDef; // longitud de def (cantidad de caracteres)
    struct node * tail;
} node;

typedef struct node * List;

struct letter {
    size_t wordsCount;  // Cantidad de palabras que empiezan con esta letra
    List first;   // La vieja y conocida lista
};

struct dictCDT {
    size_t count;  // Cantidad de palabras en el diccionario
    struct letter words[LETTERS];
};

dictADT newDict() {
    return calloc(1, sizeof(struct dictCDT));
}

void freeDict(dictADT d) {
    // NO hace falta if ( d==NULL)

}

void addWord(dictADT d, const char * word, const char * def) {
    if(!isalpha(word[0])) {
        return;
    }
}

void deleteWord(dictADT d, const char * word) {

}

char ** wordsLetter(dictADT d, char letter) {

}

char ** words(dictADT d) {

}

char * def(dictADT d, const char * word) {

}

size_t wordsCount(dictADT d) {
    return d->count;
}


static List getWordRec()


char* getDeff(const dictADT dict, const char* word){

}
