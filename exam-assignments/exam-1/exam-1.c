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

#define IS_VALID  1
#define NOT_VALID 0

/* Binary operators */
#define ADDITION_OPERATOR '+'
#define SUBTRACT_OPERATOR '-'
#define MULTIPLY_OPERATOR '*'
#define DIVIDE_OPERATOR   '/'
#define POWER_OPERATOR    '^'

/* Unary operators */
#define SQAURE_ROOT_OPERATOR '#'
#define REVERSE_OPERATOR     '%'
#define DIVIDE_ONE_OPERATOR  '!'
#define HELP_MENU_OPERATOR   'h'
#define EXIT_OPERATOR        'q'

/* Function prototypes */
double run_calculator(void);
void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *accumulator);
int is_binary(char operator);
int is_unary(char operator);
void show_help_menu(void);

int main(void) {

  double final_result = run_calculator();

  printf("Final result is: \033[1;37m%.6lf\033[0;37m\n", final_result);

  return EXIT_SUCCESS;
}

double run_calculator(void) {
  double accumulator, operand;
  char operator;

  system("clear"); /* Det skal jo se godt ud */

  printf("\nWelcome to Seb's Calculating Machine.\n\n");

  printf("To calculate, type in the operator and operand in using this format: \033[1;37m<operator> <operand>\033[0;37m\n\n");
  printf("Example: \033[1;37m+ 5\033[0;37m\n");
  printf("^ The above will add 5 to the accumulator.\n\n");
  printf("The accumulator will start with a value of 0.\n\n");
  printf("If you at any time need a list with the valid operators, just type \033[1;37m'h'\033[0;37m.\n");
  printf("When you want to quit, type \033[1;37m'q'\033[0;37m to show the final result.\n");
  printf("Otherwise enjoy :)\n\n");

  do {
    printf("Enter operator, and an optional operand => ");
    scan_data(&operator, &operand);
    do_next_op(operator, operand, &accumulator);
    if (operator != 'q') {
     printf("Result so far is \033[1;37m%.6lf\033[0;37m.\n", accumulator); 
    }
  } while (operator != EXIT_OPERATOR);

  return accumulator;
}

void scan_data(char *operator, double *operand) {
  scanf(" %c", operator);
  
  switch(*operator) {
    case HELP_MENU_OPERATOR:
      show_help_menu();
      break;
    case ADDITION_OPERATOR: case SUBTRACT_OPERATOR: case MULTIPLY_OPERATOR: case DIVIDE_OPERATOR: case POWER_OPERATOR:
      /* if operator is + - * / ^ we need an operand and must scanf again */
      scanf(" %lf", operand);
      break;
  }
}

void do_next_op(char operator, double operand, double *accumulator) {

  if (is_binary(operator) == IS_VALID) {
    /* + - * / ^ */
    switch(operator) {
      case ADDITION_OPERATOR:
        *accumulator += operand;
        break;
      case SUBTRACT_OPERATOR:
        *accumulator -= operand;
        break;
      case MULTIPLY_OPERATOR:
        *accumulator *= operand;
        break;
      case DIVIDE_OPERATOR:
        if (operand != 0)
          *accumulator /= operand;
        break;
      case POWER_OPERATOR:
        *accumulator = pow(*accumulator, operand);
        break;
    }
  } else if (is_unary(operator) == IS_VALID) {
    /* #, %, ! */
    switch(operator) {
      case SQAURE_ROOT_OPERATOR:
        if (*accumulator > 0)
          *accumulator = sqrt(*accumulator);
        break;
      case REVERSE_OPERATOR:
        *accumulator = -*accumulator;
        break;
      case DIVIDE_ONE_OPERATOR:
        if (*accumulator > 0)
          *accumulator = 1 / *accumulator;
    }
  } else {
    printf("An error occured and maybe you typed an invalid operator! Goodbye.\n");
    exit(EXIT_FAILURE);
  }
}

int is_binary(char operator) {
  switch (operator) {
    case ADDITION_OPERATOR: case SUBTRACT_OPERATOR: case MULTIPLY_OPERATOR: case DIVIDE_OPERATOR: case POWER_OPERATOR:
      return IS_VALID; 
    default:
      return NOT_VALID;
  }
}
int is_unary(char operator) {
  switch (operator) {
    case SQAURE_ROOT_OPERATOR: case REVERSE_OPERATOR: case DIVIDE_ONE_OPERATOR: case HELP_MENU_OPERATOR: case EXIT_OPERATOR:
      return IS_VALID; 
    default:
      return NOT_VALID;
  }
}

void show_help_menu(void) {
  printf("\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |          |            Valid binary operators                    |\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" | Operator |                    Description                       |\n");
  printf(" |    %c     |  addition of the accumulator with the operand        |\n", ADDITION_OPERATOR);
  printf(" |    %c     |  subtraction of the accumulator with the operand     |\n", SUBTRACT_OPERATOR);
  printf(" |    %c     |  multiplication of the accumulator with the operand  |\n", MULTIPLY_OPERATOR);
  printf(" |    %c     |  division of the accumulator with the operand        |\n", DIVIDE_OPERATOR);
  printf(" |    %c     |  power of the accumulator with the operand           |\n", POWER_OPERATOR);
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |          |             Valid unary operators                    |\n");
  printf(" +----------+------------------------------------------------------+\n");
  printf(" |    %c     |  the square root of the accumulator                  |\n", SQAURE_ROOT_OPERATOR);
  printf(" |    %c     |  reverse the sign of the accumulator                 |\n", REVERSE_OPERATOR);
  printf(" |    %c     |  divide 1 with the accumulator                       |\n", DIVIDE_ONE_OPERATOR);
  printf(" |    %c     |  exit the calculator with the end result             |\n", EXIT_OPERATOR);
  printf(" +----------+------------------------------------------------------+\n\n");

  /* C90 compoilers are required to support a maximum of 509 - there a lot of printf's */
}
