#include <stdio.h>

int main(void) {
    float first,middle,last;

    printf("Give me three => ");
    scanf("%f%f%f", &first, &middle, &last);
    printf("The result / average: %.2f\n", (first + middle + last) / 3.0);
    return 0;
}
