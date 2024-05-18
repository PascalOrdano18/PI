#include <stdio.h>
#include <string.h>
#include <ctype.h>

char esPalindromo(char* string);
int palindromoAux(char* string, int dim);
int getDim(char*string);

int main(void){

    char string[] = "anana";
    char result = esPalindromo(string);

    printf("%d", result);
    return 0;
}

char esPalindromo(char* string){
    int dim = getDim(string);
    return palindromoAux(string, dim);
}

int palindromoAux(char* string, int dim){
    if(dim <= 1){
        return 1;
    }
    return (*string == *(string+dim-1)) && palindromoAux(string+1, dim-2); 
}

int getDim(char*string){
    return strlen(string);
}
