#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5; //i: 3, j: 4, k: 5
  int res1, res2, res3;
  
  i++; j--; ++k;

  printf("i: %d, j: %d, k: %d\n", i,j,k);  //i: 4, j: 3, k: 6

  res1 = --i; //res1: 3
  res2 = j++; //res2: 4
  res3 = --k; //res3: 5

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3); //res: 3, res2: 4, res3: 5
  printf("i: %d, j: %d, k: %d\n", i,j,k); //i: 4, j:3, k:6
  
  return 0;
}