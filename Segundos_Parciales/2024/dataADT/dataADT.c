#include "dataADT.h"
#include <stddef.h>
#include <stdlib.h>

#define BLOCK 10

typedef struct node{
    elemType elem;
    struct node* tail;
} TNode;
typedef TNode* TList;

struct dataCDT{
    TList first;
    compare cmp;
    size_t size;
};

dataADT newData(compare cmp){
    dataADT new = calloc(1, sizeof(struct dataCDT));
    new->cmp = cmp;
    return new;
}

static TList addElemRec(TList node, elemType elem, int* added, compare cmp){
    int c;
    if(node == NULL || (c = cmp(node->elem, elem)) > 0){
        TList new = malloc(sizeof(*new));
        new->elem = elem;
        new->tail = node;
        *added = 1;
        return new;
    }
    if(c == 0){
        return node;
    }
    node->tail = addElemRec(node->tail, elem, added, cmp);
    return node;
}


int addElement(dataADT data, elemType elem){
    int added = 0;
    data->first = addElemRec(data->first, elem, &added, data->cmp); // La unica razon por la que no agrega es si estaba el elemento -> si added es 0, el elemento ya existia
    data->size += added;
    return added;
}


static TList deleteElementRec(TList node, elemType elem, int* deleted, compare cmp){
    int c;
    if(node == NULL || (c = cmp(node->elem, elem)) > 0){
        return node;
    }
    if(c == 0){
        TList aux = node->tail;
        free(node);
        *deleted = 1;
        return aux;
    }
    node->tail = deleteElementRec(node->tail, elem, deleted, cmp);
    return node;
}


int deleteElement(dataADT data, elemType elem){
    int deleted = 0;
    data->first = deleteElementRec(data->first, elem, &deleted, data->cmp);
    data->size -= deleted;
    return deleted;
}

size_t countElement(const dataADT data){
    return data->size;
}

void fillVec(TList node, elemType* res, int (*filter) (elemType), size_t* dim){
    if(node == NULL){
        return ;
    }

    if(filter(node->elem)){  // Si retorna 1 -> lo meto al array
        (*dim)++;
        *res = node->elem;
        fillVec(node->tail, res + 1, filter, dim);
        return ;
    }
    fillVec(node->tail, res, filter, dim);
    return ;
}


elemType * elems(const dataADT data, int (*filter) (elemType), size_t * dim){
    *dim = 0;
    elemType* res = malloc(data->size * sizeof(*res));
    fillVec(data->first, res, filter, dim);
    res = realloc(res, *dim * sizeof(*res));
    return res;
}

int isElemRec(TList node, elemType elem, compare cmp){
    int c;
    if(node == NULL || (c = cmp(node->elem, elem)) > 0){
        return 0;
    }
    if(cmp == 0){
        return 1;
    }
    return isElemRec(node->tail, elem, cmp);
}

int isElement(const dataADT data, elemType elem){
    return isElemRec(data->first, elem, data->cmp);
}

void freeDataRec(TList node){
    if(node == NULL){
        return ;
    }
    freeDataRec(node->tail);
    free(node);
}

void freeData(dataADT data){
    freeDataRec(data->first);
    free(data);
}
