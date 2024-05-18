#include <stdio.h>
#include "../../getnum.h"

int numerosAmigos(int numero1, int numero2);
int sumaDivisores(int num);

int main(void){
    long int numero1 = getint("Ingrese un numero\n");
    long int numero2 = getint("Ingrese otro numero\n");
    
    numerosAmigos(numero1, numero2) ? printf("Son amigos\n") : printf("No son amigos\n");
    
    return 0;
}

int numerosAmigos(int numero1, int numero2){
    int suma1 = sumaDivisores(numero1);
    int suma2 = sumaDivisores(numero2);

    return ((suma1 == numero2) && (suma2 == numero1));
}

int sumaDivisores(int num){
    int sumaDiv = 0;
    int half = num/2;

    for(int i = 1; i <= half; i++){
        if(num % i == 0){
            sumaDiv += i;
        }
    }
    return sumaDiv; 
}