/*
 * Title: En simpel grep funktion
 * Description:
 * Assignment: Opgave 13.2
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/io-seqfile-op-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: December 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void print_lines_keyword(char *keyword, char *data_file_url);

int main(int argc, char *argv[]) {
  if (argc == 3) {
    print_lines_keyword(argv[1], argv[2]);
  } else {
    printf("Please type 2 arguments: <keyword> <data file url>");
    exit(EXIT_FAILURE);
  }

}

void print_lines_keyword(char *keyword, char *data_file_url) {
  FILE *fp;
  char line[100];
  int line_i;

  fp = fopen(data_file_url, "r");
  if (fp == NULL) {
    printf("Wrong file url!\n");
    exit(EXIT_FAILURE);
  }

  line_i = 1;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    if (strstr(line, keyword) != NULL) {
      printf("Line %d: %s", line_i, line);
    }
    line_i++;
  }

  printf("\n");

}
