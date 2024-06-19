#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node{
    int elem;
    struct node* tail;
} TNode;

typedef TNode* TList;




TList removeIf(TList node, int (*criteria) (int)){
    if (node == NULL){
        return node;
    }
    if (criteria(node->elem)){
        TList aux = node->tail;
        free(node);
        return removeIf(aux, criteria);
    }
    node->tail = removeIf(node->tail, criteria);
    return node;
}



// Prototipo de la función removeIf
TList removeIf(TList list, int (*criteria)(int));

// Función de criterio para eliminar números impares
int isOdd(int n) {
    return n % 2 != 0;
}

// Función de criterio para eliminar números pares
int isEven(int n) {
    return n % 2 == 0;
}

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

void test_removeIf() {
    // Test 1: Eliminar números impares
    TList list1 = NULL;
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 3);
    appendNode(&list1, 4);
    appendNode(&list1, 5);
    list1 = removeIf(list1, isOdd);
    printList(list1); // Debe imprimir: 2 -> 4 -> NULL

    // Asertos para verificar la lista resultante
    assert(list1 != NULL && list1->elem == 2);
    assert(list1->tail != NULL && list1->tail->elem == 4);
    assert(list1->tail->tail == NULL);
    freeList(&list1);

    // Test 2: Eliminar números impares
    TList list2 = NULL;
    appendNode(&list2, 6);
    appendNode(&list2, 7);
    appendNode(&list2, 70);
    appendNode(&list2, 8);
    appendNode(&list2, 9);
    list2 = removeIf(list2, isOdd);
    printList(list2); // Debe imprimir: 6 -> 70 -> 8 -> NULL

    // Asertos para verificar la lista resultante
    assert(list2 != NULL && list2->elem == 6);
    assert(list2->tail != NULL && list2->tail->elem == 70);
    assert(list2->tail->tail != NULL && list2->tail->tail->elem == 8);
    assert(list2->tail->tail->tail == NULL);
    freeList(&list2);

    // Test 3: Eliminar números impares
    TList list3 = NULL;
    appendNode(&list3, 1);
    appendNode(&list3, 3);
    appendNode(&list3, 5);
    list3 = removeIf(list3, isOdd);
    printList(list3); // Debe imprimir: NULL

    // Asertos para verificar la lista resultante
    assert(list3 == NULL);
    freeList(&list3);

    // Test 4: Lista vacía
    TList list4 = NULL;
    list4 = removeIf(list4, isOdd);
    printList(list4); // Debe imprimir: NULL

    // Asertos para verificar la lista resultante
    assert(list4 == NULL);
    freeList(&list4);
}

int main() {
    test_removeIf();
    printf("All tests passed!\n");
    return 0;
}