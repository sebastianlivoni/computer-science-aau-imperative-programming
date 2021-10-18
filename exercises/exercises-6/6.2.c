/*
 * Title: Timer, minutter og sekunder - igen, igen
 * Description: Skriv nu en funktion, hours_minutes_seconds, som tager antal af sekunder som en input parameter, og som returnerer de tre outputs (timer, minutter og sekunder) som output parametre (pointere, call-by-reference).
 * Assignment: Opgave 6.2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-functions-ex-output-pars-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 18, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define SECONDS_PER_MINUTE (60)
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_WEEK (7 * SECONDS_PER_DAY)

void hours_minutes_seconds(int inputSeconds, int *hours, int *minutes, int *seconds);

int main() {
  int hours, minutes, seconds;
  int * phours = &hours,
      * pminutes = &minutes,
      * pseconds = &seconds;

  // jeg tænker at 8458 er input parameter og de tre andre er output parametre
  hours_minutes_seconds(8458, phours, pminutes, pseconds);
  //hours_minutes_seconds(8458, &hours, &minutes, &seconds);

  printf("Hours: %d, minutes: %d, seconds: %d\n", hours, minutes, seconds);
}

void hours_minutes_seconds(int inputSeconds, int *hours, int *minutes, int *seconds) {

  *hours = inputSeconds / SECONDS_PER_HOUR % 24;
  *minutes = inputSeconds / SECONDS_PER_MINUTE % 60;
  *seconds = inputSeconds % 60;

}