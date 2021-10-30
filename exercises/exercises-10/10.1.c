/*
 * Title: Funktionen strrev
 * Description: Programmer funktionen strrev(char *str), som omvender tegnene i parameteren str.
 * Assignment: Opgave 10.1 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/strings-string-mutation-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 30, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *str);

int main(void) {

  char str[] = "streng";

  printf("%s = ", str);

  strrev(str);

  printf("%s\n", str);
  

}

void strrev(char *str) {
  int i;

  size_t len = strlen(str);

  char *str_copy = malloc(sizeof(char) * strlen(str));

  for (i = strlen(str) - 1; i >= 0; i--) {
    
    strncat(str_copy, &str[i], 1);
  }

  /* Overwriting str with str_copy */
  strcpy(str, str_copy);
}