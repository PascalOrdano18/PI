#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node{
    int elem;
    struct node* tail;
} TNode;

typedef TNode* TList;



TList removeRepeated(TList node){
    if (node == NULL || node->tail == NULL){
        return node;
    }

    TList aux = removeRepeated(node->tail);

    if (node->elem == aux->elem){
        node->tail = aux->tail;
        free(aux);
    }
    return node;
}



// Prototipo de la función removeRepeated
TList removeRepeated(TList node);

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

void test_removeRepeated() {
    TList list1 = NULL;
    appendNode(&list1, 1);
    appendNode(&list1, 2);
    appendNode(&list1, 2);
    appendNode(&list1, 3);
    appendNode(&list1, 4);
    appendNode(&list1, 4);
    appendNode(&list1, 4);
    appendNode(&list1, 5);
    list1 = removeRepeated(list1);
    printList(list1); // Debe imprimir: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Asertos para verificar la lista resultante
    assert(list1 != NULL && list1->elem == 1);
    assert(list1->tail != NULL && list1->tail->elem == 2);
    assert(list1->tail->tail != NULL && list1->tail->tail->elem == 3);
    assert(list1->tail->tail->tail != NULL && list1->tail->tail->tail->elem == 4);
    assert(list1->tail->tail->tail->tail != NULL && list1->tail->tail->tail->tail->elem == 5);
    assert(list1->tail->tail->tail->tail->tail == NULL);
    freeList(&list1);

    TList list2 = NULL;
    appendNode(&list2, 1);
    appendNode(&list2, 1);
    appendNode(&list2, 1);
    appendNode(&list2, 1);
    list2 = removeRepeated(list2);
    printList(list2); // Debe imprimir: 1 -> NULL

    // Asertos para verificar la lista resultante
    assert(list2 != NULL && list2->elem == 1);
    assert(list2->tail == NULL);
    freeList(&list2);

    TList list3 = NULL;
    appendNode(&list3, 1);
    appendNode(&list3, 2);
    appendNode(&list3, 3);
    appendNode(&list3, 4);
    appendNode(&list3, 5);
    list3 = removeRepeated(list3);
    printList(list3); // Debe imprimir: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Asertos para verificar la lista resultante
    assert(list3 != NULL && list3->elem == 1);
    assert(list3->tail != NULL && list3->tail->elem == 2);
    assert(list3->tail->tail != NULL && list3->tail->tail->elem == 3);
    assert(list3->tail->tail->tail != NULL && list3->tail->tail->tail->elem == 4);
    assert(list3->tail->tail->tail->tail != NULL && list3->tail->tail->tail->tail->elem == 5);
    assert(list3->tail->tail->tail->tail->tail == NULL);
    freeList(&list3);

    TList list4 = NULL;
    appendNode(&list4, 2);
    appendNode(&list4, 2);
    appendNode(&list4, 2);
    appendNode(&list4, 2);
    appendNode(&list4, 2);
    list4 = removeRepeated(list4);
    printList(list4); // Debe imprimir: 2 -> NULL

    // Asertos para verificar la lista resultante
    assert(list4 != NULL && list4->elem == 2);
    assert(list4->tail == NULL);
    freeList(&list4);

    TList list5 = NULL;
    appendNode(&list5, 1);
    appendNode(&list5, 1);
    appendNode(&list5, 2);
    appendNode(&list5, 3);
    appendNode(&list5, 3);
    appendNode(&list5, 4);
    appendNode(&list5, 4);
    appendNode(&list5, 5);
    list5 = removeRepeated(list5);
    printList(list5); // Debe imprimir: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Asertos para verificar la lista resultante
    assert(list5 != NULL && list5->elem == 1);
    assert(list5->tail != NULL && list5->tail->elem == 2);
    assert(list5->tail->tail != NULL && list5->tail->tail->elem == 3);
    assert(list5->tail->tail->tail != NULL && list5->tail->tail->tail->elem == 4);
    assert(list5->tail->tail->tail->tail != NULL && list5->tail->tail->tail->tail->elem == 5);
    assert(list5->tail->tail->tail->tail->tail == NULL);
    freeList(&list5);
}

int main() {
    test_removeRepeated();
    printf("All tests passed!\n");
    return 0;
}