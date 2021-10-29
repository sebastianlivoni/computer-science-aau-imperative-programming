/*
 * Title: Conversion from string to double and int
 * Description: Write a type int function strtoint and a type double function strtodouble that convert string representations of numbers to their numeric equivalents.
 * Assignment: Opgave 1 side 518 i afsnit 8.7 i Problem Solving and Program Design in C, eighth edition.
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 28, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strtoint(const char str[]);
double strtodouble(const char str[]);

int main(void) {
  char test[] = "500";

  printf("Number %f\n", strtodouble("-75.812"));

}

int strtoint(const char str[]) {
  int val;
  sscanf(str, "%d", &val);
  return val;
}

double strtodouble(const char str[]) {
  double val;
  sscanf(str, "%lf", &val);
  return val;
}