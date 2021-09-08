/* 
 * Title: Timer, minutter og sekunder - igen
 * Description: Converting seconds into weeks, days, ..., seconds 
 * Assignment: 3.4
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-conditional-exp-slide-exercise-1.html
 */

#include <stdio.h>

int main(void) {
	int num = 4980;

	//printf("Enter whole number: ");
	//scanf("%d", &num);

	const int seconds = num % 60;
	const int minutes = num / 60 % 60;
	const int hours = num / 3600 % 24; // 60 / 60
	const int days = num / 86400 % 7; // 60 / 60 / 24
	const int weeks = num / 604800; // 60 / 60 / 24 / 7

	//printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder.\n", weeks, days, hours, minutes, seconds);

	if (weeks > 0) {
		(weeks == 1) ? printf("%d uge", weeks) : printf("%d uger", weeks);
	}
	if (days > 0) {
		(days == 1) ? printf("%d dag", days) : printf("%d dage", days);
	}
	if (hours > 0) {
		(hours == 1) ? printf("%d time", hours) : printf("%d timer", hours);
	}
	if (minutes > 0) {
		(minutes == 1) ? printf("%d minut", minutes) : printf("%d minutter", minutes);
	}
	if (seconds > 0) {
		(seconds == 1) ? printf("%d sekund", seconds) : printf("%d sekunder", seconds);
	}

	return 0;
}