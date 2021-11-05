/*
 * Title: Palindromer
 * Description: 
 * Assignment: Opgave 11.2 
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/recursion-fib3-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome_iter(char *str);

int main(void) {
  printf("%d\n", is_palindrome_iter("regninger"));
}

int is_palindrome_iter(char *str) {
  int i = 0, j = strlen(str) - 1, is_palindrome = 1;
  while (is_palindrome > 0 && i >= 0 && j >= 0) {
    if (str[i] == str[j]) {
      i++; j--;
    } else {
      is_palindrome = 0;
    }
  }
  return is_palindrome;
}