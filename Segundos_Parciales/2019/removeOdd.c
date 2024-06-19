// Escribir una funcion removeOdd que reciba unicamente una lista de enteros y elimine de la misma todos los elementos en posicion impar.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




typedef struct node{
    int elem;
    struct node* tail;
} TNode;

typedef TNode* TList;

// TODO ESTO HECHO CON GPT PARA PROBAR EL PROGRAMA 

TList removeOdd(TList list);

void printList(TList list) {
    while (list != NULL) {
        printf("%d -> ", list->elem);
        list = list->tail;
    }
    printf("NULL\n");
}

TList createNode(int elem) {
    TList newNode = (TList)malloc(sizeof(TNode));
    newNode->elem = elem;
    newNode->tail = NULL;
    return newNode;
}

void appendNode(TList* list, int elem) {
    TList newNode = createNode(elem);
    if (*list == NULL) {
        *list = newNode;
    }
    else {
        TList temp = *list;
        while (temp->tail != NULL) {
            temp = temp->tail;
        }
        temp->tail = newNode;
    }
}

void freeList(TList* list) {
    TList temp;
    while (*list != NULL) {
        temp = *list;
        *list = (*list)->tail;
        free(temp);
    }
}

void test_removeOdd() {
    TList list1 = NULL;
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 3);
    appendNode(&list1, 4);
    appendNode(&list1, 5);
    list1 = removeOdd(list1);
    printList(list1); // Debe imprimir: 1 -> 3 -> 5 -> NULL
    freeList(&list1);

    TList list2 = NULL;
    appendNode(&list2, 6);
    appendNode(&list2, 7);
    appendNode(&list2, 8);
    appendNode(&list2, 9);
    list2 = removeOdd(list2);
    printList(list2); // Debe imprimir: 6 -> 8 -> NULL
    freeList(&list2);

    TList list3 = NULL;
    appendNode(&list3, 10);
    list3 = removeOdd(list3);
    printList(list3); // Debe imprimir: 10 -> NULL
    freeList(&list3);

    TList list4 = NULL;
    list4 = removeOdd(list4);
    printList(list4); // Debe imprimir: NULL
}

int main() {
    test_removeOdd();
    return 0;
}


TList removeOdd(TList node){
    if (node == NULL || node->tail == NULL){
        return node;
    }

    TList aux1 = node->tail;
    TList aux2 = aux1->tail;
    free(aux1);

    return removeOdd(aux2);
}

