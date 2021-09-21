/* 
 * Title: Operator prioriteter i logiske udtryk
 * Description: Denne opgaver giver dig træning i at anvende operator prioritering i logiske udtryk.
 * Assignment: 3.2
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-boolexp-slide-exercise-1.html
 * 
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void){

  int a = 1, b = 2, c = 3;
  double x = 1.0;

  int res1, res2, res3, res4;

  res1 = (a > b) && (c < x);
  res2 = (a < ! b) || (!(!a));
  res3 = (a + b) < ((!(c)) + c);
  res4 = ((a - x) || (b * c)) && (b / a);

  printf("res1 = %d, res2 = %d, res3 = %d,  res4 = %d \n", 
	 res1, res2, res3, res4);

  return 0;
}