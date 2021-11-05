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
#include <string.h>

int is_palindrome(char word[]);

int main(void) {
  char word[15];

  printf("Please write a word to check for palindrome => ");
  scanf(" %s", word);

  if (is_palindrome(word)) {
    printf("%s is a palindrome! Nice\n", word);
  } else {
    printf("%s is not palindrome! Aww\n", word);
  }
}

int is_palindrome_rec(char word[], int size) {
  
  printf("%d\n", size);
  return 1;
}

int is_palindrome(char word[]) {
  return is_palindrome_rec(word, strlen(word));
}