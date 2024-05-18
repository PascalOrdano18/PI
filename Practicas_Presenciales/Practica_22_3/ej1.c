#include <stdio.h>
#include <math.h>
#include "../../getnum.h"

int esPrimo(int num);
int n_primos(int n);

int main(void) {
    // int numero = getint("Ingrese un numero\n");
    int n = getint("Ingrese la cantidad de primos que desea generar\t");
    n_primos(n);

}

int esPrimo(int num) {
    if (num % 2 == 1){
        int raiz = sqrt(num);
        for (int i = 3; i <= raiz; i+=2) {
            if (num % i == 0) {
                return 0;
            }
        }   
    } else {
        return 0;
    }
    return 1;
}

int n_primos (int n){
    int numero = 3;
    if (n != 0){
        printf("2\n");
    }
    while (n > 0){
        if (esPrimo(numero)){
            printf("%d\n", numero);
            n--;
        }
        numero += 2;
    }
    return 0;
}