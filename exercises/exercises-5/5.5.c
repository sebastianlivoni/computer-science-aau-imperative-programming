/*
 * Title: Skudårsfunktionen
 * Description: rogrammer en ny skudårsfunktion med brug af && og ||, og uden brug af if-else og uden brug af betingede udtryk.
 * Assignment: Opgave 5.5
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

//Function declaration
int isLeapYear();
int isLeapYear_myversion();

int main(void) {
  int year;

  for (int i = 1900; i <= 2100; i++) {
    if (isLeapYear(i) != isLeapYear_myversion(i)) {
      printf("fail: %d: %d og %d", i, isLeapYear(i), isLeapYear_myversion(i));
    }
  }

}

int isLeapYear(int year){
  int res;
  if (year % 400 == 0)
    res = 1;
  else if (year % 100 == 0)
    res = 0;
  else if (year % 4 == 0)
    res = 1;
  else res = 0;
  return res;
}

int isLeapYear_myversion(int year){
  int res;

  res = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;

  return res;
}