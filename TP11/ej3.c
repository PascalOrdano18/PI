// ¿Qué indican las siguientes expresiones?

// OJO creo que tengo mal los primeros

int *(*p) (int (*a)[ ]);    // es un puntero a funcion p que recibe un array de punteros a int y devuelve un puntero a int
int *p[10];    // array de punteros a int. Tiene 10 elementos, 10 punteos a int
int (*p)[10];    // es un puntero a un array de 10 elementos que son ints
int *p(void);     // es una funcion que recibe void y retorna puntero a int
p (char *a);      // es una funcion que recibe un puntero a char. Esta incompleta, no especifica el tipo del return
int *p(char *a);   // es una puntero a una funcion que recibe un puntero a char y devuelve un int
int (*p) (char *a);     // un puntero a una funcion que recibe un putnero a char y retorna un int
int (*p(char *a))[10];   //p es una función que toma un puntero a char y retorna un puntero a un array de 10 enteros.
int p(char (*a)[ ]);    // p es una funcion que recibe un puntero a un array de chars y retorna un int
int p(char *a[ ]);   // p es una funcion que recibe un array de punteros a char y retorna int
int *p(char a[ ]);     // un puntero a una funcion que recibe un arreglo de chars y retorna un int
int *p(char (*a)[ ]);   // es un puntero a una funcion que recibe un puntero a un array de char y retorna un int
int *p(char *a[ ]);    // es una funcion que recibe un array de punteros a char y retorna un puntero a int
int (*p)(char(*a)[ ]);   // es un puntero a funcion que recibe un puntero a array de char y retorna int
int *(*p)(char *a[ ]);   // es un puntero a funcion que recibe un array de punteros a char y retorna un puntero a int
int (*p[10])(void);     //  es un array de 10 punteros a funcion que reciben void y retornan int
int (*p[10])(char a);   // es un array de 10 punteros a funcion que reciben char y retornarnan int
int *(*p[10])(char a);   // es un array de 10 punteros a funcion que reciben un char y retornan un puntero a int
int *(*p[10])(char *a);  // es un array de 10 punteros a funcion que reciben un puntero a char y retornan un puntero a int
int (*p) (char *a[ ]);  // es un puntero a funcion que recibe un array de punteros a char y retorna un int
