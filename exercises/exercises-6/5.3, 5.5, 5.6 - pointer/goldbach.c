/*
 * Title: Goldbachs Formodning
 * Description: Goldbachs formodning udtrykker en påstand om at alle lige heltal større end to er summen af to primtal. Denne formodning er hverken bevist eller modbevist. I denne opgave vil vi beskæftige os med følgende variation af påstanden:
 * Assignment: Opgave 5.3
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/functions-par-ex-2-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

void find_max_and_min(int a, int b, int *min, int *max);
int check();

int main(void) {

  int a, b;

  printf("Please write two numbers bigger than 6 => ");
  if (scanf(" %d %d", &a, &b) != 2 || a < 6 || b < 6) {
    printf("You must write two integers bigger than 6!\n");
    return EXIT_FAILURE;
  }

  int min;
  int max;
  
  find_max_and_min(a, b, &min, &max);

  if (min % 2 != 0) {
    min++;
  }
  
  for (int i = min; i <= max; i += 2) {
    if (check(i) == 0) {
      printf("Der er sgu sket noget som ikke må ske :(\n");
      return EXIT_FAILURE;
    }
  }

  printf("\nCongratulations! All integers between %d and %d is the sum of two odd prime numbers!\n", a, b);

  return EXIT_SUCCESS;
  
}

void find_max_and_min(int a, int b, int *min, int *max) {
  *min = a < b ? a : b;
  *max = b > a ? b : a;
}

int check(int n) {
  int max = n / 2;

  for (int i = 1; i <= max; i += 2) {
    if (is_prime(i) && is_prime(n - i)) {
      //printf("%d = %d + %d\n", n, i, n - i);
      return 1;
    }
  }

  return 0;

}