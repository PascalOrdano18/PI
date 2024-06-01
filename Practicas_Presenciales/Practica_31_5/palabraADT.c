#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "palabraADT.h"

#define BLOCK 5

struct wordCDT{
    char* word;
    size_t size;
};

wordADT crearVacia(void){
    wordADT newW = calloc(1, sizeof(struct wordCDT));
    return newW;
}

wordADT addLetter(wordADT wordS, char letter){
    if(wordS->size % BLOCK == 0){
        wordS->word = realloc(wordS->word, (wordS->size + BLOCK) * sizeof(wordS->word));
    }
    wordS->word[wordS->size++] = letter;
    return wordS;
}

static void freeRec(char* word){
    if(*word == '\0')
        return ;
    freeRec(word + 1);
    free(word);
}

void destruirPalabra(wordADT pal){  // Actua como free
    freeRec(pal->word);
    free(pal);
}

wordADT crearDesde(char* s){
    wordADT newWF = malloc(sizeof(*newWF));
    newWF->size = strlen(s);
    newWF->word = malloc(newWF->size);
    strcpy(newWF->word, s);
    return newWF;
}
void mostrarPalabra(wordADT pal){
    for(int i = 0; pal->word[i] != '\0'; i++){
        printf("%c", pal->word[i]);
    }
}
