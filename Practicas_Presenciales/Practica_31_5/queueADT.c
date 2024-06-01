#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_va_list.h>
#include "queueADT.h"

typedef struct node{
    elementType elem;
    struct node* tail;
} tNode;

typedef tNode* List;

struct queueCDT{
    List first;
    List last;
    size_t size;
    List iter;
};

queueADT newQueue(void){
    queueADT newQ = calloc(1, sizeof(struct queueCDT));
    return newQ;
}

void queue(queueADT q, elementType n){
    List newNode = malloc(sizeof(*newNode));
    newNode->elem = n;
    newNode->tail = NULL;

    if(q->first == NULL){
        q->first = newNode;
    } else {
        q->last->tail = newNode;
    }
    q->last = newNode;
    q->size++;
}

void dequeue(queueADT q, elementType *out){
    if(q->first == NULL){
        return;
    }
    List aux = q->first;
    *out = q->first->elem;
    q->first = aux->tail;
    free(aux);
}

int isEmpty(queueADT q){
    return (q->first == NULL);
}

static void freeRec(List l){
    if(l==NULL){
        return ;
    }
    freeRec(l->tail);
    free(l);
}
void freeQueue(queueADT q){
    freeRec(q->first);
    free(q);
}


void toBegin(queueADT q){
    q->iter = q->first;
}

int hasNext(queueADT q){
    return q->iter != NULL;
}

elementType next(queueADT q){
    elementType aux;
    if(hasNext(q)){
        aux = q->iter->elem;
        q->iter = q->iter->tail;
        return aux;
    }
    exit(1);
}
