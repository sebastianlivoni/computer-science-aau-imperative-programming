/*
 * Title: Array merger
 * Description: Merge contents of two sorted arrays of type double
 * Assignment: Page 472 exercise 11
 * Link to assignment: In the book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 27, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

void merge_arrays(double *merge_array, int *new_size, const double *arr1, int size_arr1, const double *arr2, int size_arr2);

int main(void) {
  double sorted_arr1[] = {-10.5, -1.8, 3.5, 4.0, 6.3, 7.2, 7.3, 8.5, 8.6, 8.7, 8.8, 10.0, 10.10, 20.0, 28.0, 42.0, 43.0};
  double sorted_arr2[] = {-50.0, -10.5, -1.8, 3.1, 3.6, 4.0, 6.3, 7.1, 7.2, 8.8, 9.9, 10.10, 20.0, 30.0, 40.0, 42.0, 43.0};

  /* Get size of array 1 & array 2 & the the sum of these */
  int size_of_arr1 = sizeof(sorted_arr1) / sizeof(double),
      size_of_arr2 = sizeof(sorted_arr2) / sizeof(double),
      max_arr_width = size_of_arr1 + size_of_arr2;

  double *merged_arr = malloc(max_arr_width * sizeof(double));
  int merged_arr_size;

  /* Merge the two array */
  merge_arrays(merged_arr, &merged_arr_size, sorted_arr1, size_of_arr1, sorted_arr2, size_of_arr2);

  for (int i = 0; i < merged_arr_size; i++) {
    printf("%.2f ", merged_arr[i]);
  }

  printf("\n");

  free(merged_arr);
}

void merge_arrays(double *merge_array, int *new_size, const double *arr1, const int size_arr1, const double *arr2, const int size_arr2) {

  int i = 0,
      count_arr1 = 0,
      count_arr2 = 0,
      sum_of_arrays = size_arr1 + size_arr2;

  while (i < sum_of_arrays) {
    if (count_arr1 < size_arr1 && count_arr2 < size_arr2) {
      if (arr1[count_arr1] < arr2[count_arr2]) {
        merge_array[i++] = arr1[count_arr1++];
      } else if (arr2[count_arr2] < arr1[count_arr1]) {
        merge_array[i++] = arr2[count_arr2++];
      } else {
        /* Either arr1 or arr2 - doesn't matter */
        merge_array[i++] = arr1[count_arr1++];
        count_arr2++;
        sum_of_arrays--;
      }
    } else if (count_arr1 < size_arr1) {
      merge_array[i++] = arr1[count_arr1++];
    } else if (count_arr2 < size_arr2) {
      merge_array[i++] = arr2[count_arr2++];
    }
  }

  *new_size = i;
  merge_array = realloc(merge_array, *new_size * sizeof(double));
}
