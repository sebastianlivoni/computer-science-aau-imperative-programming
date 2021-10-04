/* 
 * Title: Nye funktioner i gamle opgaver
 * Description: I lektionen om iterative kontrolstrukturer arbejdede vi med to opgaver, som vi nu vil tage op igen med det formål at indføre abstraktion med funktioner.
 * Assignment: Opgave 5.7
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-3.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

int sum_iter(int);
int sum_formula(int);
int population_projection(double, double, double);

int main(void) {

  //Programmeringsopgave 1 side 267
  printf("Sum-iter: %d\n", sum_iter(10));
  printf("Sum-formula: %d\n", sum_formula(10));

  //Population projection
  printf("Population projection: %d years\n", population_projection(9870, 0.10, 30000));

}

int sum_iter(int n) {
  int sum;
  for (int i; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int sum_formula(int n) {
  return (n + 1) * n / 2;
}

int population_projection(double population, double growth_rate_pr_year, double limit) {
  int count_year = 0;
  while (population <= limit) {
    population *= 1 + growth_rate_pr_year;
    count_year++;
  }
  return count_year;
}