#include <stdio.h>
#include <math.h>

#define G 9.8
#define EFFICIENCY 0.9

int main(void) {
  int h, m;
  double w;

  printf("Type the height of the dam => ");
  scanf("%d", &h);

  printf("Type the mass => ");
  scanf("%d", &m);

  

  //convert cubic meter to mass
  m = m * 1000;

  w = m * G * h * EFFICIENCY;

  printf("%.2f\n", w / 1000000);

}