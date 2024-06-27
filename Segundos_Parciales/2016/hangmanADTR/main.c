#include "hangmanADT.h"

int main() {
    // Crear el juego con un nivel máximo de 3
    hangmanADT game = newHangman(3);
    assert(game != NULL);  // Asegurarse de que el juego se creó correctamente

    // Agregar palabras al nivel 1
    char* words1[] = { "apple", "banana", "cherry", NULL };
    int added = addWords(game, words1, 1);
    assert(added == 3);  // Asegurarse de que se agregaron 3 palabras al nivel 1

    // Agregar palabras al nivel 2
    char* words2[] = { "dog", "elephant", "frog", NULL };
    added = addWords(game, words2, 2);
    assert(added == 3);  // Asegurarse de que se agregaron 3 palabras al nivel 2

    // Verificar el tamaño del nivel 1
    int level1Size = size(game, 1);
    assert(level1Size == 3);  // Asegurarse de que el tamaño del nivel 1 es 3

    // Verificar el tamaño del nivel 2
    int level2Size = size(game, 2);
    assert(level2Size == 3);  // Asegurarse de que el tamaño del nivel 2 es 3

    // Verificar que la función word devuelva una palabra válida del nivel 1
    char* aWordLevel1 = word(game, 1);
    assert(aWordLevel1 != NULL);
    assert((strcmp(aWordLevel1, "apple") == 0) ||
        (strcmp(aWordLevel1, "banana") == 0) ||
        (strcmp(aWordLevel1, "cherry") == 0));

    // Verificar que la función word devuelva una palabra válida del nivel 2
    char* aWordLevel2 = word(game, 2);
    assert(aWordLevel2 != NULL);
    assert((strcmp(aWordLevel2, "dog") == 0) ||
        (strcmp(aWordLevel2, "elephant") == 0) ||
        (strcmp(aWordLevel2, "frog") == 0));

    // Verificar todas las palabras del nivel 1
    char** level1Words = words(game, 1);
    assert(level1Words != NULL);  // Asegurarse de que el arreglo no es NULL
    assert(strcmp(level1Words[0], "apple") == 0);
    assert(strcmp(level1Words[1], "banana") == 0);
    assert(strcmp(level1Words[2], "cherry") == 0);

    // Verificar todas las palabras del nivel 2
    char** level2Words = words(game, 2);
    assert(level2Words != NULL);  // Asegurarse de que el arreglo no es NULL
    assert(strcmp(level2Words[0], "dog") == 0);
    assert(strcmp(level2Words[1], "elephant") == 0);
    assert(strcmp(level2Words[2], "frog") == 0);

    printf("Todas las pruebas pasaron correctamente.\n");

    return 0;
}

// int main(void) {
//     // Crear el juego con un nivel máximo de 3
//     hangmanADT game = newHangman(3);
//     assert(game != NULL);  // Asegurarse de que el juego se creó correctamente

//     // Agregar palabras al nivel 1
//     char* words1[] = { "apple", "banana", "cherry", NULL };
//     int added = addWords(game, words1, 1);
//     assert(added == 3);  // Asegurarse de que se agregaron 3 palabras al nivel 1

//     // Agregar palabras al nivel 2
//     char* words2[] = { "dog", "elephant", "frog", NULL };
//     added = addWords(game, words2, 2);
//     assert(added == 3);  // Asegurarse de que se agregaron 3 palabras al nivel 2

//     // Verificar el tamaño del nivel 1
//     int level1Size = size(game, 1);
//     assert(level1Size == 3);  // Asegurarse de que el tamaño del nivel 1 es 3

//     // Verificar el tamaño del nivel 2
//     int level2Size = size(game, 2);
//     assert(level2Size == 3);  // Asegurarse de que el tamaño del nivel 2 es 3

//     // // Verificar la última palabra del nivel 1
//     // char* lastWordLevel1 = word(game, 1);
//     // assert(strcmp(lastWordLevel1, "cherry") == 0);  // Asegurarse de que la última palabra del nivel 1 es "cherry"

//     // // Verificar la última palabra del nivel 2
//     // char* lastWordLevel2 = word(game, 2);
//     // assert(strcmp(lastWordLevel2, "frog") == 0);  // Asegurarse de que la última palabra del nivel 2 es "frog"

//     // Verificar todas las palabras del nivel 1
//     char** level1Words = words(game, 1);
//     assert(level1Words != NULL);  // Asegurarse de que el arreglo no es NULL
//     assert(strcmp(level1Words[0], "apple") == 0);
//     assert(strcmp(level1Words[1], "banana") == 0);
//     assert(strcmp(level1Words[2], "cherry") == 0);

//     // Verificar todas las palabras del nivel 2
//     char** level2Words = words(game, 2);
//     assert(level2Words != NULL);  // Asegurarse de que el arreglo no es NULL
//     assert(strcmp(level2Words[0], "dog") == 0);
//     assert(strcmp(level2Words[1], "elephant") == 0);
//     assert(strcmp(level2Words[2], "frog") == 0);

//     printf("Todas las pruebas pasaron correctamente.\n");

//     return 0;
// }