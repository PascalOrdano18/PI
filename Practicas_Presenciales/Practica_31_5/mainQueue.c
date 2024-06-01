#include <stdio.h>
#include <assert.h>
#include "queueADT.h"

int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    toBegin(q);
    assert(hasNext(q) && next(q) == 5);
    assert(hasNext(q) && next(q) == 9);
    assert(hasNext(q) && next(q) == 3);
    assert(hasNext(q) == 0);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    toBegin(q);
    assert(hasNext(q) == 0);
    freeQueue(q);
    printf("OK!\n");
    return 0;
}
