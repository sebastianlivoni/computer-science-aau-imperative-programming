/* 
 * Title: Write a program to display a centimeters-to-inches conversion table. The smallest and largest number of centimeters in the table are input values.
 * Description: Your table should give conversions in 10-centimeter intervals. One centimeter equals 0.3937 inch.
 * Assignment: Page 255 Programming Project 2
 * Link to assignment: Book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

#define INTERVAL 10
#define ONE_CENCTIMETER_IN_INCHES 0.3937

int main(void) {
  double x, y, low, high;

  printf("Please write a small and large number => ");

  while(scanf(" %lf %lf", &x, &y) != 2) {
    printf("Please write a correct small and large number => ");
    scanf("%*s"); //ignore it
  }

  low = y > x ? x : y;
  high = y > x ? y : x;

  printf("CENTIMERS TO INCHES CONVERSION TABLE\n");
  printf("centimeters      inches\n");
  for (double i = low; i <= high; i += INTERVAL) {
    printf("%.2lf %15.2lf \n", i, i * ONE_CENCTIMETER_IN_INCHES);
  }
}