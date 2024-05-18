#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01

float raizNR(float lastValue, int iter, float x);

int main(void){
    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

float raizNR(float lastValue, int iter, float x){
    if(x < 0)
        return -1;
    if(iter == 0)
        return lastValue;
    lastValue = (lastValue + (x/lastValue)) / 2.0;
    return raizNR(lastValue, iter-1, x);
}
