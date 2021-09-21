/* 
 * Title: En simplificeret udgave af Euclids algoritme
 * Description: Hvad sker der hvis vi dropper ombytningen af i og j, og således risikerer at small bliver større end large i while-løkken? Her er en sådan version af programmet:
 * Assignment: 4.5
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-control-more-exercises-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {
  int a, b, i, j, remainder;
 
  printf("Enter two non-negative integers: ");
  scanf("%d %d", &a, &b);

  i = a; j = b;  /* We don't know if i > j */  
  while (j > 0){
    remainder = i % j;
    i = j;
    j = remainder;
  }

  printf("GCD of %d and %d is %d\n\n", a, b, i);
  
  return 0;
}   

/* 
 * Answer:
 * Hvis vi prøver at skrive "5 10" ind, så kommer remainder til at blive 5 % 10 hvilket jo
 * ikke giver mening da 5 er mindre end 10 og dermed kan divisionen ikke lade sig gøre
 * 
 * English:
 * If we try to enter "5 10", then remainder will be 5% 10 which of course
 * does not make sense as 5 is less than 10, then the division can not be done sadly :(
*/