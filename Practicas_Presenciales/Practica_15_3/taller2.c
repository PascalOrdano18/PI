#include <stdio.h>
#include "../getnum.h"

int main(void){

    int sum = 0;
    int num = getint("Ingrese un numero");
    if (num < 0){
        num *= -1;
    }
    while(num > 0){
        sum += (num % 10);
        num = num/10;
    }
    printf("La suma es: %d", sum);
    return 0;
}
