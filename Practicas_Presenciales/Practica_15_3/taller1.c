#include <stdio.h>
#include <math.h>
#include "../getnum.h"

int main(void){
    int a, b, c;
    double sol1, sol2;

    do {
        a = getint("Ingrese el coeficiente cuadratico\t");   
    } while (a == 0);
    
    b = getint("Ingrese el coeficiente lineal\t");
    c = getint("Ingrese el termino independiente\t");

    double discriminante = ((b*b) - (4*a*c));
    double raiz = sqrt(discriminante);
    
    if ((discriminante) < 0){
        printf("El discriminante es negativo, las raices son imaginarias");
    } else {
        sol1 = (-b + raiz) / (2*a);
        sol2 = (-b - raiz) / (2*a);
        printf("Las raices son: %g y %g\n", sol1, sol2);
    }
    return 0;
}
