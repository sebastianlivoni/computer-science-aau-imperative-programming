/* 
 * Title: Write a nested if statement for the decision diagrammed in the accompanying flowchart.
 * Description: Use a multiple-alternative if for intermediate decisions where possible.
 * Assignment: Exercise 3 from Section 4.7 from page 236
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-boolexp-slide-exercise-1.html
 * 
 * Programmers: Sebastian Livoni, Simon Halkjær Tander, Richard Avenia, Lasse Fjellanger, Jacob Kyed Andreassen
 * Date completed: September 15, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ph = 10;

  if (ph <= 2)
     printf("Very acidic");  
  else if (ph < 7) 
     printf("Acidic");       
  else if (ph == 7)
     printf("Neutral");      
  else if (ph < 12)
     printf("Alkaline");     
  else 
     printf("Very alkaline");

  printf("\n");

  return ((((((((((0))))))))));
}