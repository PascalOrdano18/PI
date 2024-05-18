// #include <stdio.h>
// #include "../getnum.h"

// int main(void){
//     float n;
//     int sum = 0;
//     printf("ingrese un numero\n");
    
//     while(((n = getchar()) != EOF) && n != '\n'){
//         if(n >= '0' && n <= '9'){
//             n = n - '0';
//             sum += n;
//         } else if (n == '.'){
//             sum = 0;
//         } else {
//             printf("Porfavor ingrese numeros\n");
//             return 1;
//         }
//     }
//     printf("La suma es: %d", sum);

//     return 0;
// }




#include <stdio.h>
#include "../getnum.h"

int main(void){
    float n;
    int sum = 0;
    int punto = 0;
    printf("ingrese un numero\n");
    
    while(((n = getchar()) != '\n') && (n >= '0' && n <= '9') || n == '.' ){
        if(punto == 0 && n == '.'){
            punto = 1;
        } else if (punto ==1){
            n -= '0';
            sum += n;

        }
    }
    printf("La suma es: %d", sum);

    return 0;
}