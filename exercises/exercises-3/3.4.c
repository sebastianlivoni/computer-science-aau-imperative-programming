/* 
 * Title: Timer, minutter og sekunder - igen
 * Description: Converting seconds into weeks, days, hours, minutes and seconds 
 * Assignment: 3.4
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-conditional-exp-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 8, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_WEEK (7 * SECONDS_PER_DAY)

int main(void) {
	int num;

	printf("Enter whole number: ");
	scanf("%d", &num);

	const int seconds = num % 60;
	const int minutes = num / SECONDS_PER_MINUTE % 60;
	const int hours = num / SECONDS_PER_HOUR % 24;
	const int days = num / SECONDS_PER_DAY % 7;
	const int weeks = num / SECONDS_PER_WEEK;
	
	if (weeks) {
		(weeks == 1) ? printf("%d uge", weeks) : printf("%d uger", weeks);
	}
	if (days) {
		(weeks) ? (seconds == 0 && minutes == 0 && hours) ? printf(" og ") : printf(", ") : 0;
		(days == 1) ? printf("%d dag", days) : printf("%d dage", days);
	}
	if (hours) {
		(weeks || days) ? (seconds == 0 && minutes == 0) ? printf(" og ") : printf(", ") : 0;
		(hours == 1) ? printf("%d time", hours) : printf("%d timer", hours);
	}
	if (minutes) {
		(weeks || days || hours) ? (seconds == 0) ? printf(" og ") : printf(", ") : 0;
		(minutes == 1) ? printf("%d minut", minutes) : printf("%d minutter", minutes);
	}
	if (seconds) {
		(minutes || hours || days || weeks) ? printf(" og ") : 0;
		(seconds == 1) ? printf("%d sekund", seconds) : printf("%d sekunder", seconds);
	}

	printf("\n");

	return 0;
}