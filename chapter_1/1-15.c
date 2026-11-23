/*
 * Author: Jefferson Lupac
 * Date: 23 November, 2026
 * The C programming language chapter 1 exercise 1-15. Rewrite the temperature
 * conversion program of section 1-2 to use a function for conversion.
 */

#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20

double to_celsius(double fahrenheit);

int main()
{
    int fahrenheit;

    printf("FAHRENHEIT        CELSIUS\n\n");

    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP) {
        printf("%9d %15.1f\n", fahrenheit, to_celsius(fahrenheit));
    }

    return 0;
}

double to_celsius(double fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
