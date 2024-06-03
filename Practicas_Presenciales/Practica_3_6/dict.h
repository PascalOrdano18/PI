//
// Created on 29/05/2024.
// Diccionario de palabras en inglés
// Las palabras son cortas, las definiciones pueden ser extensas
//

#ifndef UNTITLED8_DICTADT_H
#define UNTITLED8_DICTADT_H

#include <stdlib.h>

typedef struct dictCDT * dictADT;

dictADT newDict();

void freeDict(dictADT d);

// Agrega una copia de la palabra (si no estaba) y una copia de
// la definición. Si la palabra estaba no hace nada
void addWord(dictADT d, const char * word, const char * def);

void deleteWord(dictADT d, const char * word);

// Retorna un vector ordenado con la copia de las palabras
// que empiezan con la letra. Al final del vector hay un NULL
char ** wordsLetter(dictADT d, char letter);

// Todas las palabras, ordenadas alfabéticamente
char ** words(dictADT d);

// Retorna una copia de la definición de la palabra word
// Si la palbra no está retorna NULL
char * def(dictADT d, const char * word);

// Cantidad de palabras en el diccionario
size_t wordsCount(dictADT d);

#endif //UNTITLED8_DICTADT_H
