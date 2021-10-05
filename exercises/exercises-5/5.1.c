/*
 * Title: Trinvis forfinelse af solveQuadraticEquation
 * Description: 
 * Assignment: Opgave 5.1 
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/functions-anden-grads-ex-pars-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 5, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <math.h>

//Prototypes declaration
double calc_discriminant();
double first_root();
double second_root();

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){
  double discriminant, root1, root2;

  discriminant = calc_discriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots\n");
  else if (discriminant == 0){
    root1 = -b/(2*a);
    printf("One root: %f\n", root1);
  }
  else {
    root1 = first_root(a, b, discriminant);
    root2 = second_root(a, b, discriminant);
    printf("Two roots: %f and %f\n", root1, root2);
  }

}   

int main(void) {
  double a = 1.0, b = -8.0, c = 15.0,
         d = 2.0, e =  8.0, f =  2.0,
         g, h, i;

  /* First call - coefficents are values of variables */
  solveQuadraticEquation(a, b, c);  

  /* Second call - coefficents are values of expressions */
  solveQuadraticEquation(d - 1, -e, 7 * f + 1); 

  do {
    /* Third call - coefficents are entered by user outside solveQuadraticEquation */
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &g, &h, &i);
    if (g != 0 && h != 0 && i != 0) {
      solveQuadraticEquation(g, h, i); 
    }
  } while (g != 0 && h != 0 && i != 0);

  return 0;
}

double calc_discriminant(double a, double b, double c) {
  return b * b - 4 * a * c;
}

double first_root(double a, double b, double d) {
  return (-b + sqrt(d)) / ( 2 * a);
}

double second_root(double a, double b, double d) {
  return (-b - sqrt(d))/(2*a);
}