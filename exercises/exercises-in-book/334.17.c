/*
 * Title: Beregning af arealet under en kurve
 * Description: 
 * Assignment: Afleveringsopgave 17 side 334
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-20/opgave-hints/noter-pspd7-334-17.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 30, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

double trap(double a, double b, int n, double (*f)(double));
double trapez_sum(double n, double (*f)(double), double h);
double h(double x);
double g(double x);

int main(void) {

  printf("Area of area below function h(x) = %.2f\n", trap(-2, 2, 2000, &h));

}

double trap(double a, double b, int n, double (f)(double)) {
  double T = 0,
         h = fabs((b - a) / n);

  T = (h / 2) * (f(a) + f(b) + 2 * trapez_sum(n, f, h));

  return T;
}

double trapez_sum(double n, double (*f)(double), double h) {
  double sum = 0, 
         x = 0,
         i;

  for (i = 1; i < n; i++) {
    x += h;
    sum += f(x);
  }
  return 2 * sum;
}

double h(double x) {
  return csqrt(4 - x * x);
}
double g(double x) {
  return x * x * sin(x);
}