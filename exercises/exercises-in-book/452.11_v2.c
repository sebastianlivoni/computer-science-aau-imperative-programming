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

double* merge_arrays(const double *arr1, const int size_arr1, const double *arr2, const int size_arr2, int *new_size);
void print_array(double* array, int size);

int main(void) {
  double *merged_arr,
         sorted_arr1[] = {-10.5, -1.8, 3.5, 4.0, 6.3, 7.2, 7.3, 8.5, 8.6, 8.7, 8.8, 10.0, 10.10, 20.0, 28.0, 42.0, 43.0},
         sorted_arr2[] = {-50.0, -10.5, -1.8, 3.1, 3.6, 4.0, 6.3, 7.1, 7.2, 8.8, 9.9, 10.10, 20.0, 30.0, 40.0, 42.0, 43.0};

  /* Get size of array 1 & array 2 & the the sum of these */
  int merged_arr_size,
      size_of_arr1 = sizeof(sorted_arr1) / sizeof(double),
      size_of_arr2 = sizeof(sorted_arr2) / sizeof(double);

  /* Merge the two array */
  merged_arr = merge_arrays(sorted_arr1, size_of_arr1, sorted_arr2, size_of_arr2, &merged_arr_size);

  /* Print our array */
  print_array(merged_arr, merged_arr_size);

  /* Clean up and other stuff */
  free(merged_arr);
  return EXIT_SUCCESS;
}

double* merge_arrays(const double* arr1, const int size_arr1, const double* arr2, const int size_arr2, int* new_size) {
  /* Allocating memory for the new merged array */
  double* merged_arr = malloc((size_arr1 + size_arr2)* sizeof(double));

  int i = 0,
      count_arr1 = 0,
      count_arr2 = 0,
      size_of_arrays = size_arr1 + size_arr2;

  while (i < size_of_arrays) {
    if (count_arr1 < size_arr1 && count_arr2 < size_arr2) {
      /* While both arrays still have elements */
      if (arr1[count_arr1] < arr2[count_arr2]) {
        merged_arr[i++] = arr1[count_arr1++];
      } else if (arr2[count_arr2] < arr1[count_arr1]) {
        merged_arr[i++] = arr2[count_arr2++];
      } else {
        /* Arr1 & arr2 is equal */
        merged_arr[i++] = arr1[count_arr1++];
        count_arr2++;       /* We want to skip this value and count to next one */
        size_of_arrays--;   /* Because both values are the same, the size of the array is going to be 1 value smaller */
      }
    } else if (count_arr1 < size_arr1) {
      /* Only arr1 left - adding the values left of array 1 to the merged array */
      merged_arr[i++] = arr1[count_arr1++];
    } else if (count_arr2 < size_arr2) {
      /* Only arr2 left - adding the values left of array 2 to the merged array */
      merged_arr[i++] = arr2[count_arr2++];
    }
  }

  *new_size = i;
  /* Reallocate memory */
  return (double*) realloc(merged_arr, *new_size * sizeof(double));
}

void print_array(double* array, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%.2f ", array[i]);
  }
  printf("\n");
}
