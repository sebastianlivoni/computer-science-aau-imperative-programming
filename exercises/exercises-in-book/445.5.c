/*
 * Title: 
 * Description: Write a C program segment to display the index of the smallest and the largest numbers in an array x of 20 integers. Assume array x already has values assigned to each element.
 * Assignment: Review Question 5
 * Link to assignment: In the book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void display_min_and_max(int x[], int size);

int main(void) {

  int x[SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11};

  display_min_and_max(x, SIZE);

}

void display_min_and_max(int x[], int size) {
  int min, max, min_index, max_index;

  for (int i = 0; i < size; i++) {
    if (x[i] > max) {
      max = x[i];
      max_index = i;
    }
    if (x[i] < min) {
      min = x[i];
      min_index = i;
    }
  }

  printf("Max is at index %d - min is at index %d\n", max_index, min_index);
}