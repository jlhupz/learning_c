/*
 * Author: Jefferson Lupac
 * Date: 14 November, 2026
 * The C programming language chapter 1 exercise 1-5. Modify the temperature 
 * conversion program to print the table in reverse order, that is, from 300
 * degrees to 0.0
 */

#include <stdio.h>

int main()
{
    int fahrenheit;

    printf("Fahrenheit    Celsius\n");

    for (fahrenheit = 300; fahrenheit >= 0; fahrenheit = fahrenheit - 20)
        printf("%10d %10.1f\n", fahrenheit, (5.0/9.0) * (fahrenheit - 32));

    return 0;
}