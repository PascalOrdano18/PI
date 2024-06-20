#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int elem;
    struct node* tail;
} TNode;
typedef TNode* TList;


TList iter(TList l1, TList l2){
    if (l1 == NULL || l2 == NULL){
        return NULL;
    }

    if (l1->elem > l2->elem){
        return iter(l1, l2->tail);
    }
    if (l1->elem < l2->elem){
        return iter(l1->tail, l2);
    }

    TList newNode = malloc(sizeof(*newNode));
    newNode->elem = l1->elem;
    newNode->tail = iter(l1->tail, l2->tail);
    return newNode;
}

// Prototipo de la función inter
TList iter(TList list1, TList list2);

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

void test_iter() {
    // Test 1: Intersección no vacía
    TList list1a = NULL;
    appendNode(&list1a, 1);
    appendNode(&list1a, 4);
    appendNode(&list1a, 8);
    appendNode(&list1a, 21);
    appendNode(&list1a, 23);

    TList list1b = NULL;
    appendNode(&list1b, 1);
    appendNode(&list1b, 3);
    appendNode(&list1b, 4);
    appendNode(&list1b, 21);

    TList result1 = iter(list1a, list1b);
    printList(result1); // Debe imprimir: 1 -> 4 -> 21 -> NULL

    // Asertos para verificar la lista resultante
    assert(result1 != NULL && result1->elem == 1);
    assert(result1->tail != NULL && result1->tail->elem == 4);
    assert(result1->tail->tail != NULL && result1->tail->tail->elem == 21);
    assert(result1->tail->tail->tail == NULL);
    freeList(&result1);
    freeList(&list1a);
    freeList(&list1b);

    // Test 2: Intersección vacía
    TList list2a = NULL;
    appendNode(&list2a, 6);
    appendNode(&list2a, 7);
    appendNode(&list2a, 8);
    appendNode(&list2a, 9);

    TList list2b = NULL;
    appendNode(&list2b, 5);

    TList result2 = iter(list2a, list2b);
    printList(result2); // Debe imprimir: NULL

    // Asertos para verificar la lista resultante
    assert(result2 == NULL);
    freeList(&result2);
    freeList(&list2a);
    freeList(&list2b);
}

int main() {
    test_iter();
    printf("All tests passed!\n");
    return 0;
}

