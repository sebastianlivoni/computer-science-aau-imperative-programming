/*
 * Title: Reduktion af et array
 * Description: I denne opgave skal I skrive en funktion som kombinerer alle n elementer i a, på samme måde som combine gør det for fire faste tal. 
 * Assignment: Opgave 9.3
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 22, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

double combine_right(double a[], int n, double (*combiner)(double, double));
double combine_left(double a[], int n, double (*combiner)(double, double));
double plus(double a, double b);

int main(void) {

  double array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

  printf("Sum: %lf\n", combine_right(array, ARRAY_SIZE, &plus));


  printf("Sum: %lf\n", combine_left(array, ARRAY_SIZE, &plus));

}

double plus(double a, double b) {
  return a + b;
}

double combine_right(double a[], int n, double (*combiner)(double, double)) {
  int sum = 0, last_combiner = a[n - 1];
  for (int i = n - 1; i > 0; i--) {
    last_combiner = combiner(a[i - 1], last_combiner);
  }

  return last_combiner;
}

double combine_left(double a[], int n, double (*combiner)(double, double)) {
  int sum = 0, last_combiner = a[0];
  for (int i = 0; i < n - 1; i++) {
    last_combiner = combiner(a[i + 1], last_combiner);
  }

  return last_combiner;
}
