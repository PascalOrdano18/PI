#include <stdio.h>

int vecSum(int* vec, int dim);

int main(void){
    int dim = 6;
    int vec[] = {1, 2, 3, 4, 10, 20};
    int sum = vecSum(vec, dim);
    printf("La suma es: %d", sum);
    return 0;
}

int vecSum(int* vec, int dim){
    if(!dim){
        return 0;
    }
    return *vec + vecSum(vec+1, dim-1);
}

