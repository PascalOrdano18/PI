#include <stdio.h>

int main(void){

    unsigned char var, var1, var2, var3, var4;
    var = 0xD8;
    var1 = (var >> 6) & 3;
    var2 = (var >> 4) & 3; 
    var3 = (var >> 2) & 3;
    var4 = var & 3;

    printf("%x %x %x %x", var1, var2, var3, var4);

    return 0;
}


