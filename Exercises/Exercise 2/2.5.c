/*
 * Convert seconds to weeks, days, hours, minutes and seconds.
 * http://people.cs.aau.dk/~normark/impr-c/intro-circle-example-slide-exercise-1.html
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