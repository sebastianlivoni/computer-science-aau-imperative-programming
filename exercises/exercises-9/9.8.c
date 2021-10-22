/*
 * Title: Multiple terningekast
 * Description: 
 * Assignment: Opgave 9.8
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-6.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 22, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define DIE_MAX_EYES 6

void roll_multiple_dies_pointer(int n, int arr[]);
int* roll_multiple_dies_return(int n);
int roll_die(void);

int main(void) {

  srand(time(NULL));  // Seeding the random number generator.
                      // Do this only once!

  int n = 10;

  /* Aflevering gennem pointer */

  int* tbl = malloc(n * sizeof(int));

  if (tbl == NULL) {
    printf("Cannot allocate memory. Bye\n");
    exit(EXIT_FAILURE);
  }

  roll_multiple_dies_pointer(n, tbl);

  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", i, tbl[i]);
  }

  free(tbl);

  /* Aflevering gennem return */

  int *new_tbl;
  new_tbl = roll_multiple_dies_return(n);

  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", i, new_tbl[i]);
  }

  free(new_tbl);

  return 0;
}

void roll_multiple_dies_pointer(int count, int *arr) {
  for (int i = 0; i < count; i++) {
    arr[i] = (rand() % DIE_MAX_EYES) + 1;
  }
}

int* roll_multiple_dies_return(int n) {
  int* arr = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = (rand() % DIE_MAX_EYES) + 1;
  }

  return arr;
}

int roll_die(void) {
  return (rand() % DIE_MAX_EYES) + 1;
}

/* Jeg foretrækker at returnere gennem en pointer */