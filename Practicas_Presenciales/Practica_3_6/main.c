#include <stdio.h>
#include "dict.h"
#include <string.h>
#include <assert.h>

int main(void) {
    dictADT d = newDict();
    addWord(d, "casa", "Lugar habitable....");
    char aux[50] = "Casona";
    addWord(d, aux, "Como la casa pero mas grande");
    strcpy(aux,"tortuga");
    addWord(d, aux, "Animal......");

    addWord(d, "CASA", "......");  // no la agrega, ya está

    char ** w = wordsLetter(d, 'c');
    assert(strcmp(w[0],"casa" )==0);
    assert(strcmp(w[1],"Casona" )==0);
    assert(w[2]==NULL);

    // Liberar w[0], w[1], w

    puts("OK");
    return 0;
}
