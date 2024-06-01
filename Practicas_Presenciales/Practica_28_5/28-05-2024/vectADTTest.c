#include "vectADT.h"
#include <stdio.h>
#include <assert.h>

int
main(void) {
    vectorADT v = newVector();

    assert(elementCount(v) == 0);

    addElement(v, 15, 2);
    addElement(v, 31, 4);
    addElement(v, 32, 4);
    addElement(v, 7, 5);

    int aux;
    assert(getElement(v, 2, &aux) == 1);
    assert(aux == 15);
    assert(getElement(v, 4, &aux) == 1);
    assert(aux == 32);
    assert(getElement(v, 5, &aux) == 1);
    assert(aux == 7);
    assert(getElement(v, 100, &aux) == 0);
    assert(getElement(v, 0, &aux) == 0);

    assert(elementCount(v) == 3);

    assert(deleteElement(v, 4) == 1);
    assert(deleteElement(v, 100) == 0);

    assert(elementCount(v) == 2);

    assert(getElement(v, 4, &aux) == 0);

    assert(deleteElement(v, 5) == 1);

    assert(elementCount(v) == 1);

    freeVector(v);

    puts("OK!");
    return 0;
}
