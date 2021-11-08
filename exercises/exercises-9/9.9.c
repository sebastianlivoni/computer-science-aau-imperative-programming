/*
 * Title: Associative arrays.
 * Description: 
 * Assignment: Opgave 9.9 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-7.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 6, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSON 10;

int h(char *name) {
  int name_len = strlen(name);
  int sum = name[0] + name[name_len / 2] + name[name_len - 1];
  return sum % MAX_PERSON;
}

int main(void) {

  int alder_af_navn[] = {10, 20, 30};
 
  int alder = h("Peter");

  printf("Index: %d\n", alder);

}