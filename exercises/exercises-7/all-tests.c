#include "CuTest.h"
#include <stdio.h>

CuSuite* daysInMonthGetSuite(void);    
    
void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
      
  CuSuiteAddSuite(suite, daysInMonthGetSuite());  /* Adding our test suite */

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}
    
int main(void) {
  RunAllTests();
}