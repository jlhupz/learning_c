/*
 * Author: Jefferson Lupac
 * Date: 10 November, 2026
 * The C programming language chapter 1 exercise 1-3. Modify the temperature
 * conversion program to print a heading above the table.
 */

#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20

int main()
{
    int fahrenheit;
    float celsius;

    printf("FAHRENHEIT        CELSIUS\n\n");

    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP) {
        celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%9d %15.1f\n", fahrenheit, celsius);
    }

    return 0;
}
