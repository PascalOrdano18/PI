#include <stdio.h>

int main(void){
    int num = 35;
    int rta;

    rta = (num <= 15 & num >= 0) ? ( (num > 9) ? 'A'+num-10 : '0'+num ) : num;

    printf("La respuesta es: %c\n", rta);
    

    return 0;
}