// Opgave 11 side 125 i Problem Solving and Program Design in C, eighth edition.

#include <stdio.h>

int main(void) {
  int m, n, check;
  
  printf("Type the value for m and n:\n");
  check = scanf("%d %d", &m, &n);

  if (check == 2) {
    if (m > n && m > 0 && n > 0) {
      printf("side1: %d\n", m * m - n * n);
      printf("side2: %d\n", 2 * m * n);
      printf("hypotenuse: %d\n", m * m + n * n);
    } else {
      printf("m must be bigger than n and both numbers must be bigger than 0!\n");
    }
  } else {
    printf("Please type two numbers splitted by a whitespace\n");
  }
  
  return 0;
}