#include "dataADT.h"



int cmp(int n1, int n2){
    return n1 - n2;
}


int even(int n) {
    return n % 2 == 0;
}
int main(void) {
    dataADT data = newData(cmp); // Almacenaremos enteros ordenados en forma ascendente
    assert(addElement(data, 10) == 1);
    assert(addElement(data, 10) == 0);
    assert(addElement(data, 1) == 1);
    assert(addElement(data, 100) == 1);
    assert(addElement(data, 5) == 1);
    assert(addElement(data, 15) == 1);
    assert(addElement(data, 20) == 1);
    assert(countElement(data) == 6);
    size_t dim;
    int * v = elems(data, even, &dim);
    assert(dim == 3);
    assert(v[0] == 10 && v[1] == 20 && v[2] == 100);
    free(v);
    assert(countElement(data) == 6);
    assert(deleteElement(data, 20) == 1);
    assert(countElement(data) == 5);
    assert(deleteElement(data, 20) == 0);
    v = elems(data, even, &dim);
    assert(dim == 2);
    assert(v[0] == 10 && v[1] == 100);
    free(v);
    freeData(data);
    puts("OK!");
    return 0;
}
