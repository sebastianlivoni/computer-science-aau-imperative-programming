#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

int isLeapYear(int yr);

/* Function Under Test */
int daysInMonth(int month, int year){
  int numberOfDays;
  switch(month){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
      numberOfDays = 31; break;
    case 4: case 6: case 9: case 11: 
      numberOfDays = 30; break;
    case 2:
      if (isLeapYear(year)) numberOfDays = 29; 
      else numberOfDays = 28; break;
    default: exit(-1);  break;
  }
  return numberOfDays;
}   

/* Test function of daysInMonth */
void testDaysInMonthJan(CuTest *tc){
  int actual = daysInMonth(1, 2010);
  int expected = 31;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthFeb(CuTest *tc){
  int actual = daysInMonth(2, 2010);
  int expected = 28;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthApr(CuTest *tc){
  int actual = daysInMonth(4, 2010);
  int expected = 30;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthDec(CuTest *tc){
  int actual = daysInMonth(12, 2010);
  int expected = 31;
  CuAssertIntEquals(tc, expected, actual);
}  

/* Stub */
int isLeapYear(int year){
  return 0;
}

/* Test case management: Adding the test case to a test suite */
CuSuite* daysInMonthGetSuite(void) {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, testDaysInMonthJan);
  SUITE_ADD_TEST(suite, testDaysInMonthFeb);
  SUITE_ADD_TEST(suite, testDaysInMonthApr);
  SUITE_ADD_TEST(suite, testDaysInMonthDec);
  return suite;
}