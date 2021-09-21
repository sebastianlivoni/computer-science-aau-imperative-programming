/* 
 * Title: Forklaring af et program med while løkke og udtryk med assignments
 * Description: Forklar hvad der udskrives af følgende program. Hvor mange gange udføres kroppen af while-løkken? Og hvilken række af tal udskriver programmet (helt præcist)? Forudsig først resultatet, og kør dernæst programmet.
 * Assignment: 4.1
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-control-more-iteration-while-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */


/* 
 * Forklar hvad der udskrives af følgende program. Hvor mange gange udføres kroppen af while-løkken? 
 * Og hvilken række af tal udskriver programmet (helt præcist)? Forudsig først resultatet, og kør dernæst programmet.
 */

/* 
 * Forudsigelse:
 * Der udskrives 2^10 hvilket er 1024
 * Kroppen af white-løkken udføres 10 gange da ++i bliver talt inden og dermed starter den ved i=1 og slutter ved i=10
 * Rækkefølge: 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
 */

#include <stdio.h>

int main(void){
   int i = 0, power = 1;

   while (++i <= 10)
      printf("%5d", power *= 2);
   printf("\n");

   return 0;
}

// * Hvad sker der hvis ++i erstattes af i++?
// * Svar: Så bliver det talt 11 gange og så bliver det 2048


// * Det er også interessant at omskrive programmet, så det bruger en for-løkke i stedet for en while-løkke. Prøv dette!

/* Omskrevet til et for-loop
int main(void){
  int i = 0, power = 1;

  for (i = 1; i <= 10; i++) {
    printf("%5d", power *= 2);
  }
  printf("\n");

  return 0;
}
*/