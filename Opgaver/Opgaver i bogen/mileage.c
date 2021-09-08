#include <stdio.h>

int main(void) {
  double start, end;
  printf("Enter beginning odometer rading\n");
  scanf("%lf", &start);

  printf("Enter ending odometer rading\n");
  scanf("%lf", &end);

  printf("You traveled %.1f miles. At $0.35 per mile,\nyour reimbursement is $%.2f\n", end - start, (end - start) * 0.35);
}