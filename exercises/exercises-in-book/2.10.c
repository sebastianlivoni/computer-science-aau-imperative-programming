// Chapter 2 - Opgave 10

// Write a program that outputs the equation of the perpendicular bisector of the line segment between two points. Your program should

#include <stdio.h>
#include <math.h>
int main(void) {
  double x1, x2, y1, y2;
  double slope;
  printf("Input Point 1 (x, y) => ");
  scanf("%lf, %lf", &x1, &y1);
  printf("Input Point 2 (x, y) => ");
  scanf("%lf, %lf", &x2, &y2);
  slope = (y2 - y1) / (x2 - x1);
  double mid_x, mid_y;
  mid_x = (x1 + x2) / 2;
  mid_y = (y1 + y2) / 2;
  double slope_pb = pow(slope, -1) * -1.0;
  double y_intercept = mid_y - slope_pb * mid_x;
  printf("\n\nPoint 1 (%.1f, %.1f)\nPoint 2 (%.1f, %.1f)\nFormula of the perpendicular bisector: y = %.1fx + %.2f\n", x1, y1, x2, y2, slope_pb, y_intercept);
 }