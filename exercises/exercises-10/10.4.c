/*
 * Title: Opgave 10.4 
 * Description: Skriv et program med en funktion der finder og returnerer det længste fælles endelse (suffix) af to ord.
 * Assignment: Længste fælles endelse af to ord
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/strings-extra-opgaver-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 30, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "10.1.h"

void biggest_common_suffix(char *word1, char *word2, char *longest_suffix);

int main(void) {

  char longest_suffix[500], 
       word1[30] = "datalogi",
       word2[30] = "biologi";

  biggest_common_suffix(word1, word2, longest_suffix);

  printf("Biggest common suffix of %s & %s is %s\n", word1, word2, longest_suffix);

}


void biggest_common_suffix(char *word1, char *word2, char *longest_suffix) {
  int i = strlen(word1) - 1,
      j = strlen(word2) - 1;

  while (strcmp(&word1[i], &word2[j]) == 0) {
    strncat(longest_suffix, &word1[i], 1);
    i--; j--;
  }

  str_reverse(longest_suffix);

}