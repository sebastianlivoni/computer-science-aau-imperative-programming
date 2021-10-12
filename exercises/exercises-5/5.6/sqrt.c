/*
 * Title: Programmering af en kvadratrodsfunktion
 * Description: Programmer din egen kvadratrodsfunktion my_sqrt med brug af Newtons metode. Newtons metode gør det muligt for os at finde denne rod. 
 * Assignment: Opgave 5.6
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.00000001

void compare_sqrts();
double my_sqrt();
double newtons_method();

int main(void) {
  compare_sqrts(0, 25);
}

void compare_sqrts(int start, int end) {

  printf("+-------------+-----------------+-------------+\n");
  printf("|             |                 |             |\n");
  printf("|    Number   |  Seb's version  |    Math.h   |\n");
  printf("|             |                 |             |\n");
  for (double i = start; i <= end; i++) {
    printf("| %10lf  |   %10lf    | %10lf  |\n", i, my_sqrt(i), sqrt(i));
  }
}

double my_sqrt(double a) {
  if (a == 0) {
    return 0;
  } else if (a < 0) {
    return NAN;
  }

  double x = a, difference, new_x;

  do {
    new_x = newtons_method(x, a);
    difference = x - new_x;
    x = new_x;
  } while (difference > DELTA);

  return x;
}

double newtons_method(double x, double a) {
  return x - (pow(x, 2) - a) / (2 * x);
}