#include <stdlib.h>

typedef struct vectorCDT * vectorADT;

typedef int elemType;	// Tipo de element a insertar

vectorADT newVector(void);

// Agrega elem en la posición index
// Si la posición ya estaba ocupada lo pisa
void addElement(vectorADT v, elemType elem, size_t index);

// Deja en out el elemento en la posición index y retorna 1
// Retorna 0 si no había un elemento en esa posición
size_t getElement(const vectorADT v, size_t index, elemType * out);

// Elimina el elemento en la posición index y retorna 1
// Si la posición estaba vacía no hace nada y retorna 0
size_t deleteElement(vectorADT v, size_t index);

// Retorna la cantidad de elementos presentes en el vector
size_t elementCount(const vectorADT v);

void freeVector(vectorADT v);
