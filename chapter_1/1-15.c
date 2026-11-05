/*
 *  Date: 02/12/25
 *  Author: Jefferson Lupac
 *  Exercise 1-15. Rewrite the temperature conversaion program of Section
 *  of C Programming Language to use a function for conversion.
 *  Convert Fahrenheit to Celcius using c = (5.0/9.0) * (f - 32)
 *  Convert Celcius to Fahrenheit using f = c * (9.0/5.0) + 32
 */

#include <stdio.h>
#define UPPER 300
#define LOWER 0

float celc(float);
float fahr(float);
void print_conversion_table(char tempUnit, float upper, float lower, int step);

int main() 
{
    char tempUnit;
    int step;

    printf("Enter temperature unit to convert to (c or f): ");
    scanf("%c", &tempUnit);
    printf("Enter number of temperature steps: ");
    scanf("%d", &step);

    if (step <= 0) {
        printf("Error: Invalid temperature unit steps.\n");
        return -1;
    }
    else if (tempUnit != 'c' && tempUnit != 'f') {
        printf("Error: Invalid temperature unit to convert to.\n");
        return -1;
    }
    else {
        print_conversion_table(tempUnit, UPPER, LOWER, step);
    }

    return 0;
}

float celc(float f) 
{ 
    return 5.0 / 9.0 * (f - 32.0); 
}

float fahr(float c) 
{ 
    return c * (9.0 / 5.0) + 32; 
}

void print_conversion_table(char tempUnit, float upper, float lower, int step) 
{
    if (tempUnit == 'c') {
        printf("==========================\n");
        printf("Celcius\t\tFahrenheit\n");
        printf("==========================\n\n");

        for (float c = -17.78; c <= upper; c += step) {
            printf("%6.2f\t\t%6.2f\n", c, fahr(c));
        }
    }
    else if (tempUnit == 'f') {
        printf("=======================\n");
        printf("Fahrenheit\tCelcius\n");
        printf("=======================\n\n");

        for (float fahr = upper; fahr >= lower; fahr -= step) {
            printf("%3.0f\t\t%6.2f\n", fahr, celc(fahr));
        }
    }
}
