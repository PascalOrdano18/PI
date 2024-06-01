#include "vectADT.h"

// Encapsulo el elemType con su flag de aparicion
struct elemWithFlag {
    elemType elem;
    char flag;
};

struct vectorCDT {
    struct elemWithFlag * elements; // vector dinámico de estructuras
    size_t size; // espacio reservado
    size_t elemCount; // cantidad de elementos
};

vectorADT newVector(void) {
    return calloc(1, sizeof(struct vectorCDT));
}

size_t elementCount(const vectorADT v) {
    return v->elemCount;
}

void freeVector(vectorADT v) {
    free(v->elements);
    free(v);
}

static int
validIndex(const vectorADT v, size_t index) {
    return index < v->size && v->elements[index].flag;
}

size_t getElement(const vectorADT v, size_t index, elemType * out) {
    if(!validIndex(v, index)) {
        return 0;
    }
    *out = v->elements[index].elem;
    return 1;
}

size_t deleteElement(vectorADT v, size_t index) {
    if(!validIndex(v, index)) {
        return 0;
    }
    v->elements[index].flag = 0;
    v->elemCount--;
    return 1;
}

void addElement(vectorADT v, elemType elem, size_t index) {
    if(index >= v->size) {
        v->elements = realloc(v->elements, (index + 1) * sizeof(struct elemWithFlag));
        for(int i = v->size; i <= index; i++) {
            v->elements[i].flag = 0;
        }
        v->size = index + 1;
    }
    v->elements[index].elem = elem;
    if(!v->elements[index].flag)
        v->elemCount++;
    v->elements[index].flag = 1;
}
