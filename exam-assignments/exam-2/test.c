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

#define SIZE 15

enum numbers {one = 1, two, three, four, five, six};

typedef struct {
  int number;
  int amount;
} num_count;

void find_pairs(int *arr, num_count *pairs_arr);
int sort_pairs(const void *a, const void *b);

int main(void) {
  int i;
  int test[SIZE] = {2, 3, 3, 5, 3, 2, 3, 5, 2, 2, 5, 3, 6, 5, 6};

  num_count pairs_arr[6];
  find_pairs(test, pairs_arr);

  for (i = 0; i < 6; i++) {
    printf("%d: %d\n", pairs_arr[i].number, pairs_arr[i].amount);
  }

  

}

void find_pairs(int *arr, num_count *pairs_arr) {
  int i;

  for (i = 0; i < 6; i++) {
    pairs_arr[i].number = i + 1;
    pairs_arr[i].amount = 0;
  }
  for (i = 0; i < SIZE; i++) {
    pairs_arr[arr[i] - 1].amount += 1;
  }

  /*qsort(pairs_arr, 6, sizeof(pairs_arr[0]), sort_pairs);*/
}

int sort_pairs(const void *a, const void *b) {
  num_count *pair1 = (num_count *)a;
  num_count *pair2 = (num_count *)b;

  if (pair1->amount == pair2->amount)
    return 0;
  else if (pair1->amount < pair2->amount)
    return 1; 
  else
    return -1;
}
