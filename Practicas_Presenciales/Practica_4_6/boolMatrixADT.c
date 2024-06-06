
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "boolMatrixADT.h"

struct boolCol{
    size_t colNumber;
    struct boolCol* tail;
};


typedef struct boolCol* boolColList;

struct boolRowNode{
    size_t rowNumber;
    boolColList cols;
    struct boolRowNode* tail;
};

typedef struct boolRowNode* boolRowList;


struct boolMatrixCDT{
    boolRowList rows;
};

boolMatrixADT newBoolMatrix(void){
    return calloc(1, sizeof(struct boolMatrixCDT));
}

static boolRowList getRowRec(boolRowList l, size_t row){
    if(l == NULL || l->rowNumber > row)
        return NULL;
    if(l->rowNumber == row)
        return l;
    return getRowRec(l->tail, row);
}



static boolColList getColRec(boolColList l, size_t col){
    if(l == NULL || l->colNumber > col)
        return NULL;
    if(l->colNumber == col)
        return l;
    return getColRec(l->tail, col);
}



boolean getValue(const boolMatrixADT m, size_t row, size_t col){

}

static boolColList setColRec(boolColList l, size_t col, boolean value){
    if(l == NULL || l->colNumber )
}

static boolRowList setRowRec(boolRowList l, size_t row, size_t col, boolean value){
    if(l == NULL || l->rowNumber < row){
        if(value == true){
            boolRowList newRow = malloc(sizeof(*newRow));
            newRow->rowNumber = row;
            newRow->tail = l;
            newRow->cols = setColRec(NULL, col, value);
        }
        return l;
    }
    if(l->rowNumber == row){
        l->cols = setColRec(l->cols, col, value);
        if(l->cols == NULL){
            boolRowList aux = l->tail;
            free(l);
            return aux;
        }
        return l;
    }
    l->tail = setRowRec(l->tail, row, col, value);
    return l;
}


void setValue(boolMatrixADT m, size_t row, size_t col, boolean value){
    m->rows = setRowRec(m->rows, row, col, value);
}
