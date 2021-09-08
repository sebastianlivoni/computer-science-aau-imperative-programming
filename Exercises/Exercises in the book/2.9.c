// Chapter 2 - Opgave 9

// Opgave 11 side 125 i Problem Solving and Program Design in C, eighth edition.

#include <stdio.h>
#include <stdlib.h>

void convertFromSeconds(num) {
  const int seconds = num % 60;
  const int minutes = num / 60 % 60;
  const int hours = num / 3600 % 24; // 60 / 60
  const int days = num / 86400 % 7; // 60 / 60 / 24
  const int weeks = num / 604800; // 60 / 60 / 24 / 7

  printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder.\n", weeks, days, hours, minutes, seconds);
}

int main(void) {
  int length_yard, width_yard, check, length_house, width_house;
  double rate_in_square_meters = 0.18580608;
  
  printf("Type the length and width in meters of a rectangular yard:\n");
  check = scanf("%d %d", &length_yard, &width_yard);

  if (check != 2) {
    printf("Please type 2 integers");
    exit(EXIT_SUCCESS);
  }
  
  printf("Type the length and width in meters of a rectangular house in the yard:\n");
  check = scanf("%d %d", &length_house, &width_house);

  if (check != 2) {
    printf("Please type 2 integers\n");
    exit(EXIT_SUCCESS);
  }

  if (length_yard * width_yard < length_house * width_house) {
    printf("The yard's area must be bigger than the house\n");
    exit(EXIT_SUCCESS);
  }

  //printf("%.2f seconds\n", (length_yard * width_yard - length_house * width_house) / rate_in_square_meters);
  int num = (length_yard * width_yard - length_house * width_house) / rate_in_square_meters;
  convertFromSeconds(num); //printer x uger x dage x timer x min og x sekunder
  
  return 0;
}