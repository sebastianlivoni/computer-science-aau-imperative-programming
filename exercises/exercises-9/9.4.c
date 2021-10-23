/*
 * Title: Bsort using qsort parameters
 * Description: my own version of qsort using bsort
 * Assignment: Opgave 9.4 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 23, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

void bubble_sort(int a[], int n);
void prn_array(char *s, const int a[], int n);
void swap(int *p, int *q);

void bsort(void *base, size_t n, size_t size, int(*compar)(const void *, const void *)) {

  int i, j;

  int* array = base;

  for (i = 0; i < n - 1; ++i)
  {
    for (j = n - 1; j > i; --j) {
      if (compar(array[j - 1], array[j]) > 0) {
        swap(&array[j - 1], &array[j]);
      }
    }
  }

}

int element_compare(const void *ap, const void *bp){
  int a = (int*) ap;
  int b = (int*) bp;

  return (a - b);
}

int main(void)
{
  int a[] = {7, 3, 66, 3, -5, 22, -77, 2};
  int n;

  n = sizeof(a) / sizeof(int); /* Notice how the size of a is found */
  prn_array("Before", a, n);

  bsort(a, n, sizeof(int), element_compare);
  prn_array("After", a, n);
  return 0;
}

void prn_array(char *s, const int a[], int n)
{
  int i;

  printf("\n    %s sorting:", s);
  for (i = 0; i < n; ++i)
    printf("%5d", a[i]);
  putchar('\n');
}

void swap(int *p, int *q)
{
  int tmp;

  tmp = *p;
  *p = *q;
  *q = tmp;
}