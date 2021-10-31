/*
 * Title: Flertals navneord
 * Description: 
 * Assignment: Opgave 10.3 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/strings-extra-opgaver-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 29, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOUNS_SIZE 9

char * to_plural(const char *noun);

int main(void) {

  int i;

  char * nouns[NOUNS_SIZE] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};

  for (i = 0; i < NOUNS_SIZE; i++) {
    printf("Singular: %s\n", nouns[i]);
    printf("Pluralis: %s\n", to_plural(nouns[i]));
  }
}

char* to_plural(const char *noun) {
  char noun_copy[100];
  int length_noun = strlen(noun);

  strcpy(noun_copy, noun);

  if (noun_copy[length_noun - 1] == 'y') {
    noun_copy[length_noun - 1] = '\0';
    strcat(noun_copy, "ies");
  } else if (noun_copy[length_noun - 1] == 's') {
    strcat(noun_copy, "es");
  } else if (noun_copy[length_noun - 1] == 'h' && noun_copy[length_noun - 2] == 'c') {
    strcat(noun_copy, "es");
  } else if (noun_copy[length_noun - 1] == 's' && noun_copy[length_noun - 2] == 'e') {
    strcat(noun_copy, "es");
  } else {
    strcat(noun_copy, "s");
  }
  char* s = strcpy(malloc(100), noun_copy);

  return s;
}