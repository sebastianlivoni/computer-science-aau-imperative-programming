/* 
 * Title: x-y coordinate Quadrant
 * Description: Write a program that takes the x–y coordinates of a point in the Cartesian plane and prints a message telling either an axis on which the point lies or the quadrant in which it is found.
 * Assignment: Project 6
 * Link to assignment: Page 232
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 13, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {
  double x,y;

  printf("Type coordinate => ");
  int test = scanf("%lf %lf", &x, &y);

  if (test != 2) {
    printf("Please type 2 numbers!\n");
    return 1;
  }

  printf("(%.1lf, %.1lf) is ", x, y);

  (x == 0 && y == 0) ? printf("in the middle\n") : 0;

  (y == 0 && x != 0) ? printf("on the y-line\n") : 0;
  (x == 0 && y != 0) ? printf("on the x-line\n") : 0;

  if (x > 0) {
    if (y > 0) {
      printf("in quadrant I\n");
    } else if (y < 0) {
      printf("in quadrant IV\n");
    }
  } else if (x < 0) {
    if (y > 0) {
      printf("in quadrant II\n");
    } else if (y < 0) {
      printf("in quadrant III\n");
    }
  }
}