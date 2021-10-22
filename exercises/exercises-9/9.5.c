/*
 * Title: Dynamisk allokering og qsort
 * Description: Use malloc to allocate space for 100 doubles.
 * Assignment: Opgave 9.5 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-3.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int element_compare(const void *ip1, const void *ip2);

int main(void) {

  double *tbl = (double*)malloc(MAX * sizeof(double));

  if (tbl == NULL) {
    printf("Cannot allocate memory. Bye\n");
    exit(EXIT_FAILURE);
  } else {
    printf("Memory successfully allocated with mailloc.\n");

    srand(time(NULL));

    int i;

    for (i = 0; i < MAX; ++i) {
      tbl[i] = (double)(rand() % 100) + 1;
    }
  }

  qsort(tbl, MAX, sizeof(double), element_compare);

  int i;
  for (i = 0; i < MAX; i++) {
    printf("%lf\n", tbl[i]);
  }

  free(tbl);

}

int element_compare(const void *ip1, const void *ip2){
  int result;
  double *ipi1 = (double *) ip1, 
         *ipi2 = (double *) ip2;

  if (*ipi1 < *ipi2)
    result = -1;
  else if (*ipi1 > *ipi2)
    result = 1;
  else
    result = 0;

  return result;
}