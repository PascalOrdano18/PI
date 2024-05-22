#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIVISIONES 100000
#define EPSILON 0.0000001
#define FUNCION(x) sin((x))
#define DISTANCIA(x, y) (y)-(x)
#define BLOQUE 100   //podria tener 50 raices, pues por cada raiz se usan dos elementos del array

typedef struct{
    int from;
    int upTo;
} Intervalo;

typedef struct{
    float from;
    float upTo;
} IntervaloRaiz;

typedef struct fun{
    double (*funcion)(double);
    char* name;
} Functions;

typedef struct{
    IntervaloRaiz* vecAparecidos;
    int dimRaices;
} Apariciones;

void getIntervalo(Intervalo* intervalo);
Functions getFuncion(Functions funciones[], size_t dim);
Apariciones buscaRaices(Intervalo* intervalo, Functions funcion);
void reallocateMemo(Apariciones* apariciones);
void guardarRaices(Apariciones* apariciones, float i, float step);
void printResults(Apariciones aparicionesResult);

int main(void){

    Functions funciones[] = {
        { sin, "sin" },
        { cos, "cos" },
        { log, "log" },
        { tan, "tan" },
        { sqrt, "sqrt"},
        { cosh, "cosh"}
      };
    Functions funcion = getFuncion(funciones, sizeof(funciones)/sizeof(*funciones));
    Intervalo intervalo = {0,0};
    getIntervalo(&intervalo);
    Apariciones aparicionesResult = buscaRaices(&intervalo, funcion);

    printResults(aparicionesResult);

    free(aparicionesResult.vecAparecidos);
    return 0;
}

Apariciones buscaRaices(Intervalo* intervalo, Functions funcion){
    Apariciones apariciones;
    apariciones.vecAparecidos = malloc(BLOQUE * sizeof(IntervaloRaiz));
    apariciones.dimRaices = 0;

    int moduloDistancia = DISTANCIA(intervalo->from, intervalo->upTo);
    float step = (float)moduloDistancia/DIVISIONES;

    for(float i = intervalo->from; i < (intervalo->upTo - step); i += step){
        float funcionI = funcion.funcion(i);
        float funcionIpStep = funcion.funcion(i+step);
        if(funcionI * funcionIpStep <= 0){  // TEOREMA DE BOLZANO
            if(!(apariciones.dimRaices % BLOQUE)){
                reallocateMemo(&apariciones);
            }
        guardarRaices(&apariciones, i, step);
        }
        else if (funcionI <= EPSILON && funcionIpStep >= EPSILON){
            if(!(apariciones.dimRaices % BLOQUE)){
                reallocateMemo(&apariciones);
            }
            guardarRaices(&apariciones, i, step);
        }
    }
    return apariciones;
}
void guardarRaices(Apariciones* apariciones, float i, float step){
    apariciones->vecAparecidos[apariciones->dimRaices].from = i;
    apariciones->vecAparecidos[apariciones->dimRaices].upTo = i+step;
    apariciones->dimRaices++;
}

void reallocateMemo(Apariciones* apariciones){
    apariciones->vecAparecidos = realloc(apariciones->vecAparecidos,  (apariciones->dimRaices + BLOQUE) * sizeof(IntervaloRaiz));
}

Functions getFuncion(Functions funciones[], size_t dim){
    int choice = 0;
    do{
        puts("Seleccione la funcion a analizar:\n");
        for(int i = 0; i < dim; i++){
            printf("%d -> %s(x)\n", i+1, funciones[i].name);
        }
        scanf("%d", &choice);
    }while(choice < 1 || choice > dim);
    return funciones[choice-1];
}

void getIntervalo(Intervalo* intervalo){
    do{
        printf("Ingrese el primer y ultimo valor del intervalo: \nDesde: ");
        scanf("%d", &intervalo->from);
        printf("\nHasta: ");
        scanf("%d", &intervalo->upTo);

        printf("El intervalo es [%d ; %d]", intervalo->from,intervalo->upTo);
    } while(intervalo->from >= intervalo->upTo);
    return;
}

void printResults(Apariciones aparicionesResult){
    printf("\nRaices encontradas: %d\n", aparicionesResult.dimRaices);

    for(int i = 0; i < aparicionesResult.dimRaices;i++){
        printf("Entre: %f\ty %f\n", aparicionesResult.vecAparecidos[i].from, aparicionesResult.vecAparecidos[i].upTo);
    }
    return ;
}
