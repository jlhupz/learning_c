/*
 * Author: Jefferson Lupac
 * Date: 10 November, 2026
 * The C programming language chapter 1 exercise 1-4. Write a program to print 
 * the corresponding Celsius to Fahrenheit table 
 */

#include <stdio.h>
#define UPPER 300 
#define LOWER -17.8
#define STEP 5.0

int main()
{
    float fahrenheit;
    float celsius; 

    printf("CELSIUS        FAHRENHEIT\n\n");

    for(celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP) {
        fahrenheit = (celsius * (9.0/5.0)) + 32.0; 
        printf("%7.1f %17.1f\n", celsius, fahrenheit);
    }

    return 0;
}

