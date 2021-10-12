/* 
 * Write a program segment that computes 1 + 2 + 3 + ... + (n - 1) + n, where n is a data value.
 * Description: Follow the loop body with an if statement that compares this value to (n * (n + 1)) / 2 and displays a message that indicates whether the values are the same or different. What message do you think will be displayed?
 * Assignment: Book, Page 247, Programming exercise 1
 * 
 * Programmer: Sebastian Livoni
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h> 

int main(void) {
  int sum = 0;
  int n = 100;
  for (int i = 0; i <= n; i++) {
    sum += i;
  }
  sum += (n - 1) + n;

  printf("True or false: %s\n", (n * (n + 1)) / 2 == sum ? "true" : "false");
}
