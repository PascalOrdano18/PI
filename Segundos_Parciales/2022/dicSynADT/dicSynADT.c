#include "dicSynADT.h"

typedef struct node {
    char * synonym;
    struct node * tail;
} node;

typedef struct wordWithSyns {
    char * word;
    node * syns;
    struct wordWithSyns * tail;
} wordWithSyns;

struct dicSynCDT {
    size_t size; // cantidad de palabras
    wordWithSyns * first;
};

dicSynADT newDicSyn() {
    dicSynADT new = calloc(1, sizeof(struct dicSynCDT));
    return new;
}


size_t size(const dicSynADT dict) {
    return dict->size;
}
/*
** Busca el nodo con la palabra word. Si no estaba lo agrega en forma ascendente
** y hace que node apunte al nuevo nodo.
** Si ya estaba entonces node apunta al nodo que contiene word
*/
static wordWithSyns * addWord( wordWithSyns * first, const char * word, wordWithSyns ** node, int * flag) {
// NO COMPLETAR
}
void add(dicSynADT dict, const char * word, const char * synonymous) {
// Primero veo si hay que agregar word. Me retorna en un parámetro
// de salida una referencia al nodo, y en un flag retorna 0 si estaba o 1
// si lo agregó
    wordWithSyns * theWord;
    int flag = 0;
    dict->first = addWord(dict->first, word, &theWord, &flag);
    dict->size += flag;
    // En theWord tenemos el puntero al nodo con la palabra word
    // Completar el resto de la función
    dict->first = addWord(dict->first, synonymous, &theWord, &flag);
    dict->size += flag;
}
char ** synonyms(dicSynADT dict, const char * word) {
// Completar
}
char ** words(const dicSynADT dict) {
// Completar
}
void freeDict(dicSynADT dict) {
// NO completar
}
