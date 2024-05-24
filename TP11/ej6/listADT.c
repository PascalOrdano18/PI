#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"


typedef struct node{
    elemType head;         // Como funciona esto? PREGUNTAR
    struct node* tail;
} node;

typedef struct node* List;

struct listCDT{
    List first;     // Puntero al primer nodo de la lista, esto no me permite acceder al tail de NADA, solo me da acceso a la lista en si, es decir a su primer nodo
    size_t size;
    compare cmp;       // Devuelve -1 si el primer elemento es "menor" (segun como lo defina el usuario) , 0 si es "igual" y 1 si es "mayor"
};


listADT newList(compare cmp){
    listADT lista = calloc(1, sizeof(struct listCDT));
    lista->cmp = cmp;
    return lista;
}

static void freeRec(List list){
    if(list == NULL)
        return ;
    freeRec(list->tail);
    free(list);
}

void freeList(listADT list){
    freeRec(list->first);
    free(list);
}


int isEmptyList(const listADT list){
    return list->first == NULL;
}

static int belongsListRec(List list, elemType elem, compare cmp){
    if(list == NULL){
        return 0;
    }
    int c = cmp(list->head, elem);
    if(c == 0){
        return 1;
    }
    if(c > 0){
        return 0;
    }
    // Sabemos que list->head es "menor" que elem
    return belongsListRec(list->tail, elem, cmp);
}

int belongsList(const listADT list, elemType elem){
    return belongsListRec(list->first, elem, list->cmp);
}

static List insertListRec(List list, elemType elem, compare cmp, int* flag){
    int c;
    if(list == NULL || (c = cmp(list->head, elem)) > 0){ // Pues si es mayor a cero ->
        List newNode = malloc(sizeof(node));
        newNode->head = elem;
        newNode->tail = list;
        *flag = 1;
        return newNode;
    }
    if(c < 0){
        // elem es "mayor" que el primero
        list->tail = insertListRec(list->tail, elem, cmp, flag);
    }
    return list;
}

// Retorna 1 si lo agrego y cero si ya estaba
int insertList(listADT list, elemType elem){
    int flag = 0;
    list->first = insertListRec(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}


int deleteList(listADT list, elemType elem){
    return 0;
}

int sizeList(const listADT list){
    return list->size;
}


static List getElementAtIndexRec(const List list, int index){
    if(list == NULL || !index)
        return list;
    return getElementAtIndexRec(list->tail, index-1);
}

// Quiero retornar la informacion en un nodo, entonces deberia retornar un puntero al nodo, List.
// Pero en el listADT.h no puedo definir un tipo de return como List
//
//  LO RESOLVI! TENIA QUE CREAR UN TYPEDEF EN EN ARCHIVO DE ENCABEZADO QUE FUNCIONE COMO List
Listh getElementAtIndex(const listADT list, int index){
    return getElementAtIndexRec(list->first, index);
}

void mapRec(List list, funcP funcion){
    if(list == NULL){
        return ;
    }
    list->head = funcion(list->head);
    mapRec(list->tail, funcion);
}

void map(listADT list, funcP funcion){
    mapRec(list->first, funcion);
}
