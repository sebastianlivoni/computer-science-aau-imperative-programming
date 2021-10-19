/*
 * Title: Square root using formula NG = 0.5(LG + N/LG)
 * Assignment: Page 371 exercise 7
 * Link to assignment: In the book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 20, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.005

double compute_sqrt(double n);
void driver_function();

int main(void) {

  driver_function();

  return EXIT_SUCCESS

}

void driver_function() {
  const int SIZE = 5;
  double numbers[SIZE] = {120.5, 88, 36.01, 10000, 0.25};

  for (int i = 0; i < SIZE; i++) {
    printf("Square root of %.2lf = %.2lf\n", numbers[i], compute_sqrt(numbers[i]));
  } 
}

double compute_sqrt(double n) {

  double LG = 1.0, NG = 1.0;

  while (1) {
    NG = 0.5 * (LG + n / LG);
    if (fabs(LG - NG) <= DELTA)
      return NG;
    LG = NG;
  }

  return EXIT_FAILURE;

}