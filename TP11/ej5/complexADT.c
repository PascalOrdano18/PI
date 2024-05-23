#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include "complexADT.h"
#include <assert.h>

struct complexCDT{
    double real;
    double imaginary;
};


complexADT newComplexNumber(double real, double imaginary){
    complexADT newNumber = calloc(1, sizeof(struct complexCDT));
    newNumber->real = real;
    newNumber->imaginary = imaginary;
    return newNumber;
}

double realPart(const complexADT number){
    return number->real;
}

double imaginaryPart(const complexADT number){
    return number->imaginary;
}

complexADT sumNumbers(const complexADT number1, const complexADT number2){
    complexADT newNumber = calloc(1, sizeof(struct complexCDT));
    newNumber->real = number1->real + number2->real;
    newNumber->imaginary = number1->imaginary + number2->imaginary;
    return newNumber;
}

complexADT subNumbers(const complexADT number1, const complexADT number2){
    complexADT newNumber = calloc(1, sizeof(struct complexCDT));
    newNumber->real = number1->real - number2->real;
    newNumber->imaginary = number1->imaginary - number2->imaginary;
    return newNumber;
}


complexADT multiplyNumbers(const complexADT number1, const complexADT number2){
    complexADT newNumber = calloc(1, sizeof(struct complexCDT));
    newNumber->real = number1->real * number2->real;
    newNumber->imaginary = number1->imaginary * number2->imaginary;
    return newNumber;
}

// Esto es lo unico que no anda, no se dividir complejos tengo que volver a ingreso
complexADT divideNumbers(const complexADT number1, const complexADT number2){
    complexADT aux = calloc(1, sizeof(struct complexCDT));
    complexADT num = multiplyNumbers(number1, number2);
    double div = (number2->real * number2->real) - (number2->imaginary * number2->imaginary);
    aux->real = num->real / div;
    aux->imaginary = num->imaginary / div;
    return aux;
}

complexADT conjugateComplex(const complexADT number){
    complexADT conjugateNumber = calloc(1, sizeof(struct complexCDT));
    conjugateNumber->real = number->real;
    conjugateNumber->imaginary = -number->imaginary;
    return conjugateNumber;
}


void freeComplex(complexADT number){
    if(number != NULL){
        free(number);
    }
}
