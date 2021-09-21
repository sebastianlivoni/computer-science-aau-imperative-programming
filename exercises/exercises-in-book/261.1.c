/* 
 * Title: There are 9,870 people in a town whose population increases by 10% each year.
 * Description: Write a loop that displays the annual population and determines how many years (count_years) it will take for the population to surpass 30,000.
 * Assignment: Page 261 Programming Project 1
 * Link to assignment: Book
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 21, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */

#include <stdio.h>
#define POPULATION 9870
#define MAX_POPULATION 30000
#define ANNUAL_INCREASE_IN_DECIMAL 1.1

int main(void) {
  int current_population = POPULATION, count_years = 0;

  while (current_population <= MAX_POPULATION) {
    current_population *= ANNUAL_INCREASE_IN_DECIMAL;
    count_years += 1;
  }

  printf("It will take %d years to surpass a population of %d people with an increase of %.0lf procent each year\n", count_years, MAX_POPULATION, ANNUAL_INCREASE_IN_DECIMAL * 10 - 1);
}