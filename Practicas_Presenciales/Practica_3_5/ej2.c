#include <stdio.h>
#include <stdlib.h>
#include "../../getnum.h"

#define TOTAL_ITEMS 2
#define MAX_LONG 10

typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;

typedef tItem tFactura[TOTAL_ITEMS];



void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
 
int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}


void cargar(tFactura fact, int cant){
    for(int i = 0; i < cant; i++){
        leerItem();
    }
    return ;
}

tItem leerItem(){
    tItem aux;

    //FALTA HACER DO WHILES PARA CORROBORAR QUE EL USUARIO INGRESE TODO DE MANERA CORRECTA
    //Y USAR BIEN EL FGETS PERO ESO SE VE MAS AL FINAL

    aux.codigo = getint("Ingrese el codigo del primer producto: \n");
    fgets(aux.desc, MAX_LONG, stdin);
    aux.precio = getfloat("Ingrese el precio del producto: \n");
}


float importe(tFactura f, int itemsTotales){
    float valorTotal = 0;
    for(int i = 0; i < itemsTotales; i++){
        valorTotal += f[i].precio;
    }
    return valorTotal;
}



