/* 
 * Title: Switch statement to assign variable a specific value
 * Description: Write a switch statement that assigns to the variable lumens the expected brightness of an incandescent light bulb whose wattage has been stored in watts.
 * Assignment: Section 4.8 - Programming Assignment 1
 * Link to assignment: Book
 */

#include <stdio.h>

int main(void) {
  int lumens, watts;

  printf("Type lumens => ");
  scanf("%d", &watts);
  
  switch(watts) {
    case 15:
      lumens = 125;
      break;
    case 25:
      lumens = 215;
      break;
    case 45:
      lumens = 500;
      break;
    case 60:
      lumens = 880;
      break;
    case 75:
      lumens = 1000;
      break;
    case 100:
      lumens = 1675;
      break;
    default:
      lumens = -1;
  }

  printf("Lumens: %d\n", lumens);
}