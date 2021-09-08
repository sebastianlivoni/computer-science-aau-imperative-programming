/* 
 * Title: If else statement to assign variable a specific value
 * Description: Write a nested if statement equivalent to the switch statement described in the first programming exercise.
 * Assignment: Section 4.8 - Programming Assignment 2
 * Link to assignment: Book
 */

#include <stdio.h>

int main(void) {
  int lumens, watts;

  printf("Type lumens => ");
  scanf("%d", &watts);
  
  if (watts == 15) {
    lumens = 125;
  } else if (watts == 25) {
    lumens = 215;
  } else if (watts == 40) {
    lumens = 500;
  } else if (watts == 60) {
    lumens = 880;
  } else if (watts == 75) {
    lumens = 1000;
  } else if (watts == 100) {
    lumens = 1675;
  } else {
    lumens = -1;
  }

  printf("Lumens: %d\n", lumens);
}