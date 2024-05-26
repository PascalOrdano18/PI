

typedef struct setCDT* setADT;
typedef const char* elemType;
typedef int (*compare)(elemType c1, elemType c2);
typedef elemType* Array;


/* Retorna un nuevo conjunto vacío */
setADT newSet(compare func);

void freeSet(setADT set);

// Retorna 1 si esta vacio, 0 si no esta vacio
int isEmptySet(setADT set);

int setContains(const setADT set, elemType element);

// Retorna 1 si lo agrego, 0 si no
int addElement(setADT set, elemType element);

// Retorna 1 si lo elimino, 0 si no
int deleteElement(setADT set, elemType element);

int sizeSet(const setADT set);

setADT unionSet(setADT set1, setADT set2);

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2);
