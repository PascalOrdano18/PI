#include "bibleADT.h"
#include <stdlib.h>


#define BOOKS 76
#define BLOCK 40

typedef struct verse{
    char* text;
    size_t verseSize;
} verse;
typedef verse* TVerse;

typedef struct book{
    TVerse versiculo;
    size_t allocVerses;
} book;

struct bibleCDT{
    book libro[BOOKS];
};


bibleADT newBible(void){
    bibleADT new = calloc(1, sizeof(struct bibleCDT));
    return new;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bible->libro[bookNbr - 1].allocVerses < verseNbr){
        bible->libro[bookNbr - 1].versiculo = realloc(bible->libro[bookNbr - 1].versiculo, verseNbr * sizeof(*bible->libro[bookNbr - 1].versiculo));
        for(int i = bible->libro[bookNbr - 1].allocVerses; i < verseNbr; i++){
            bible->libro[bookNbr - 1].versiculo[i].text = NULL;
            bible->libro[bookNbr - 1].versiculo[i].verseSize = 0;
        }
        bible->libro[bookNbr - 1].allocVerses = verseNbr;
    }

    if(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize > 0){
        return 0;
    }

    // Realloc de a bloques
    int i;
    for(i = 0; *(verse + i) != 0; i++){
        if(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize % BLOCK == 0){
            bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize += BLOCK;
            bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text = realloc(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text, bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize + 1);
        }
        *(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text + i) = *(verse + i);
    }

    if(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize != i){
        bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text = realloc(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text, bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize + 1);
    }
    bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize = i + 1;   // Posiblemente es i + 1
    *(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text + i + 1) = 0;
    return 1;
}

char* getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize == 0){
        return NULL;
    }

    char* res = malloc(bible->libro[bookNbr - 1].versiculo[verseNbr - 1].verseSize + 1);

    strcpy(res, bible->libro[bookNbr - 1].versiculo[verseNbr - 1].text);
    return res;
}

void freeBible(bibleADT bible){
    for(int i = 0; i < BOOKS; i++){
        for(int j = 0; j < bible->libro[i].allocVerses; j++){
            free(bible->libro[i].versiculo[j].text);
        }
        free(bible->libro[i].versiculo);
    }
    free(bible);
}
