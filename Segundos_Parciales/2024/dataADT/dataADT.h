#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef struct dataCDT * dataADT;
typedef int (*compare)(int n1, int n2);

typedef int elemType;
/* Crea un TAD de elementos genéricos
*/
dataADT newData(compare cmp);
/* Agrega el elemento #elem, si no estaba. Retorna 1 si lo agrega, 0 si no
*/
int addElement(dataADT data, elemType elem);
/* Elimina el elemento #elem, si estaba. Retorna 1 si lo elimina, 0 si no
*/
int deleteElement(dataADT data, elemType elem);
/* Retorna la cantidad de elementos
*/
size_t countElement(const dataADT data);
/* La función #filter retorna 1 si el elemento debe incluirse en la respuesta y 0 si no
* Retorna un vector ordenado con aquellos elementos que cumplan con el criterio
* Si no hay elementos que cumplan con el criterio retorna NULL y setea *dim en cero
*/
elemType * elems(const dataADT data, int (*filter) (elemType), size_t * dim);
/* Retorna 1 si el elemento #elem está entre los datos, 0 si no
*/
int isElement(const dataADT data, elemType elem);
/* Libera los recursos utilizados por el TAD
*/
void freeData(dataADT data);
