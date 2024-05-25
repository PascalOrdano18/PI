#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../utillist.h"


int main(void){
    // wordLettersMatch(lista);
    return 0;
}

// Parte a         (no tienen nada que ver la a y la b entre si)
int wordLettersMatch(TList l, char* s){
    if(l == NULL || s == NULL || *s == 0 || l->elem != *s)
        return 0;
    return 1 + wordLettersMatch(l->tail, s+1);
}

// Parte b
void count(char* s, int* pares, int * impares){
    if(*s == '\0'){
        *pares = 0;
        *impares = 0;
        return ;
    }
    count(s+1, pares, impares);
    // Es mejor primero hacer un if con isdigit
    if(isdigit(*s) && (*s - '0') % 2 == 0){
        (*pares)++;
    }
    if(isdigit(*s) && (*s - '0') % 2 != 0){
        (*impares)++;
    }
}



// Ej de parcial 2023 C2, HECHO POR OCTA

int contarGrupos(char* s, char letter){
    if(s == NULL || *s == 0 || *(s+1) == 0)
        return *s == letter;
    int aux = contarGrupos(s+1, letter);
    return (*s != *(s+1) && *s == letter) + aux;
}




// HACER EL MISMO EJERCICIO PERO EN LISTAS
