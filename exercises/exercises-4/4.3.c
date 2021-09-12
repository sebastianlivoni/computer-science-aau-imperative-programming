/* 
 * Title: Endnu en sum af tal i et interval
 * Description:  Programmet skal addere alle tal i intervallet fra n til 2 * n hvis n er ikke negativ. Hvis n er negativ, skal programmet addere tallene fra 2 * n til n.
 * Assignment: 4.3
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-control-more-iteration-while-slide-exercise-3.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 12, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {

  int n, sum;

  printf("Write an integer => ");
  scanf("%d", &n);

  //for loops
  if (n > 0) {
    for (int i = n; i <= 2 * n; i++) {
      sum += i;
    }
  } else {
    for (int i = n * 2; i < 0; i++) {
      sum += i;
    }
  }

  printf("Sum for loop: %d\n", sum);

  sum = 0;

  //while loops
  if (n > 0) {
    int i = n;
    while (i <= 2 * n) {
      sum += i;
      i++;
    }
  } else {
    int i = n * 2;
    while (i <= 0) {
      sum += i;
      i++;
    }
  }

  printf("Sum while loop: %d\n", sum);

}