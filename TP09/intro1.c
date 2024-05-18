#include <stdio.h>

void palotes(size_t cant);

int main(void){

    size_t cant = 100;

    palotes(cant);

    return 0;
}


void palotes(size_t cant){
    if(!(cant)){
        return;
   }
    printf("|");
    palotes(cant-1);
    return ;
}


