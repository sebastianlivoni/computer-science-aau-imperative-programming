/* 
 * Title: Convert seconds to weeks, days, hours, minutes and seconds.
 * Description: Converting seconds into weeks, days, hours, minutes and seconds 
 * Assignment: 2.5
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/intro-circle-example-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 4, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>

int main(void) {
    int num;
    
    printf("Enter whole number: ");
    scanf("%d", &num);

    const int seconds = num % 60;
    const int minutes = num / 60 % 60;
    const int hours = num / 3600 % 24; // 60 / 60
    const int days = num / 86400 % 7; // 60 / 60 / 24
    const int weeks = num / 604800; // 60 / 60 / 24 / 7

    printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder.\n", weeks, days, hours, minutes, seconds);

    return 0;
}