#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include "listADT.h"

// Si mi lista fuera de enteros ordenados en forma descendente
int cmpInts(int n1, int n2) {
    return n2 - n1;
}

int main(void) {
    listADT myList = newList((int (*) (char *, char*)) strcasecmp);
    assert(sizeList(myList)==0);
    assert(isEmptyList(myList));
    assert(insertList(myList, "hola")==1);
    assert(insertList(myList, "HOLA")==0);
    assert(insertList(myList, "hola y adios")==1);
    assert(sizeList(myList)==2);

    //assert(deleteList(myList, "no estoy")==0);

    freeList(myList);

    puts("OK!");
    return 0;
}
