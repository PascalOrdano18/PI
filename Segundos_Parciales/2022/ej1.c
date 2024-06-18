
#include <stdio.h>
#include <stdlib.h>

typedef struct node* TList;
typedef struct node{
    int elem;
    struct node* tail;
} TNode;

TList sortedList(TList list);



TList prepend(TList list, int value) {
    TNode* newNode = (TNode*) malloc(sizeof(TNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return list;
    }
    newNode->elem = value;
    newNode->tail = list;
    return newNode;
}

// Función para imprimir la lista
void printList(TList list) {
    while (list != NULL) {
        printf("%d -> ", list->elem);
        list = list->tail;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void freeList(TList list) {
    TNode* current;
    while (list != NULL) {
        current = list;
        list = list->tail;
        free(current);
    }
}




int main(void){
// Crear y probar la lista
    TList myList = NULL;
    myList = prepend(myList, 4);
    myList = prepend(myList, 3);
    myList = prepend(myList, 2);
    myList = prepend(myList, 1);

    printf("Original List: ");
    printList(myList);

    myList = sortedList(myList);
    printf("Sorted List: ");
    printList(myList);

    // Liberar la memoria utilizada por la lista
    freeList(myList);

    return 0;
}

TList sortedList(TList list){
    if(list == NULL || list->tail == NULL){
        return list;
    }
    TList aux = sortedList(list->tail);
    if(list->elem >= aux->elem){
        free(list);
        return aux;
    }
    list->tail = aux;
    return list;
}
