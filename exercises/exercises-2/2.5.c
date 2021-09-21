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
#define SECONDS_PER_MINUTE (60)
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_WEEK (7 * SECONDS_PER_DAY)

int main(void) {
    int num;
    
    printf("Enter whole number: ");
    scanf("%d", &num);

    const int weeks = num / SECONDS_PER_WEEK; // 60 / 60 / 24 / 7
    const int days = num / SECONDS_PER_DAY % 7; // 60 / 60 / 24
    const int hours = num / SECONDS_PER_HOUR % 24; // 60 / 60
    const int minutes = num / SECONDS_PER_MINUTE % 60;
    const int seconds = num % 60;

    printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder.\n", weeks, days, hours, minutes, seconds);

    return 0;
}