/*
 * Title: 
 * Description: 
 * Assignment: 
 * Link to assignment: 
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA 0.00000001

void compare_sqrts();
double my_sqrt();
double newtown_formula();

int main(void) {

  //compare_sqrts(0, 25);

  printf("lol: %.8lf\n", my_sqrt(16));

}

void compare_sqrts(int start, int end) {
  for (double i = start; i <= end; i++) {
    printf("my_sqrt(%lf): %lf - sqrt(%lf): %lf\n", i, my_sqrt(i), i, sqrt(i));
  }
}

double my_sqrt(double a) {
  double x = 17;
  for (int i = 0; i <= 100; i++) {
    //printf("%lf\n", 3 - (pow(3, 7) - 1000) / 7 * pow(3, 6));
    //printf("%.13lf\n", 3 - (pow(3, 7) - 1000) / (7 * pow(3, 6)));
    double new_x = newtown_formula(x);
    double difference = x - new_x;
    if (difference <= DELTA) {
      return new_x;
    }

    x = new_x;
  }

  return a;

}

double newtown_formula(double x) {
  //return x - (pow(x, 7) - 1000) / (7 * pow(x, 6));
  return x - (pow(x, 2) - 168) / (2 * x);
}
