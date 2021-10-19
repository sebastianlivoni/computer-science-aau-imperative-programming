/*
 * Title: Celcius til fahrenheit med output parameter
 * Description: Omskriv nu funktionen således at fahrenheit temperaturen returneres gennem en output parameter - en pointer. Omskriv også main, således at kaldet ændres til denne nye parameterprofil.
 * Assignment: Opgave 6.1 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-functions-ex-output-pars-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 19, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

void convert_celcius_to_fahrenheit(double celcius, double *fahrenheit);

int main(void) {

  double celcius = 100;
  double fahrenheit;

  convert_celcius_to_fahrenheit(celcius, &fahrenheit);

  printf("%lf celcius in fahrenheit: %lf\n", celcius, fahrenheit);

}

void convert_celcius_to_fahrenheit(double celcius, double *fahrenheit) {
  *fahrenheit = celcius * 1.8 + 32;
}