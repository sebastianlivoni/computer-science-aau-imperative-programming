/* 
 * Title: Sum af tal i interval som er dividerbare med samme tal
 * Description: In this problem, three positive integers m, n and k are given, where k is greater than 1. Write a program that adds all integers between m and n (both inclusive) where i k goes up.
 * Assignment: 4.2
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-control-more-iteration-while-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {

  unsigned int m = 5, n = 13, k = 3;

  int sum = 0;
  for (; m <= n; m++) {
    if (m % k == 0) {
      sum += m;
    }
  }
  printf("Sum: %d\n", sum);

}