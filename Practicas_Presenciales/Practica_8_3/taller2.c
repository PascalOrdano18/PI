#include <stdio.h>

int main(void){

    int x = 1;
    int y = 2;
    int z = 3;
    int maximo;

    maximo = ( (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z ));


    printf("El maximo entre %d, %d y %d es => %d\n", x, y, z, maximo);
    return 0;

}

