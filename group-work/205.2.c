/* 
 * Title: Write assignment statements for the following:
 * Assignment: Exercise 2 from page 205
 * 
 * Programmers: Sebastian Livoni, Simon Halkjær Tander, Richard Avenia, Lasse Fjellanger, Jacob Kyed Andreassen
 * Date completed: September 15, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdlib.h>
#include <stdio.h>

int main(void) {

    int between, divisor, lowercase;

    int k = 9;
    int n = 7;

    int digit = 10;
    int num = 5;

    char ch = 'a';

    between = !(n < -k || n > +k);
    printf("between = %d\n", between);

    divisor = (digit % num == 0);
    printf("divisor = %d\n", divisor);
    

    lowercase = ('a' <= ch && ch <= 'z');
    printf("lowercase = %d\n", lowercase);
    
    return 0;

}