#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct dicSynCDT * dicSynADT;
/* Retorna un nuevo diccionario de sinónimos. Al inicio está vacío.
** No hay límite de capacidad.
*/
dicSynADT newDicSyn();
/* Agrega una relación entre una palabra y su sinónimo
** Se asegura que tanto word como synonymous no son NULL ni vacíos
** Ver ejemplo de uso
*/
void add(dicSynADT dict, const char * word, const char * synonymous);
/* Retorna cuántas palabras hay en el diccionario. Se cuentan tanto las palabras
** como los sinónimos (los parámetros word y synonymous de la función anterior)
*/
size_t size(const dicSynADT dict);
/* Dada una palabra retorna un vector con una copia de todos sus sinónimos
** ordenados alfabéticamente, con NULL como marca de final
*/
char ** synonyms(dicSynADT dict, const char * word);
/* Retorna un vector con las palabras y sinónimos del diccionario (ver ejemplo)
** El vector está ordenado en forma ascendente y contiene NULL como marca de
** final.
** Si no hay palabras, retorna un vector que sólo contiene NULL
*/
char ** words(const dicSynADT dict);
/* Libera toda la memoria reservada */
void freeDict(dicSynADT dict);
