/* 
 * Title: Inden i eller uden for en cirkel
 * Description: CProgrammet skal afgøre om punktet (x, y) er placeret inden i cirklen, på cirkelperiferien, eller uden for cirklen. 
 * Assignment: 3.1
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-boolexp-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 11, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

//! Mangler DELTA der fortæller hvor meget vi ønsker at kunne afvige fra et "perfect hit"

#include <stdio.h>
#include <math.h>
#define DELTA 1

int main(void) {
  double r, x, y;

  printf("Skriv et punkt (x, y) => ");
  int check = scanf("%lf %lf", &x, &y);

  if (check != 2) {
    printf("Skriv 2 tal\n");
    return 1;
  }

  printf("Skriv radius => ");
  scanf("%lf", &r);

  double left_side = pow(x, 2) + pow(y, 2);
  double right_side = pow(r, 2);

  (left_side <= right_side)
    ? (left_side == right_side)
      ? printf("På periferien\n") 
      : printf("Inden i\n")
    : printf("Uden for\n");

}