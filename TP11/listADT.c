#include "listADT.h"
#include <stdlib.h>


typedef struct node{
    elemType head;
    struct node* tail;
} tNode;

typedef tNode* tList;

struct listCDT{
    tList first;
    size_t elemCount;
    int (*cmpFun)(elemType, elemType);
};

listADT newList(int (*cmp)(elemType, elemType)){
    listADT l = malloc(sizeof(*l));
    l->first = NULL;
    l->elemCount = 0;
    l->cmpFun = cmp;
    return l;
}


int size(const listADT l){
    return l->elemCount;
}

int isEmpty(const listADT l){
    return l->elemCount == 0;
}


static tList addRec(listADT list, elemType elem, int (*cmp)(elemType, elemType)){
    int res = cmp(elem, list->head);
    if(list == NULL || res < 0){
        tList newNode = malloc(sizeof(tNode));
        newNode->head = elem;
        newNode->tail = list;
        return newNode;
    }

    if(res == 0){
        return list;
    }

    list->tail = add(elem, list->tail);

    return list;
}


int add(listADT l , elemType elem){
    l->first = addRec(l->first, elem, l->cmpFun);
}
