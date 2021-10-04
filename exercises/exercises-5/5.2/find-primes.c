/*
 * Title: Find de første n primtal
 * Description: Denne opgave giver dig blandt andet træning i programmering af et C program, der anvender en header file (.h fil) og en tilhørende .c fil.
 * Assignment: Opgave 5.2
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/functions-par-ex-2-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int main(void) {
  
  int i = 1, j = 0, n;

  printf("How many primes do you want to see: ");
  scanf(" %d", &n);

  while (j < n) {
    if (is_prime(i)) {
      j++;
      printf("prime: %d: %d\n", j, i);
    }
    i++;
  }
}


// gcc primes.c find-primes.c
// ./a.out