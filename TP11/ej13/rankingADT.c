#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rankingADT.h"

struct rankingCDT{
    elemType* rank;
    compare cmp;
    size_t size;
};

static void swapRanks(rankingADT ranking, int pos);

rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
  rankingADT newR = malloc(sizeof(struct rankingCDT));
  newR->size = dim;
  newR->cmp = cmp;

  if(dim > 0){
      newR->rank = malloc(dim * sizeof(elemType));
      for(int i = 0; i < dim; i++){
          newR->rank[i] = elems[i];
    }
  }
  else{
      newR->rank = NULL;
  }
  return newR;
}


static void swapRanks(rankingADT ranking, int pos){
    if(pos == 1 || pos > ranking->size)
        return ;
    int index = pos - 1;
    elemType aux = ranking->rank[index];
    ranking->rank[index] = ranking->rank[index-1];
    ranking->rank[index-1] = aux;
}

void addRanking(rankingADT ranking, elemType elem){
    int pos = position(ranking, elem);
    if(pos != 0){   // Significa que esta en el ranking y no es el Top 1
        swapRanks(ranking, pos);
        return ;
    }
    ranking->rank = realloc(ranking->rank, (ranking->size+1) * sizeof(elemType));
    ranking->rank[ranking->size] = elem;
    ranking->size++;
    return ;
}


size_t size(const rankingADT ranking){
    return ranking->size;
}

int position(const rankingADT r, elemType elem){
    for(int i = 0; i < r->size; i++){
        if(r->cmp(r->rank[i], elem) == 0)
        return i + 1;   // Pues i es el indice pero necesito la posicion en el ranking, que empieza en 1
    }
    return 0;  // Si no encontro nada, retorna cero
}

int getByRanking(rankingADT ranking, size_t n, elemType* elem){
    int index = n-1;
    if(n > ranking->size || n < 1)
        return 0;
    *elem = ranking->rank[index];
    if(n > 1)
        swapRanks(ranking, n);
    return 1;
}

elemType* getTopRanking(const rankingADT ranking, size_t* top){
    if(ranking->size == 0){
        *top = 0;
        return NULL;
    }
    if(*top > ranking->size)
        *top = ranking->size;
    elemType* topArr = malloc(*top * sizeof(elemType));
    for(int i = 0; i < *top; i++)
        topArr[i] = ranking->rank[i];
    return topArr;
}

int contains(rankingADT ranking, elemType elem){
    int pos = position(ranking, elem);
    if(pos == 0)
        return 0;
    if(pos != 1)
        swapRanks(ranking, pos);
    return 1;
}

void downByRanking(rankingADT ranking, size_t n){
    if(n < ranking->size)
        swapRanks(ranking, n+1);
}

void freeRanking(rankingADT r){
    free(r->rank);
    free(r);
}
