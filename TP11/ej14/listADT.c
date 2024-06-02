#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

// ES INCREIBLE LO FACIL QUE ME SALIO ESTE EJERCICIO, ENTENDI BIEN LOS ITERADORES

typedef struct node{
    struct node* tail;
    elemType head;
} tNode;

typedef tNode* List;

struct listCDT{
    List first;
    List iter;     // Es un puntero a un nodo que va a ser manipulado con las 3 funciones, permitiendo acceder al ultimo nodo insertado
    List iterAsc;  // Es un puntero a un nodo que va a ser manipulado con 3 funciones que permiten acceder a los elementos de manera ascendente
    compF cmp;
};

listADT newList(compF cmp){
    listADT newL = calloc(1, sizeof(struct listCDT));
    newL->cmp = cmp;
    return newL;
}

static List addRec(List node, elemType elem, compF cmp, listADT l){
    int c;
    if(node == NULL || (c = cmp(node->head, elem)) == 0){
        return node;
    }
    if(c > 0){
        List newNode = malloc(sizeof(*newNode));
        newNode->head = elem;
        newNode->tail = node;
        if(l->iter != NULL){
            l->iter->head = elem;
            l->iter = newNode;
        }
        if(l->iterAsc != NULL){
            l->iterAsc->head = elem;
            l->iterAsc = newNode;
        }
        return newNode;
    }
    node->tail = addRec(node->tail, elem, cmp, l);
    return node;
}

void add(listADT list, elemType elem){
    list->first = addRec(list->first, elem, list->cmp, list);
}

void toBegin(listADT list){
    list->iter = list->first;
}

int hasNext(listADT list){
    if(list->iter == NULL || list->iter->tail == NULL)
        return 0;
    return 1;
}

elemType next(listADT list){
    if(hasNext(list) == 0){
        exit(1);
    }
    list->iter = list->iter->tail;
    return list->iter->head;
}


void toBeginAsc(listADT list){
    list->iterAsc = list->first;
}

int hasNextAsc(listADT list){
    if(list->iterAsc == NULL || list->iterAsc->tail == NULL){
        return 0;
    }
    return 1;
}

elemType nextAsc(listADT list){
    if(list->iterAsc == NULL || hasNextAsc(list) == 0){
        exit(1);
    }
    list->iterAsc = list->iterAsc->tail;
    return list->iterAsc->head;
}


static void freeRec(List node){
    if(node == NULL){
        return ;
    }
    freeRec(node->tail);
    free(node);
}

void freeList(listADT list){
    freeRec(list->first);
    free(list);
}
