/* 
 * Title: Write nests of loops that cause the following output to be displayed:
 * 0 
 * 0 1 
 * 0 1 2 
 * 0 1 2 3 
 * 0 1 2 3 4 
 * 0 1 2 3 4 5 
 * 0 1 2 3 4 
 * 0 1 2 3 
 * 0 1 2 
 * 0 1 
 * 0
 * Assignment: Page 272 Programming Project 2
 * Link to assignment: Book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#define COUNT_TO 5

int main(void) {
  int count_to_next = 1;
  while (count_to_next <= COUNT_TO + 1) {
    for (int i = 0; i < count_to_next; i++) {
      printf("%d ", i);
    }
    count_to_next += 1;
    printf("\n");
  }

  count_to_next = 4;
  while (count_to_next > 0 - 1) {
    for (int i = 0; i < count_to_next + 1; i++) {
      printf("%d ", i);
    }
    count_to_next -= 1;
    printf("\n");
  }
}