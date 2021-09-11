#include <stdio.h>
#include <math.h>
#define DELTA 1

int main(void) {
  double r, x, y;

  printf("Skriv et punkt (x, y) => ");
  int check = scanf("(%lf, %lf)", &x, &y);

  if (check != 2) {
    printf("Brug format (x, y)...\n");
    return 1;
  }

  printf("Skriv radius => ");
  scanf("%lf", &r);

  (pow(x - 1, 2) + pow(y - 4, 2) <= pow(r, 2)) ? (pow(x - 1, 2) + pow(y - 4, 2) == pow(r, 2)) ? printf("På periferien") : printf("Inden i\n") : printf("Uden for\n");

}