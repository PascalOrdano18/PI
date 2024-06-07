#include "bibleADT.h"
#include <alloca.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT_LIBROS 76

typedef struct versiculos{
    char* verseText;
    size_t size;
}versiculos;
typedef versiculos* verse;

typedef struct book{
    verse verseArr;
    size_t size;
} book;

struct bibleCDT{
    book books[CANT_LIBROS];
};


bibleADT newBible(void){
    bibleADT newB = calloc(1, sizeof(struct bibleCDT));
    return newB;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char *verse){

    if(bible->books[bookNbr - 1].size < verseNbr){
        bible->books[bookNbr - 1].verseArr = realloc(bible->books[bookNbr - 1].verseArr, verseNbr * sizeof(versiculos));
        for(int i = bible->books[bookNbr - 1].size; i < verseNbr; i++){
            bible->books[bookNbr - 1].verseArr[i].size = 0;
            bible->books[bookNbr - 1].verseArr[i].verseText = NULL;
        }
        bible->books[bookNbr - 1].size = verseNbr;
    }

    if(bible->books[bookNbr - 1].verseArr[verseNbr - 1].size != 0){
        return 0;
    }
    bible->books[bookNbr - 1].verseArr[verseNbr - 1].size = strlen(verse);
    bible->books[bookNbr - 1].verseArr[verseNbr - 1].verseText = malloc(bible->books[bookNbr - 1].verseArr[verseNbr - 1].size + 1);
    strcpy(bible->books[bookNbr - 1].verseArr[verseNbr - 1].verseText, verse);
    return 1;
}



char* getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bible->books[bookNbr - 1].size < verseNbr || bible->books[bookNbr - 1].verseArr[verseNbr - 1].size == 0){
        return NULL;
    }
    char* copy = malloc(bible->books[bookNbr - 1].verseArr[verseNbr - 1].size + 1);
    strcpy(copy, bible->books[bookNbr - 1].verseArr[verseNbr - 1].verseText);

    return copy;
}



void freeBible(bibleADT bible){
    for(int i = 0; i < CANT_LIBROS; i++){
        for(int j = 0; j < bible->books[i].size; j++){
            free(bible->books[i].verseArr[j].verseText);
        }
            free(bible->books[i].verseArr);
    }
    free(bible);
}
