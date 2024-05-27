#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"

// Lo hago con listas

typedef struct node{
    elemType head;
    struct node* tail;
    unsigned int appeared;   // En cada nodo guardo cuantas veces aparece ese elemento.
} tNode;

struct bagCDT{
    compare cmp;
    List first;
    size_t size;
};

static void freeBagRec(List list){
    if(list == NULL){
        return ;
    }
    freeBagRec(list->tail);
    free(list);
}
void freeBag(bagADT bag){
    freeBagRec(bag->first);
    free(bag);
}

bagADT newBag(compare cmp){
    bagADT nBag = calloc(1, sizeof(struct bagCDT));
    nBag->cmp = cmp;
    return nBag;
}

static unsigned int countRec(compare cmp, List list, elemType elem){
    if(list == NULL){
        return 0;
    }
    if(!cmp(list->head, elem)){
        return list->appeared;
    }
    return countRec(cmp, list->tail, elem);
}

unsigned int count(const bagADT bag, elemType elem){
    return countRec(bag->cmp, bag->first, elem);
}

static unsigned int sizeRec(List list){
    if(list == NULL)
        return 0;
    return (list->appeared == 1) + sizeRec(list->tail);
}

unsigned int size(const bagADT bag){
    return sizeRec(bag->first);
}

unsigned int add(bagADT bag, elemType elem){
    List newNode = malloc(sizeof(*newNode));
    newNode->head = elem;
    newNode->tail = bag->first;
    newNode->appeared = count(bag, newNode->head) + 1;
    bag->first = newNode;
    bag->size++;
    return newNode->appeared;
}

static List deleteRec(List list, elemType elem, compare cmp){
    if(list == NULL){
        return list;
    }
    if(!cmp(list->head, elem)){
        List nextNode = list->tail;
        free(list);
        return nextNode;
    }
    list->tail = deleteRec(list->tail, elem, cmp);
    return list;
}

unsigned int deleteB(bagADT bag, elemType elem){
    if(bag == NULL || bag->first == NULL){
        return 0;
    }
    bag->size--;
    deleteRec(bag->first, elem, bag->cmp);
    return count(bag, elem);
}

static elemType mostPopularRec(List list, int* counter){
    if(list == NULL){
        *counter = 0;
        return NULL;
    }
    elemType aux = mostPopularRec(list->tail, counter);
    if(list->appeared >= *counter){
        *counter = list->appeared;
        return list->head;
    }
    return aux;
}

elemType mostPopular(bagADT bag){
    assert(bag != NULL && bag->first != NULL);
    int counter;
    return mostPopularRec(bag->first, &counter);
}
