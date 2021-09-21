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

  //Count up
  int count_next = 1;
  while (count_next <= COUNT_TO + 1) {
    for (int i = 0; i < count_next; i++) {
      printf("%d ", i);
    }
    count_next += 1;
    printf("\n");
  }

  //Count down
  count_next = COUNT_TO;
  while (count_next > 0) {
    for (int i = 0; i < count_next; i++) {
      printf("%d ", i);
    }
    count_next -= 1;
    printf("\n");
  }

}