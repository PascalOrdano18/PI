#include <assert.h>
#include <string.h>
#include "dictADT.h"
#include <stdlib.h>
#include <stdio.h>

// Asumimos que los strings de palabras y definiciones no serán muy largos
// De lo contrario hacer la copia de a bloques para no invocar a strlen
int
main(void) {
    dictADT dict = newDict();

//    size_t dim;
//    char ** w = words(dict, &dim);
//    assert(w==NULL);
//    w = wordsBeginWith(dict, 'a', &dim);
//    assert(w==NULL);

    addDefinition(dict, "oveja", "animal de 4 patas lanudo.");
    addDefinition(dict, "oveja", "apodo de Sergio Hernandez");
    addDefinition(dict, "abeja", "insecto que hace miel.");

//    char * s = getDeff(dict, "oveja");
//    assert(strcmp(s, "animal de 4 patas lanudo.apodo de Sergio Hernandez") == 0);
//    free(s);

    addDefinition(dict, "ozono", "...");
    addDefinition(dict, "oso", "...");

//    w = words(dict, &dim);
//    assert(dim==4);
//    assert(strcmp(w[0], "abeja")==0);
//    assert(strcmp(w[1], "oso")==0);
//    assert(strcmp(w[2], "oveja")==0);
//    assert(strcmp(w[3], "ozono")==0);
//    for(int i=0; i < dim; i++) {
//        free(w[i]);
//    }
//    free(w);

//    w = wordsBeginWith(dict, 'o', &dim);
//    assert(dim==3);
//    assert(strcmp(w[0], "oso")==0);
//    assert(strcmp(w[1], "oveja")==0);
//    assert(strcmp(w[2], "ozono")==0);
//    for(int i=0; i < dim; i++) {
//        free(w[i]);
//    }
//    free(w);
//
//    // Agregamos dos palabras: vino y cerveza
    char v[100] = "vino";
    addDefinition(dict, v, "...");
    strcpy(v, "cerveza");
    addDefinition(dict, v, "...");

//    freeDict(dict);

    puts("OK");
}
