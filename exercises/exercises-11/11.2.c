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
int is_palindrome_rec(char *str);

int main(void) {
  char text_to_check[] = "regninger";

  printf("Is palindrome? %s\n", (is_palindrome_iter(text_to_check) == 1) ? "yes" : "no");
  printf("Is palindrome? %s\n", (is_palindrome_rec(text_to_check) == 1) ? "yes" : "no");
}

int is_palindrome_iter(char *str) {
  int i = 0, j = strlen(str) - 1, is_palindrome = 1;
  while (is_palindrome > 0 && j >= 0) {
    if (str[i] == str[j]) {
      i++; j--;
    } else {
      is_palindrome = 0;
    }
  }
  return is_palindrome;
}

int check_palindrome(char *str, int i, int j) {
  if (j == 0) 
    return 1;
  else if (str[i] != str[j])
    return 0;
  else 
    return check_palindrome(str, ++i, --j);
}

int is_palindrome_rec(char *str) {
  return check_palindrome(str, 0, strlen(str) - 1);
}