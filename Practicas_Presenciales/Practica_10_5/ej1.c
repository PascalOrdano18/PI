#include <stdio.h>

int esPotenciaDe3(int number);

int main(void){

    int number = 27;
    int res = esPotenciaDe3(number);

    printf("%d", res);

    return 0;
}

int esPotenciaDe3(int number){
    if(number == 1 || number == 3)
        return 1;
    if(number % 3 != 0){
        return 0;
    return esPotenciaDe3(number/3);
}

