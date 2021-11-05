/*
 * Title: Heltalsdivision og restuddragning med rekursive funktioner
 * Description: 
 * Assignment: Opgave 11.3 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/recursion-power3-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

int quotient(int dividend, int divisor);
int modulus(int dividend, int divisor);

int main(void) {

  printf("%d\n", quotient(13, 5));
  printf("%d\n", modulus(13, 5));

}

int quotient(int dividend, int divisor) {
  if (dividend >= divisor) {
    return 1 + quotient(dividend - divisor, divisor);
  } else {
    return 0;
  }
}

int modulus(int dividend, int divisor) {
  if (dividend >= divisor) {
    return modulus(dividend - divisor, divisor);
  } else {
    return dividend;
  }
}