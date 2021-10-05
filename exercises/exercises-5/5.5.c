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

int main(void) {
  int year;

  printf("Is Leap Year? => ");
  scanf(" %d", &year);

  printf("%s", isLeapYear(year) ? "Yes! It is leap year that year!\n" : "Nope! It is not leap year that year!\n");

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