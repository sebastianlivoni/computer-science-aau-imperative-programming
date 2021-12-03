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

#define INPUT_FILE_URL "./input.txt"
#define OUTPUT_FILE_URL "./output.txt"
#define MAX_NAME_LGT 50
#define MAX_LINE_LENGTH 80
#define PERSONS 11

struct person {
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
};
typedef struct person person;

person* sort_persons(person person);
int cmpfunc(const void * a, const void * b);

int main(void) {
  char line[MAX_LINE_LENGTH];
  int persons_count = 0;
  int i;

  person person_list[PERSONS];
  
  FILE* input_file;
  FILE* output_file;

  input_file = fopen(INPUT_FILE_URL, "r");
  if (input_file == NULL) {
    printf("Could not open the file %s!\n", INPUT_FILE_URL);
    exit(EXIT_FAILURE);
  }
  output_file = fopen(OUTPUT_FILE_URL, "w");
  if (output_file == NULL) {
    printf("Could not open the file %s!\n", OUTPUT_FILE_URL);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, MAX_LINE_LENGTH, input_file)) {
    sscanf(line, 
      "%s %[^,], %[A-Za-z A-Za-z] %d, %d %[A-Za-z].",
      person_list[persons_count].fornavn,
      person_list[persons_count].efternavn,
      person_list[persons_count].vejnavn,
      &person_list[persons_count].vejnummer,
      &person_list[persons_count].postnummer,
      person_list[persons_count].bynavn
    );
    person_list[persons_count].vejnavn[strlen(person_list[persons_count].vejnavn) - 1] = '\0'; /* remove last whitespace */

    persons_count += 1;
  }

  qsort(person_list, PERSONS, sizeof(person), cmpfunc);

  fclose(input_file);

  for (i = 0; i < PERSONS; i++) {
    fprintf(output_file, "%s: %s\n", person_list[i].bynavn, person_list[i].efternavn);
    printf("%s %s\n", person_list[i].efternavn, person_list[i].fornavn);
  }

  fclose(output_file);

  return EXIT_SUCCESS;

}

int cmpfunc(const void * a, const void * b) {
  int strcmp_retval;
  person* p1 = (person*)a;
  person* p2 = (person*)b;

  strcmp_retval = strcmp(p1->efternavn, p2->efternavn);

  if (strcmp_retval == 0)
    return strcmp(p1->fornavn, p2->fornavn);
  else
    return strcmp_retval;
}
