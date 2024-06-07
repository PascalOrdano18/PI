#include "squirrelADT.h"
#include <stdlib.h>



typedef size_t* colsA;

typedef struct rows{
    colsA squirrelsInCol;
    size_t colsSize;
} rows;

typedef rows* rowsA;

struct squirrelCensusCDT{
    size_t blockSizeMeters;
    rowsA rows;
    size_t rowsSize;
};

#define NORMALIZE(distance, blockSizeMeters) ((distance) / (blockSizeMeters))


squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres){
    if(blockSizeMetres == 0){
        exit(1);
    }
    squirrelCensusADT newC = malloc(sizeof(struct squirrelCensusCDT));
    newC->blockSizeMeters = blockSizeMetres;
    newC->rows = malloc(sizeof(rows));
    return newC;
}

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    size_t row = NORMALIZE(yDistance, squirrelAdt->blockSizeMeters);
    size_t col = NORMALIZE(xDistance, squirrelAdt->blockSizeMeters);

    if(row > squirrelAdt->rowsSize){
        squirrelAdt->rows = realloc(squirrelAdt->rows, row * sizeof(rows));
        for(int i = squirrelAdt->rowsSize; i < row; i++){
            squirrelAdt->rows[i] = 0;
            squirrelAdt->rowsSize = row;
        }
        squirrelAdt->rowsSize = row;
    }
    if(col > squirrelAdt->rows[row].colsSize){
        squirrelAdt->rows[row].squirrelsInCol = realloc(squirrelAdt->rows[row].squirrelsInCol, col * sizeof(size_t));
        squirrelAdt->rows[row].colsSize = col;
    }

}

// size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){

// }
