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

void run_calculator();
void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *accumulator);
int isBinary(char operator);

int main(void) {

  run_calculator();

}

void run_calculator(void) {
  double accumulator, operand;
  char operator;

  while (1) {
    printf("Enter operator, and an optional operand: => ");
    scan_data(&operator, &operand);
    do_next_op(operator, operand, &accumulator);
    printf("Result so far is %lf\n", accumulator);
  }
}

void do_next_op(char operator, double operand, double *accumulator) {

  if (isBinary(operator)) {
    // + - * / ^
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
  } else {
    // #, %, !, q
    switch(operator) {
      case '#':
        if (*accumulator > 0)
          *accumulator = sqrt(*accumulator);
        break;
      case '%':
        *accumulator = -*accumulator;
        break;
      case '!':
        *accumulator = 1 / *accumulator;
        break;
      case 'q':
        printf("Final result is: %lf\n", *accumulator);
        exit(EXIT_SUCCESS);
    }
  }

}

void scan_data(char *operator, double *operand) {
  scanf(" %c", operator);
  switch(*operator) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      // if + - * / ^ we need an operand
      scanf(" %lf", operand);
  }
}

int isBinary(char operator) {
  if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^') { // using '' because that is for single characters
    return 1; // is binary - return true;
  } else {
    return 0; // not binary - return false;
  }
}