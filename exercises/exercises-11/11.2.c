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

char* is_palindrome(int (f)(char*), char *sequence);
int is_palindrome_iter(char *str);
int is_palindrome_rec(char *str);
int do_palindrome_rec(char *str);

int main(void) {
  char sequence[1000];
  int run = 1;
  
  printf("\nWelcome to Seb's Blazing Insanely Fast and Meticulous Palindrome Checker!\nType 'quit' to quit.\n\n");

  while (run) {
    printf("What sequence do you want to check palindrome on? => ");
    scanf(" %s", sequence);

    if (strcmp(sequence, "quit") == 0) {
      run = 0;
      printf("Goodbye!\n");
    } else {
      printf(
        "\nIs '%s' a palindrome?\n\n"
        "%s, using iterative method.\n"
        "%s, using recursive method.\n\n",
        sequence,
        is_palindrome(&is_palindrome_iter, sequence),
        is_palindrome(&is_palindrome_rec, sequence)
      );
    }
  }
}

char* is_palindrome(int (f)(char*), char *sequence) {
  return (f(sequence) == 1) ? "Yes of course" : "No absolutely not";
}

int is_palindrome_iter(char *str) {
  int i = 0,
      j = strlen(str) - 1;
  
  while (is_palindrome > 0 && j >= 0) {
    if (str[i] == str[j]) {
      i++; j--;
    } else {
      return 0; /* Nope, not a palindrome */
    }
  }
  return 1; /* Yes, it is palindrome */
}

int is_palindrome_rec(char *str) {
  /* Need to copy to a new string */
  char str_copy[strlen(str)];
  strcpy(str_copy, str);
  return do_palindrome_rec(str_copy);
}

int do_palindrome_rec(char *str) {
  int str_len = strlen(str);
  if (str_len == 0) {
    return 1; /* Yes, it is palindrome */
  } else if (str[0] != str[str_len - 1]) {
    return 0; /* Nope, not a palindrome */
  } else {
    /* Use recursive function from str[1] to str[length - 1] */
    str[str_len - 1] = '\0';
    return do_palindrome_rec(&str[1]);
  }
}

/* First Try - But in two functions */

/*
int is_palindrome_rec(char *str) {
  return palindrome_rec(str, 0, strlen(str) - 1);
}

int palindrome_rec(char *str, int i, int j) {
  if (j == 0)
    return 1;
  else if (str[i] != str[j])
    return 0;
  else 
    return palindrome_rec(str, ++i, --j);
}
*/