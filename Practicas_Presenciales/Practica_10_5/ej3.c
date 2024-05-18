#include <stdio.h>
#include <assert.h>

void recMinMax(const int vec[], int dim, int* min, int* max);

int main(void){

    int v[] = {3, 1, 5, 2, 6, 99, -3, 2};
    int min, max;
    recMinMax(v, 0, &min, &max);
    assert(min == 0 && max == 0);
    recMinMax(v, 1, &min, &max);
    assert(min == 3 && max == 3);
    recMinMax(v, 2, &min, &max);
    assert(min == 1 && max == 3);
    recMinMax(v, 3, &min, &max);
    assert(min == 1 && max == 5);
    recMinMax(v, 6, &min, &max);
    assert(min == 1 && max == 99);
    recMinMax(v, 8, &min, &max);
    assert(min == -1 && max == -1);
    printf("OK!\n");

    return 0;
}


// MI SOLUCION
// void recMinMax(const int vec[], int dim, int* min, int* max){
//     if(dim <= 0){
//         *min = 0;
//         *max = 0;
//         return ;
//     }
//     if(*vec < 1){
//         *min = -1; 
//         *max = -1;
//         return ;
//     }
//     if(dim == 1){
//         *min = *vec;
//         *max = *vec;
//         return ;
//     }
//     recMinMax(vec+1, dim-1, min, max);
//     if(*vec > *max && *max != -1){
//         *max = *vec;
//     }
//     if(*vec < *min && *min != -1){
//         *min = *vec;
//     }
// }

// SOLUCION DE JULI AHORRANDO LA EL CHEQUEO DE DIM == 1 Y APROBECHANDO EL CASO BASE DE DIM = 0 Y QUITANDO DOS CHEQUEOS DE *MIN == -1 Y *MAX == -1
void recMinMax(const int vec[], int dim, int* min, int* max){
    if(dim <= 0){
        *min = 0;
        *max = 0;
        return ;
    }
    if(*vec < 1){
        *min = -1; 
        *max = -1;
        return ;
    }
    recMinMax(vec+1, dim-1, min, max);
    if (*min == -1)
        return;
    if(*vec > *max ){
        *max = *vec;
    }
    if(*vec < *min || !*min){
        *min = *vec;
    }
}
