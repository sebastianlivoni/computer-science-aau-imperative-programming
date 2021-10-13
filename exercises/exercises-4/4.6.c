/* 
 * Title: Ligefrem programmering af 'største fælles divisor'
 * Description: Største fælles divisor samt gentagning af beslutningen.
 * Assignment: 4.6
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/more-control-more-exercises-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 10, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int a, b, sfd;

	do {
		printf("Enter a and b => ");
		if (scanf(" %d %d", &a, &b) != 2) {
			printf("Der gik sgu noget galt / du stoppede det med vilje!\n");
			return EXIT_FAILURE;
		}
		
		//hvis temp_b er større end temp_a så skifter vi dem lige :)
		int max = a > b ? a : b;

		//fra i=1 indtil a - checker derefter om både (a og b) % i er lig med 0 og hvis det er det så er en en fælles divisor.
		for (int i = 1; i <= max; i++) {
			if (a % i == 0 && b % i == 0d) sfd = i;
		}

		printf("Største fælles divisor: %d\n", sfd);
	} while (a > 0 && b > 0);

	return EXIT_SUCCESS;
}