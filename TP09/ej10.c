#include <stdio.h>
#include <assert.h>
#include <string.h>

char* invierte(char* input, char* output);
char* invertir(char* input, char* output, int length);

int main(void) {

  char s[20] = {0};

  invierte("1234567890", s);
  assert(strcmp(s, "0987654321")==0);

  memset(s, 0, 20);
  invierte("", s);
  assert(strcmp(s, "")==0);

  memset(s, 0, 20);
  invierte("a", s);
  assert(strcmp(s, "a")==0);

  memset(s, 0, 20);
  invierte("ab", s);
  assert(strcmp(s, "ba")==0);
  
  memset(s, 0, 20);
  invierte("abc", s);
  assert(strcmp(s, "cba")==0);

  printf ("OK!\n");
  return 0;
}


char* invierte(char* input, char* output){
    int length = strlen(input);
    return invertir(input, output, length);
}

char* invertir(char* input, char* output, int length){
    if(length == 0)
        return output;
    *output = *(input+length-1);
    return invertir(input, output+1, length-1);
}


