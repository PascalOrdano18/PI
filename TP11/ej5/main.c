#include <stdio.h>
#include <assert.h>
#include "complexADT.h"

#define EPS 0.01

int main(void) {
  complexADT comp1 = newComplexNumber( 1, 2 ); // comp1 = 1 + 2i
  complexADT comp2 = newComplexNumber( 2, -3 ); // comp2 = 2 - 3i
  complexADT ans;

  ans = sumNumbers( comp1, comp2 );
  assert( realPart(ans) - 3 < EPS && imaginaryPart(ans) + 1 < EPS );
  freeComplex( ans );

  ans = subNumbers( comp1, comp2 );
  assert( realPart(ans) - 1 < EPS && imaginaryPart(ans) - 5 < EPS );
  freeComplex( ans );

  ans = multiplyNumbers( comp1, comp2 );
  assert( realPart(ans) - 8 < EPS && imaginaryPart(ans) - 1 < EPS );
  freeComplex( ans );

  ans = divideNumbers( comp1, comp2 );
  assert( realPart(ans) + 0.31 < EPS && imaginaryPart(ans) - 0.54 < EPS );
  freeComplex( ans );

  ans = conjugateComplex( comp1 );
  assert( realPart(ans) - 1 < EPS && imaginaryPart(ans) + 2 < EPS );

  freeComplex( comp1 );
  freeComplex( comp2 );
  freeComplex( ans );

  printf("OK!\n");
}
