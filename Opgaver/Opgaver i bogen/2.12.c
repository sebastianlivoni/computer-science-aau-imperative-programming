#include <stdio.h>

int main(void) {
  double toSpeed, distance;
  printf("Take-off speed in km/hr => ");
  scanf("%lf", &toSpeed);
  printf("Distance in meters => ");
  scanf("%lf", &distance);

  toSpeed = toSpeed * 10 / 36; //en anden opgave siger at dette ikke skal være med

  double t = (2 * distance) / toSpeed;
  double a = toSpeed / t;

  printf("Acceleration: %f, Time: %f\n", a, t);

}