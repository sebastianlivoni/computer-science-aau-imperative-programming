/* 
 * Title: Temperature Converter Challenge
 * Description: Write a program that takes in three arguments, a start temperature (in Celsius), an end temperature (in Celsius) and a step size and print out fahrenheit.
 * Assignment: From cprogramming.com
 * Link to assignment: https://www.cprogramming.com/challenges/celsius_converter_table.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: September 10, 2021
 */

#include <stdio.h>
#define LOWER_LIMIT 0
#define UPPER_LIMIT 50000

int main(void) {

  double start_temp_celcius, end_temp_celcius;
  int steps;


  //start temp
  printf("Please give in a lower limit, limit >= %d: ", LOWER_LIMIT);
  scanf("%lf", &start_temp_celcius);

  if (start_temp_celcius < LOWER_LIMIT) {
    printf("Start temparature must be >= 0\n");
    return -1;
  }

  //end temp
  printf("Please give in a higher limit, %.0f < limit <= %.0d: ", start_temp_celcius, UPPER_LIMIT);
  scanf("%lf", &end_temp_celcius);

  if (end_temp_celcius < start_temp_celcius) {
    printf("Higher limit is less than lower limit!\n");
    return -1;
  } else if (end_temp_celcius > UPPER_LIMIT) {
    printf("End temperature is higher than upper limit - not ok!\n");
  }

  //steps
  printf("Please give in a step, 0 < step <= %.0f: ", end_temp_celcius - start_temp_celcius);
  scanf("%d", &steps);
  
  if (steps > end_temp_celcius - start_temp_celcius) {
    printf("Step size must be in the difference between %.0f and %.0f\n", start_temp_celcius, end_temp_celcius);
    return -1;
  }

  printf("Celcius%12sFahrenheit\n", "");
  printf("-------%12s----------\n", "");

  while(start_temp_celcius <= end_temp_celcius) {
    //Fahrenheit = (C * 1,8) + 32

    printf("%f%10s%f\n", start_temp_celcius, "", (start_temp_celcius * 1.8) + 32);
    start_temp_celcius += steps;
  }

  return 0;
}