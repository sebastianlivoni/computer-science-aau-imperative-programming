/*
 * Title: A barcode scanner for Universal Product Codes (UPCs)
 * Assignment: Opgave 5 side 469
 * Link to assignment: Opgave i bogen
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define BARCODE_SIZE 12

void get_barcode(int barcode[]);
int check_barcode(int barcode[]);

int main(void) {

  /*int barcode_example[] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};*/

  int* barcode = (int *) malloc(BARCODE_SIZE * sizeof(int));

  get_barcode(barcode);
  if (check_barcode(barcode)) {
    printf("The barcode: ");
    for (int i = 0; i < BARCODE_SIZE; i++) {
      printf("%d", barcode[i]);
    }
    printf(" is validated!\n");
  } else {
    printf("Error in barcode!\n");
  }

}

void get_barcode(int barcode[]) {

  printf("Please input a barcode of %d digits => ", BARCODE_SIZE);
  for (int i = 0; i < BARCODE_SIZE; i++) {
    scanf(" %d", &barcode[i]);
  }

}

void print_barcode() {

}

int check_barcode(int barcode[]) {
  int sum_odd = 0, sum_even = 0, sum = 0, last_digit = 0;

  for (int i = 0; i < 11; i++) {
    if (i % 2 == 0) {
      //Actually odd
      sum_odd += barcode[i];
    } else {
      //Actually even
      sum_even += barcode[i];
      printf("%d ", barcode[i]);
    }
  }

  sum = sum_odd * 3 + sum_even;

  if (sum % 10 != 0) {
    last_digit = 10 - sum % 10;
  }

  return (last_digit == barcode[BARCODE_SIZE - 1]) ? 1 : 0;
}