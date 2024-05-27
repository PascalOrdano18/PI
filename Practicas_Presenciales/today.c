


static List removeElem(List list, elemType elem, int* value, compare cmp){
    int aux;
    if(list = NULL || ((aux = cmp(list->head, elem)) < 0)){
        return list;
    }
    if(aux == 0){
        List nextNode = list->tail;
        free(list);
        *value = 1;
        return nextNode;
    }
    list->tail = removeElem(list->tail, elem, value, cmp);
    return list;
}

int removeElem(listADT l, elemType elem){
    int value = 0;
    l->first = removeElemRec(l->first, elem, &value, l->cmp);
    l->elemCount -= value;
    return value;
}

static elemType getElementAtIndexRec(List list, int idx){
    if(idx == 0){
        return list->head;
    }
    return getElementAtIndexRec(list->tail, idx-1);
}
elemType getElementAtIndex(const listADT l, int idx){
    if(idx < 0 || l->elemCount <= idx){
        exit 1;
    }
    return getElementAtIndexRec(l->first, idx);
}


static void selectRec(List list, int (*criteria)(elemType)){
    if(list == NULL){
        return NULL;
    }

    if(criteria(list->head)){

    }

}

#define BLOCK 10

elemType* select(listADT l, int (*criteria)(elemType)){
    elemType* toReturn = NULL;

    int allocated = 0;
    List aux = l->first;
    for(int i = 0; i < l->elemCount; i++){
        if(crit(aux->head)){
            if(allocated % BLOCK == 0){
                toReturn = realloc(toReturn, (k + BLOCK) * sizeof(elemType));
            }
            toReturn[allocated++] = aux->head;
        }
    }
    toReturn = realloc(toReutrn, allocated * sizeof(elemType));
    return toReturn;
}
