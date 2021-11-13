/*
 * Title: Brøker og structs
 * Description: 
 * Assignment: Opgave 12.5 
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/structures-flere-opgaver-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 13, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int numerator;
  unsigned int denominator;
} Fraction;

unsigned int gcd(unsigned int large, unsigned int small);
Fraction create_fraction(unsigned int num, unsigned int denom);
void shorten_fraction(Fraction *fraction);
void printf_fraction(Fraction fraction);
Fraction multiply_fraction_with_integer(Fraction fraction, unsigned int integer);
Fraction multiply_fraction_with_fraction(Fraction fraction1, Fraction fraction2);
Fraction add_fractions(Fraction fraction1, Fraction fraction2);

int main(void) {

  Fraction fraction1 = {1, 3}, 
           fraction2 = {2, 5};

  shorten_fraction(&fraction1);
  printf_fraction(fraction1);

  printf_fraction(multiply_fraction_with_integer(fraction1, 50));

  printf_fraction(multiply_fraction_with_fraction(fraction1, fraction2));

  printf_fraction(add_fractions(fraction1, fraction2));

}

void shorten_fraction(Fraction *fraction) {
  unsigned int gcd_frac = gcd(fraction->numerator, fraction->denominator);
  fraction->numerator /= gcd_frac;
  fraction->denominator /= gcd_frac;
}

Fraction create_fraction(unsigned int num, unsigned int denom) {
  Fraction created_fraction;
  created_fraction.numerator = num;
  created_fraction.denominator = denom;

  shorten_fraction(&created_fraction);
  return created_fraction;
}

unsigned int gcd(unsigned int large, unsigned int small) {
  unsigned int remainder; 
  while (small > 0){
    remainder = large % small;
    large = small;
    small = remainder;
  }
  return large;
}

void printf_fraction(Fraction fraction) {
  printf("%d\n-\n%d\n", fraction.numerator, fraction.denominator);
}

Fraction multiply_fraction_with_integer(Fraction fraction, unsigned int integer) {
  fraction.numerator *= integer;
  shorten_fraction(&fraction);
  return fraction;
}

Fraction multiply_fraction_with_fraction(Fraction fraction1, Fraction fraction2) {
  unsigned int common_numerator = fraction1.numerator * fraction2.numerator,
               common_denominator = fraction1.denominator * fraction2.denominator;

  Fraction multiplied_fraction = create_fraction(common_numerator, common_denominator);
  return multiplied_fraction;
}

Fraction add_fractions(Fraction fraction1, Fraction fraction2) {
  Fraction sum_fraction;
  unsigned int numerator = fraction1.numerator * fraction2.denominator,
               denominator = fraction1.denominator * fraction2.denominator;

  numerator += fraction2.numerator * fraction1.denominator;

  sum_fraction = create_fraction(numerator, denominator);
  return sum_fraction;
}
