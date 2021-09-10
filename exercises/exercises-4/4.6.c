/* 
 * Title: Timer, minutter og sekunder - igen
 * Description: Converting seconds into weeks, days, hours, minutes and seconds 
 * Assignment: 3.4
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/control-conditional-exp-slide-exercise-1.html
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
	
	if (b > a) {
		int temp_a = a;
		a = b;
		b = temp_a;
	}

	for (int i = 1; i < a; i++) {
		(a % i == 0 && b % i == 0) ? sfd = i : 0;
	}

	printf("Største fælles divisor: %d\n", sfd);

	return 0;
}