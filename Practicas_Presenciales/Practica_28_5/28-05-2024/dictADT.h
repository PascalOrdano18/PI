#include <stdio.h>

typedef struct dictCDT * dictADT;

dictADT newDict(void);

void freeDict(dictADT dict);

/* Recibe una palabra y una definición. Si la palabra existe, agrega la nueva
   definición a la  ya existente.
   Si la palabra no existe en el diccionario, la agrega junto con su definición
*/
void addDefinition(dictADT dict, const char* word, const char * deff);

/* Retorna una copia de la definición o NULL si no existe la palabra */
char * getDeff(const dictADT dict, const char* word);

/* Retorna un vector ordenado con la copia de todas las palabras que
   comienzan con una letra.
   Si no hay palabras que empiecen con la letra retorna NULL y *dim en cero
*/
char ** wordsBeginWith(const dictADT dict, char letter, size_t * dim);

/* Retorna un vector ordenado con la copia de todas las palabras del diccionario
   Si no hay palabras retorna NULL y *dim en cero
*/
char ** words(const dictADT dict, size_t * dim);

/* Remueve la palabra del diccionario. Si no existe no hace nada */
void removeWord(dictADT dict, const char * word);
