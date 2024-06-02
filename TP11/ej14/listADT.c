#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

typedef struct node{
    struct node* tail;
    elemType head;
} tNode;

typedef tNode* List;

struct listCDT{
    List firstAsc;
    List firstInsert;    // Solo lo voy a usar en toBegin
    List lastInsert;
    List iterInsert;
    List iterAsc;
    compF cmp;
};

listADT newList(compF cmp){
    listADT newL = calloc(1, sizeof(struct listCDT));
    newL->cmp = cmp;
    return newL;
}

static List addRec(List node, elemType elem, compF cmp, int* added){
    int c;
    if(node == NULL || (c = cmp(elem, node->head)) < 0){
        List aux = malloc(sizeof(*node));
        aux->head = elem;
        aux->tail = node;
        *added = 1;
        return aux;
    }
    if(c > 0 ){
        node->tail = addRec(node->tail, elem, cmp, added);
    }
    return node;
}

void add(listADT list, elemType elem){
    int added = 0;
    list->firstAsc = addRec(list->firstAsc, elem, list->cmp, &added);
    if(added){
        List aux = malloc(sizeof(*aux));
        aux->head = elem;
        aux->tail = NULL;
        if(list->firstInsert == NULL){
            list->firstInsert = aux;
        }
        else{
            list->lastInsert->tail = aux;
        }
        list->lastInsert = aux;
    }
}

void toBegin(listADT list){
    list->iterInsert = list->firstInsert;
}

int hasNext(listADT list){
    return list->iterInsert != NULL;
}

elemType next(listADT list){
    if(hasNext(list) == 0){
        puts("Uso invalido de Next");
        exit(1);
    }
    elemType res = list->iterInsert->head;
    list->iterInsert = list->iterInsert->tail;
    return res;
}

void toBeginAsc(listADT list){
    list->iterAsc = list->firstAsc;
}

int hasNextAsc(listADT list){
    return list->iterAsc != NULL;
}

elemType nextAsc(listADT list){
    if(list->iterAsc == NULL || hasNextAsc(list) == 0){
        exit(1);
    }
    elemType res = list->iterAsc->head;
    list->iterAsc = list->iterAsc->tail;
    return res;
}


static void freeRec(List node){
    if(node == NULL){
        return ;
    }
    freeRec(node->tail);
    free(node);
}

void freeList(listADT list){
    freeRec(list->firstInsert);
    freeRec(list->firstAsc);
    free(list);
}
