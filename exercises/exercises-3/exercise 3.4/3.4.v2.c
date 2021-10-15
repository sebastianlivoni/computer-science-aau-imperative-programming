/* 
 * Title: Weeks, days, hours, minutes and seconds with "and" and ","
 * Description: Converts seconds into weeks, days, hours, minutes and seconds using a nice layout
 * Assignment: 3.4
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-conditional-exp-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 22, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SECONDS_PER_MINUTE (60)
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define SECONDS_PER_WEEK (7 * SECONDS_PER_DAY)

int main(void) {
	double numScan;

	printf("Enter whole number: ");

	//if scanf is not an integer
	if (!scanf(" %lf", &numScan)) {
		printf("Please write an integer\n");
		exit(EXIT_FAILURE);
	}

	int num = (int) round(numScan); //round input - % requires integers otherwise use fmod()

	const unsigned int weeks = num / SECONDS_PER_WEEK;
	const unsigned int days = num / SECONDS_PER_DAY % 7;
	const unsigned int hours = num / SECONDS_PER_HOUR % 24;
	const unsigned int minutes = num / SECONDS_PER_MINUTE % 60;
	const unsigned int seconds = num % 60;

	if (weeks) {
		printf("%d week%s", weeks, weeks > 1 ? "s" : "");
	}

	//checks if days is bigger than 0
	if (days) {
		/* if weeks is bigger than 0 and seconds, minutes, hours is equal to 0 then days is 
		the last element and we'll print "and" otherwise "," */
		if (weeks) printf("%s", (seconds == 0 && minutes == 0 && hours == 0) ? " and " : ", ");
		printf("%d day%s", days, days > 1 ? "s" : "");
	}

	if (hours) {
		if (weeks || days) printf("%s", (seconds == 0 && minutes == 0) ? " and " : ", ");
		printf("%d hour%s", hours, hours > 1 ? "s" : "");
	}

	if (minutes) {
		if (weeks || days || hours) printf("%s", (seconds == 0) ? " and " : ", ");
		printf("%d minute%s", minutes, minutes > 1 ? "s" : "");
	}
	
	if (seconds) {
		if (minutes || hours || days || weeks) printf(" and ");
		printf("%d second%s", seconds, seconds > 1 ? "s" : "");
	}

	printf("\n");

	return EXIT_SUCCESS;
}