#include <stdio.h>

int productoEsc(int* vec1, int* vec2, const int dim);

int main(void){
    const int dim = 3;
    int vec1[dim] = {1, 2, 3};
    int vec2[dim] = {1, 2, 0};
    int result = productoEsc(vec1, vec2, dim);
    printf("El resultado es: %d", result);
    return 0;
}

int productoEsc(int* vec1, int* vec2, const int dim){
    if(!dim){
        return 0;
    }
    return ((*vec1) * (*vec2)) + productoEsc(vec1 + 1, vec2 + 1, dim - 1);
}
