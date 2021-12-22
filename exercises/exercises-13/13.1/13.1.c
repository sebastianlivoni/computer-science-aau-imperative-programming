/*
 * Title: Læsning af k ord fra fil
 * Description: Skriv en funktion der, om muligt, læser k ord fra tekstfilen
 * Assignment: 13.1
 * Link to assignment: http://people.cs.aau.dk/%7Enormark/impr-c/io-seqfile-op-slide-exercise-1.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: December 22, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_URL "./file.txt"

int getwords(FILE *ifp, int k, char *words);

int main(int argc, char const *argv[]) {
	
	FILE *fptr = fopen(FILE_URL, "r");
	char *words = malloc(500);
	int i;

	i = getwords(fptr, 20, words);

	fclose(fptr);

	printf("Found: %d words. Here they are:\n%s", i, words);

	return EXIT_SUCCESS;
}

int getwords(FILE *ifp, int k, char *words) {
	int i;
	char word[20];

	if (ifp == NULL) {
		printf("The file could not be read!\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (fscanf(ifp, "%s", word) == 1 && i < k) {
		strcat(words, word);
		strcat(words, "\n");
		i++;
	}

	return i;
}
