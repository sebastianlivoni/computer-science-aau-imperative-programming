/* 
 * Title: Inden i eller uden for en cirkel
 * Description: Skriv et program med tre doubles r, x og y.   r fortolkes som radius af en cirkel omkring punktet (0,0). x og y er koordinaterne (x, y) af et punkt.
 * Assignment: 3.1
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-boolexp-slide-exercise-1.html
 * 
 * Programmers: Sebastian Livoni, Simon Halkjær Tander, Richard Avenia, Lasse Fjellanger, Jacob Kyed Andreassen
 * Date completed: September 15, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define DELTA 0.05

int main(void) {
  double r, x, y;
  double xy_length;

  printf("Input circle radius => ");
  scanf(" %lf", &r);

  printf("Input coordinates (x, y) => ");  
  scanf(" %lf %lf", &x, &y);

  xy_length = sqrt(x * x + y * y);
  
  if (fabs(xy_length - r) <= DELTA) {
      printf("Point (%.2f, %.2f) lies on the cirle\n", x, y);
  } else if (xy_length > r) {
      printf("Point (%.2f, %.2f) lies outside the circle\n", x, y);
  } else {
    printf("Point (%.2f, %.2f) lies within the circle\n", x, y);
  }

  return EXIT_SUCCESS;

}