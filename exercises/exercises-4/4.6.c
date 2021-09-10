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

int main(void) {

  int a, b, sfd;

	printf("Enter a and b => ");
	scanf("%d %d", &a, &b);

	if (a < 1 || b < 0) {
		printf("Et af de to tal er negative eller lig med 0...");
		return -1;
	}
	
	//hvis b er større end a så skifter vi dem lige :)
	if (b > a) {
		int temp_a = a;
		a = b;
		b = temp_a;
	}

	//fra i=1 indtil a - checker derefter om både (a og b) % i er lig med 0 og hvis det er det så er en en fælles divisor.
	for (int i = 1; i < a; i++) {
		(a % i == 0 && b % i == 0) ? sfd = i : 0;
	}

	printf("Største fælles divisor: %d\n", sfd);

	return 0;
}