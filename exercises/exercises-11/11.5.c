/*
 * Title: Rekursive udgaver af Euclids algoritme
 * Description: 
 * Assignment: Opgave 11.5
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/recursion-opgaver-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>

int gcd_recursive(int large, int small) {
  int remainder;
  if (small == 0) {
    return large;
  } else {
    remainder = large % small;
    return gcd_recursive(small, remainder);
  }
}

int gcd(int i, int j) {
  int small, large;

  small = i <= j ? i : j;
  large = i <= j ? j : i;

  return gcd_recursive(large, small);
}

int gcd_recursive_sub(a, b) {
  if (a == b) {
    return a;
  } else if (a > b) {
    return gcd_recursive_sub(a - b, b);
  } else {
    return gcd_recursive_sub(a, b - a);
  }
}

int gcd_sub(int i, int j) {
  int small, large;

  small = i <= j ? i : j;
  large = i <= j ? j : i;

  return gcd_recursive_sub(large, small);
}


int main(void) {
  unsigned int k;

  int i = 9000, j = 49460;                    

  printf("GCD: %d og %d er %d\n", i, j, gcd(i, j));
  printf("GCD: %d og %d er %d\n", i, j, gcd_sub(i, j));
  
  return 0;
}