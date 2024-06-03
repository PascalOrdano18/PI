#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moveToFrontADT.h"

typedef struct node{
    elemType head;
    struct node* tail;
} node;

typedef node* List;

struct moveToFrontCDT{
    List first;
    List iter;
    compare cmp;
    size_t size;
};

static List addRec(List l, elemType elem, int* added, compare cmp);

moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT new = calloc(1, sizeof(struct moveToFrontCDT));
    new->cmp = cmp;
    return new;
}

static void freeRec(List l){
    if(l == NULL){
        return ;
    }
    freeRec(l->tail);
    free(l);
}

void freeMoveToFront(moveToFrontADT moveToFront){
    freeRec(moveToFront->first);
    free(moveToFront);
}

static List addRec(List l, elemType elem, int* added, compare cmp){
    if(l == NULL){
        List new = malloc(sizeof(node));
        new->head = elem;
        new->tail = NULL;
        *added = 1;
        return new;
    }
    if(cmp(l->head, elem) == 0)
        return l;
    l->tail = addRec(l->tail, elem, added, cmp);
    return l;
}

unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int added = 0;
    moveToFront->first = addRec(moveToFront->first, elem, &added, moveToFront->cmp);
    moveToFront->size += added;
    return added;
}

unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront){
    moveToFront->iter = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iter != NULL;
}

elemType next(moveToFrontADT moveToFront){
    if(!hasNext(moveToFront))
        exit(1);
    List aux = moveToFront->iter;
    moveToFront->iter = moveToFront->iter->tail;
    return aux->head;
}

static List findElem(List l, elemType elem, compare cmp, List* node){
    if(l == NULL){
        *node = NULL;
        return NULL;
    }
    if(cmp(l->head, elem) == 0){
        *node = l;
        return l->tail;
    }
    l->tail = findElem(l->tail, elem, cmp, node);
    return l;
}

elemType* get(moveToFrontADT moveToFront, elemType elem){
    List node;
    moveToFront->first = findElem(moveToFront->first, elem, moveToFront->cmp, &node);
    if(node == NULL){
        free(node);
        return NULL;
    }
    node->tail = moveToFront->first;
    moveToFront->first = node;
    elemType* aux = malloc(sizeof(elemType));
    *aux = node->head;
    return aux;
}
