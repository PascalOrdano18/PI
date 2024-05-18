#include <stdio.h>

int suma(int number);

int main(void){
    int number = 3498;
    printf("La suma de %d es %d", number, suma(number));
    return 0;
}

int suma(int number){
    if(!number){
        return 0;
    }
    return number%10 + suma(number/10);
}

