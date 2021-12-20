/*
 * Title: 
 * Description: 
 * Assignment: 
 * Link to assignment: 
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 14
#define DICES_EYES 6

typedef struct {
  int value;
  int amount_of_value;
} pair;

void sort_pairs(const int *arr, pair *pairs_arr);
int compare(const void * a, const void * b);

int main(void) {
  int arr[ARRAY_SIZE] = {1, 2, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 6, 6}, i;
  pair pairs_arr[ARRAY_SIZE];

  sort_pairs(arr, pairs_arr);

  qsort(pairs_arr, 6, sizeof(pair), compare);

  for (i = 0; i < DICES_EYES; i++) {
    if (pairs_arr[i].amount_of_value >= 2) {
      /*printf("One Pair = ");*/
    }
    printf("%d: %d\n", pairs_arr[i].value, pairs_arr[i].amount_of_value);
  }


}

void sort_pairs(const int *arr, pair *sorted_array) {
  int i, j, count;

  for (i = 1; i <= 6; i++) {
    sorted_array[i - 1].value = i;
    count = 0;
    for (j = 0; j < ARRAY_SIZE; j++)
      if (arr[j] == i)
        count++;
    sorted_array[i - 1].amount_of_value = count;
  }
}

int compare(const void * a, const void * b) {
  pair *pairA = (pair *)a;
  pair *pairB = (pair *)b;

  if (pairB->amount_of_value - pairA->amount_of_value == 0) {
    return pairB->value - pairA->value;
  } else {
    return pairB->amount_of_value - pairA->amount_of_value;
  }
}
