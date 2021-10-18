/*
 * Title: 
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
#include <math.h>

// Prototypes
void exchange_in_notes(int dollars_left, int *hundreds, int *fifties, int *twenties, int *tens);

int main(void) {

  int dollars, hundreds, fifties, twenties, tens;

  do {
    printf("ATM: Please input an amount divisible by 10 => ");
    scanf(" %d" , &dollars);
  } while (dollars % 10 != 0);

  exchange_in_notes(dollars, &hundreds, &fifties, &twenties, &tens);

  printf("Input: %d = Hundreds: %d, fifties: %d, twenties: %d & tens: %d\n", dollars, hundreds, fifties, twenties, tens);
}

void exchange_in_notes(int dollars_left, int *hundreds, int *fifties, int *twenties, int *tens) {

  *hundreds = floor(dollars_left / 100);
  dollars_left -= *hundreds * 100;

  *fifties = floor(dollars_left / 50);
  dollars_left -= *fifties * 50;

  *twenties = floor(dollars_left / 20);
  dollars_left -= *twenties * 20;

  *tens = floor(dollars_left / 10);

}