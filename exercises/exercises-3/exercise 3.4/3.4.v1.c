/* 
 * Title: Weeks, days, hours, minutes and seconds with "and" and ","
 * Description: Converting seconds into weeks, days, hours, minutes and seconds 
 * Assignment: 3.4
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-conditional-exp-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 13, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>
#define SECONDS_PER_MINUTE (60)
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_WEEK (7 * SECONDS_PER_DAY)

int main(void) {
	int num;

	printf("Enter whole number: ");

	//hvis scanf ikke finder et integer så returner fejl
	if (!scanf("%d", &num)) {
		printf("Please write an integer\n");
		exit(EXIT_FAILURE);
	}

	const int weeks = num / SECONDS_PER_WEEK;
	const int days = num / SECONDS_PER_DAY % 7;
	const int hours = num / SECONDS_PER_HOUR % 24;
	const int minutes = num / SECONDS_PER_MINUTE % 60;
	const int seconds = num % 60;
	
	if (weeks) {
		(weeks == 1) ? printf("%d uge", weeks) : printf("%d uger", weeks);
	}

	if (days) {
		if (weeks) (seconds == 0 && minutes == 0 && hours == 0) ? printf(" og ") : printf(", ");
		(days == 1) ? printf("%d dag", days) : printf("%d dage", days);
	}

	if (hours) {
		if (weeks || days) (seconds == 0 && minutes == 0) ? printf(" og ") : printf(", ");
		(hours == 1) ? printf("%d time", hours) : printf("%d timer", hours);
	}

	if (minutes) {
		if (weeks || days || hours) (seconds == 0) ? printf(" og ") : printf(", ");
		(minutes == 1) ? printf("%d minut", minutes) : printf("%d minutter", minutes);
	}
	
	if (seconds) {
		if (minutes || hours || days || weeks) printf(" og ");
		(seconds == 1) ? printf("%d sekund", seconds) : printf("%d sekunder", seconds);
	}

	printf("\n");

	return EXIT_SUCCESS;
}