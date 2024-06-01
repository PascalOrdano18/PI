#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>
#include "rankingADT.h"


#define BLOCK 20

typedef elemType* rankingArr;


struct rankingCDT{
    rankingArr rank;
    compare cmp;
    size_t size;
};


rankingADT newRanking(elemType* elems, size_t dim, compare cmp){
    rankingADT newR = malloc(sizeof(struct rankingCDT));
    newR->size = dim;
    newR->cmp = cmp;
    newR->rank = malloc(dim * sizeof(elemType));
    if(dim == 0){
        newR->rank = NULL;
    } else {
        newR->rank = elems;
    }
    return newR;
}

static void swapRanks(rankingADT ranking, size_t posRanking){  // Swapea un elemento del array con el elemento previo, es decir, sube en el ranking
    elemType aux = ranking->rank[posRanking - 1];
    ranking->rank[posRanking - 1] = ranking->rank[posRanking];
    ranking->rank[posRanking] = aux;
}


void addRanking(rankingADT ranking, elemType elem){
    int pos;
    if((pos = position(ranking, elem)) != 0 && pos != 1){  // Lo swapeo con el de rank mayor
        swapRanks(ranking, pos);
        return ;
    }
    if(ranking->size % BLOCK == 0){
        ranking->rank = realloc(ranking->rank, (ranking->size + BLOCK) * sizeof(elemType));
    }
    ranking->rank[ranking->size++] = elem;
}

size_t size(const rankingADT ranking){
    if(ranking == NULL)
        return 0;
    return ranking->size;
}

int getPosRec(rankingArr r, elemType elem, size_t dim, compare cmp){
    if(cmp(*r, elem) == 0){      // Si cmp = 0, *r = elem -> retorno esa posicion
        return dim+1;
    }
    if(dim == 0){   // Si dim es 0, recorrio todo el array y no lo encontro ->  No estaba
        return 0;
    }
    return getPosRec(r+1, elem, dim-1, cmp);
}

int position(const rankingADT r, elemType elem){
    return getPosRec(r->rank, elem, r->size, r->cmp);
}

int getByRanking(rankingADT ranking, size_t n, elemType *elem){
    if(n >= ranking->size){
        return 0;
    }
    *elem = ranking->rank[n-1];
    return 1;
}
