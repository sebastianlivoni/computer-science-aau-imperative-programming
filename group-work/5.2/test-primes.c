/*
 * Title: Primes
 * Description: Udskriver de første primtal
 * Assignment: Opgave 5.2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/functions-par-ex-2-slide-exercise-1.html
 * 
 * Programmer: Gruppe
 * Date completed: October 13, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include "primes.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

int main(void) {
  int count_primes = 0;
  int i = 0;

  while (count_primes <= 100) {
    if (is_prime(i)) {
      printf("prime %d: %d\n", count_primes, i);
      count_primes++;
    }
    i++;
  }

}