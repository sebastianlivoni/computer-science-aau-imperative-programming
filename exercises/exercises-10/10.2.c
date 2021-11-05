/*
 * Title: Din egen udgave af funktionen strcmp
 * Description: 
 * Assignment: Opgave 10.2 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/strings-strcmp-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcmp_rec(char *a, char *b);

int main(void) {

  printf("Stringcompare: %d\n", strcmp_rec("hej", "hej"));

}

int strcmp_rec(char *a, char *b) {
  if (strlen(a) > 0 && strlen(b) > 0) {
    if (a[0] > b[0]) {
      return -1;
    } else if (a[0] < b[0]) {
      return 1;
    } else {
      return strcmp_rec(&a[1], &b[1]);
    }
  } else {
    return 0;
  }
}