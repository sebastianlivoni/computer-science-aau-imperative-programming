/*
 * Title: En funktion som kalder en anden funktion flere gange
 * Description: Recursion :)
 * Assignment: Opgave 6.4 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-functions-ptr-fn-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen & Lasse Fjellager
 * Date completed: October 20, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

typedef double (mathFunc) (double);

double half(double x){
  return x / 2;
}

double multi_apply(mathFunc f, int n, double s) {
  return n == 0 ? s : multi_apply(f, n - 1, f(s));
}

/*double multi_apply(double f (double), int n, double s) {
  return n == 0 ? s : multi_apply(f, n - 1, f(s));
}*/


int main(void) {
  printf("Value: %lf\n", multi_apply(half, 2, 16.0));
}