// Escribir una funcion removeOdd que reciba unicamente una lista de enteros y elimine de la misma todos los elementos en posicion impar.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




typedef struct node{
    int elem;
    struct node* tail;
} TNode;

typedef TNode* TList;



TList removeOdd(TList node){
    if (node == NULL || node->tail == NULL){
        return node;
    }

    TList aux1 = node->tail;
    TList aux2 = aux1->tail;
    free(aux1);

    return removeOdd(aux2);
}

