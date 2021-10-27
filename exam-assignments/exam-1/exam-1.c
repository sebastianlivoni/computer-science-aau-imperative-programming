/*
 * Title: En regnemaskine på kommandolinjen.
 * Assignment: Eksamensopgave 1
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-21/eksamensopgaver-e21/Funktioner-parametre/opgave-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Email: seblar21@student.aau.dk
 * Group P1: B205
 * Field of study: Computer Science (Datalogi)
 * Date completed: October 25, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
double run_calculator(void);
void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *accumulator);
int is_binary(char operator);
int is_unary(char operator);
void show_help_menu(void);

int main(void) {

  printf("Final result is: %lf\n", run_calculator());

  return EXIT_SUCCESS;
}

double run_calculator(void) {
  double accumulator, operand;
  char operator;

  system("clear"); /* Det skal jo se godt ud */

  printf("\nWelcome to Seb's Calculating Machine.\n\n");

  printf("To calculate, type in the operator and operand in using this format: <operator> <operand>\n\n");
  printf("Example: + 5\n");
  printf("^ The above will add 5 to the accumulator.\n\n");
  printf("The accumulator will start with a value of 0.\n\n");
  printf("If you at any time need a list with the valid operators, just type 'h'.\n");
  printf("When you want to quit, type 'q' to show the final result.\n");
  printf("Otherwise enjoy :)\n\n");

  do {
    printf("Enter operator, and an optional operand => ");
    scan_data(&operator, &operand);
    do_next_op(operator, operand, &accumulator);
    if (operator != 'q') {
     printf("Result so far is %lf\n", accumulator); 
    }
  } while (operator != 'q');

  return accumulator;
}

void scan_data(char *operator, double *operand) {
  scanf(" %c", operator);
  
  switch(*operator) {
    case 'h':
      show_help_menu();
      break;
    case '+': case '-': case '*': case '/': case '^':
      /* if operator is + - * / ^ we need an operand */
      scanf(" %lf", operand);
      break;
  }
}

void do_next_op(char operator, double operand, double *accumulator) {

  if (is_binary(operator)) {
    /* + - * / ^ */
    switch(operator) {
      case '+':
        *accumulator += operand;
        break;
      case '-':
        *accumulator -= operand;
        break;
      case '*':
        *accumulator *= operand;
        break;
      case '/':
        if (operand != 0)
          *accumulator /= operand;
        break;
      case '^':
        *accumulator = pow(*accumulator, operand);
        break;
    }
  } else if (is_unary(operator)) {
    /* #, %, !, q */
    switch(operator) {
      case '#':
        if (*accumulator > 0)
          *accumulator = sqrt(*accumulator);
        break;
      case '%':
        *accumulator = -*accumulator;
        break;
      case '!':
        if (*accumulator > 0)
          *accumulator = 1 / *accumulator;
    }
  } else {
    printf("An error occured and something went completely wrong! Goodbye.\n");
    exit(EXIT_FAILURE);
  }
}

int is_binary(char operator) {
  switch (operator) {
    case '+': case '-': case '*': case '/': case '^':
      return 1; /* is valid binary */
    default:
      return 0; /* not valid binary operator => instead unary */
  }
}
int is_unary(char operator) {
  switch (operator) {
    case '#': case '%': case '!': case 'h': case 'q':
      return 1; /* is valid unary */
    default:
      return 0; /* not valid unary operator => instead unary */
  }
}

void show_help_menu(void) {
  printf("\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |          |            Valid binary operators                    |\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" | Operator |                    Description                       |\n");
  printf(" |    +     |  addition of the accumulator with the operand        |\n");
  printf(" |    -     |  subtraction of the accumulator with the operand     |\n");
  printf(" |    *     |  multiplication of the accumulator with the operand  |\n");
  printf(" |    /     |  division of the accumulator with the operand        |\n");
  printf(" |    ^     |  power of the accumulator with the operand           |\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |          |             Valid unary operators                    |\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |    #     |  the square root of the accumulator                  |\n");
  printf(" |    %%     |  reverse the number sign of the accumulator          |\n");
  printf(" |    !     |  divide 1 with the accumulator                       |\n");
  printf(" |    q     |  exit the calculator with the end result             |\n");
  printf(" +----------+------------------------------------------------------+\n\n");
}
