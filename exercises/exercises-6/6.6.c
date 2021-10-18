/*
 * Title: En valutaomregner
 * Description: Skriv et C program som konverterer valuta i dollars til euro, kroner, rubler og yen. I kan antage en én dollar er 0.89 euros, 6.66 kroner, 66.43 rubler og 119.9 yen.
 * Assignment: Opgave 6.6
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/more-functions-ekstr-opg-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: October 18, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

#define DOLLAR_IN_EURO   0.89
#define DOLLAR_IN_KRONE  6.66
#define DOLLAR_IN_RUBEL 66.43
#define DOLLAR_IN_YEN   119.9

void convert_from_dollars(double dollars, double *euro, double *kroner, double *rubles, double *yen);

int main(void) {
  double euro, kroner, rubler, yen;

  for (double dollars = 1; dollars <= 100; dollars++) {
    convert_from_dollars(dollars, &euro, &kroner, &rubler, &yen);

    printf("%.2lf dollars = %.2lf euro, %.2lf kroner, %.2lf rubler, %.2lf yen\n", dollars, euro, kroner, rubler, yen);
  }

}

void convert_from_dollars(double dollars, double *euro, double *kroner, double *rubles, double *yen) {

  *euro = dollars * DOLLAR_IN_EURO;
  *kroner = dollars * DOLLAR_IN_KRONE;
  *rubles = dollars * DOLLAR_IN_RUBEL;
  *yen = dollars * DOLLAR_IN_YEN;

}