/* 
 * Title: Write a program that calculates mileage reimbursement for a salesperson at a rate of $.35 per mile.
 * Description: ...
 * Assignment: Page 103 Programming Project 1
 * Link to assignment: Book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 13, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {
  double start, end;
  printf("Enter beginning odometer rading\n");
  scanf("%lf", &start);

  printf("Enter ending odometer rading\n");
  scanf("%lf", &end);

  printf("You traveled %.1f miles. At $0.35 per mile,\nyour reimbursement is $%.2f\n", end - start, (end - start) * 0.35);
}