/* 
 * Title: Write an expression to test for each of the following relationships.
 * Assignment: Programming Exercise 1
 * Link to assignment: Page 205 in book
 * 
 * Programmers: Sebastian Livoni, Simon Halkjær Tander, Richard Avenia, Lasse Fjellanger, Jacob Kyed Andreassen
 * Date completed: September 15, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

// Programmeringsopgave 1, side 205. Skriv et program med de ønskede udtryk, som erklærer og initialiserer de variable som indgår i opgaven.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double water = 0.5;
  int age = 17, 
      y = 5, 
      x = 3, 
      z = 7, 
      w = 3, 
      year = 2015, 
      speed = 55;
  
  (18 <= age && age <= 21) ? printf("Age is between 18 and 21\n") : printf("Age is NOT between 18 and 21\n");

  (water < 1.5 && water > 0.1) ? printf("Less than 1.5 and greater than 0.1\n") : printf("Not\n");
  
  year % 4 == 0 ? printf("Year is divisible by 4\n") : printf("Year is not divisible by 4\n");

  speed > 55 ? printf("speed is greater than 55\n") : printf("speed is NOT over 55\n");

  (y > x && y < z) ? printf("y is greater than x and less than z\n") : printf("y is less than x or greater than z or both\n");

  (w == 6 || w <= 3) ? printf("w is equal to 6 or not greater than 3\n") : printf("w is not equal to 6 and greater than 3\n");

  return EXIT_SUCCESS;
}