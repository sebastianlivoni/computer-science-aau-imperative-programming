/*
 * Title: Polynomier
 * Assignment: Opgave 9.2 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-arrays-input-output-pars-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void get_polynomium(double coeff[], int *degreep);
double eval_polynomium(const double coeff[], int degree, double x);

int main(void) {

  double coeff[] = {5, 4, 9, 2, 1, 9, 4, 9, 2};
  int degree;
  get_polynomium(coeff, &degree);

}

void get_polynomium(double coeff[], int *degreep) {
  printf("Please write an integer of max 8 => ");
  scanf(" %d", degreep);

  double x;

  printf("Please write an x => ");
  scanf(" %lf", &x);

  printf("Sum: %lf", eval_polynomium(coeff, *degreep, x));
}

double eval_polynomium(const double coeff[], int degree, double x) {
  int sum = coeff[0];
  for (int i = 1; i < degree; i++) {
    sum += coeff[i] * pow(x, i);
  }
  return sum;
}