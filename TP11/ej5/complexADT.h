
typedef struct complexCDT * complexADT;

// Crea un nuevo numero complejo
complexADT newComplexNumber(double real, double imaginary);


// Recibe el numero complejo y retorna la parte real
double realPart(const complexADT number);

// Recibe el numero complejo y retorna la parte imaginaria
double imaginaryPart(const complexADT number);

// Recibe dos numeros complejos y los suma, retornando otro complejo como resultado
complexADT sumNumbers(const complexADT number1, const complexADT number2);

// Recibe dos numeros complejos y los resta, retornando otro complejo como resultado
complexADT subNumbers(const complexADT number1, const complexADT number2);

// Recibe dos numeros complejos y los multiplica, retornando otro complejo como resultado
complexADT multiplyNumbers(const complexADT number1, const complexADT number2);

// Recibe dos numeros complejos y los divide, retornando otro complejo como resultado
complexADT divideNumbers(const complexADT number1, const complexADT number2);

// Recibe un numero complejo y retorna su conjugado
complexADT conjugateComplex(const complexADT number);

// Libera la memoria alocada por el numero complejo
void freeComplex(complexADT number);
