#include <stdio.h>
#include "../getnum.h"

int main(void){

    int sum = 0;
    float num = getfloat("Ingrese un numero");
    // if (num < 0){
    //     num *= -1;
    // }
    int num_entero = 0;

    while((num-num_entero) > 0.0){
        num_entero = num;
        num -= num_entero;
        num *= 10;
        sum += (((int)num) % 10);
        num_entero = num;
    }
    printf("La suma es: %d", sum);
    return 0;
}
