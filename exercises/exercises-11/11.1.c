/*
 * Title: En Fibonacci funktion med huskeværk
 * Description: 
 * Assignment: Opgave 11.1 
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/recursion-fib3-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

long fib(long n){   
  long result;

  static int memory[45];

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else if (memory[n]) {
    result = memory[n] /*den huskede vaerdi*/;
  } else {
    result = fib(n-1) + fib(n-2);
    memory[n] = result;
    /* Husk paa vaerdien; */
  }

  return result;
}

long fibtest(int n){
  long result;

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else
    result = fibtest(n-1) + fibtest(n-2);

  return result;
}


int main(void) {
  long i;

  for(i = 0; i < 100; i++) {
    printf("Fib(%li) = %li\n", i, fib(i));
  }
  for(i = 0; i < 45; i++) {
    printf("Fib(%li) = %li\n", i, fibtest(i));
  }
  return 0;
}