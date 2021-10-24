/*
 * Title: Merge contents of two sorted arrays of type double
 * Description: 
 * Assignment: 
 * Link to assignment: 
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

void merge_arrays(double *merge_array, int *size, const double *arr1, int size_arr1, const double *arr2, int size_arr2);

int main(void)
{

  /*double sorted_arr1[] = {-5.0, 1.0, 3.0, 5.0, 55.0, 80.0};
  double sorted_arr2[] = {-7.0, 1.0, 4.0, 5.0, 57.0, 75.0, 80.0};*/

  double sorted_arr1[] = {-10.5, -1.8, 3.5, 4.0, 6.3, 7.2, 8.8, 10.10};
  double sorted_arr2[] = {-50.0, -10.5, -1.8, 3.1, 3.6, 4.0, 6.3, 7.1, 7.2, 8.8, 9.9, 10.10};

  /* Get size of array 1 & array 2 */
  int size_of_arr1 = sizeof(sorted_arr1) / sizeof(double),
      size_of_arr2 = sizeof(sorted_arr2) / sizeof(double),
      max_arr_width = size_of_arr1 + size_of_arr2;

  double *merged_arr = malloc(max_arr_width * sizeof(double));
  int merged_arr_size;

  /* Merge the two array */
  merge_arrays(merged_arr, &merged_arr_size, sorted_arr1, size_of_arr1, sorted_arr2, size_of_arr2);

  for (int i = 0; i < merged_arr_size; i++)
  {
    printf("%.2f ", merged_arr[i]);
  }

  printf("\n");

  free(merged_arr);
}

void merge_arrays(double *merge_array, int *size, const double *arr1, int size_arr1, const double *arr2, int size_arr2)
{

  double arr1_value,
      arr2_value;

  int merge_array_count = 0,
      count_arr1 = 0,
      count_arr2 = 0;

  if (arr1[0] < arr2[0])
  {
    merge_array[0] = arr1[0];
    merge_array[1] = arr2[0];
    merge_array_count = 2;
    count_arr1 = 1;
    count_arr2 = 1;
  }
  else if (arr1[0] > arr2[0])
  {
    merge_array[0] = arr2[0];
    merge_array[1] = arr1[0];
    merge_array_count = 2;
    count_arr2 = 1;
    count_arr1 = 1;
  }

  while (count_arr1 < size_arr1 && count_arr2 < size_arr2)
  {
    arr1_value = arr1[count_arr1];
    arr2_value = arr2[count_arr2];
    if (merge_array[merge_array_count - 1] == arr1_value)
    {
      count_arr1++;
      continue;
    }
    else if (merge_array[merge_array_count - 1] == arr2_value)
    {
      count_arr2++;
      continue;
    }
    if (arr1_value == arr2_value)
    {
      merge_array[merge_array_count++] = arr1_value;
      count_arr1++;
      count_arr2++;
    }
    else if (arr1_value < arr2_value)
    {
      merge_array[merge_array_count++] = arr1_value;
      count_arr1++;
    }
    else if (arr1_value > arr2_value)
    {
      merge_array[merge_array_count++] = arr2_value;
      count_arr2++;
    }
  }

  /* Copying the remaing of arr1 to the merge_array if there is still something left */
  if (count_arr1 < size_arr1)
  {
    for (int i = count_arr1; i < size_arr1; i++)
    {
      if (merge_array[merge_array_count] - 1 != arr1[i])
      {
        merge_array[merge_array_count] = arr1[i];
        merge_array_count++;
      }
    }
  }
  /* Copying the remaing of arr2 to the merge_array if there is still something left */
  else if (count_arr2 <= size_arr2)
  {
    for (int i = count_arr2; i < size_arr2; i++)
    {
      if (merge_array[merge_array_count] - 1 != arr2[i])
      {
        merge_array[merge_array_count] = arr2[i];
        merge_array_count++;
      }
    }
  }

  /* Output pointer to tell what size the array turned out to be */
  *size = merge_array_count;
}
