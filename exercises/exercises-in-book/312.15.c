/*
 * Title: Approximate the value of p
 * Description: using the formula given including terms up through 1/99.
 * Assignment: Page 312 exercise 15
 * Link to assignment: In book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 26, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

void calc_pi();
void add(const int a, double *sum);
void subtract(const int a, double *sum);

int main(void) {

  calc_pi();

}

void calc_pi() {
  double sum = 1;
  for (int i = 3; i <= 300000; i += 2) {
    subtract(i, &sum);
    i += 2;
    add(i, &sum);
  }

  printf("Sum: %f\n", 4 * sum);
}

void add(const int a, double *sum) {
  *sum = *sum + 1 / (double) a;
  printf("add: 1 / %d\n", a);
}
void subtract(const int a, double *sum) {
  *sum = *sum - 1 / (double) a;
  printf("subtract: 1 / %d\n", a);
}