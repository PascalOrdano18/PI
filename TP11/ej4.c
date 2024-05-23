p es un arreglo de punteros a funciones que no reciben parámetros y devuelven punteros a double.

double * (*p[])(void)

p es una función que recibe un puntero a char y devuelve un puntero a un arreglo de 3x5 enteros.

int (*p(char* a))[3][5];

p es un puntero a un arreglo de N punteros a función que reciben un entero y retornan un puntero a entero.

int* (**p[N])(int a);
