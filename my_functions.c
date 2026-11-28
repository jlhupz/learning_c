/*
   Author: Jefferson Lupac
   Date: October 31, 2026
   My functions definition
*/

// Own header to ensure consistency.
#include "my_functions.h"
#include <stdio.h>

// Convert fahrenheit to celsius.
double to_celsius(float fahrenheit) { return (5.0 / 9.0) * (fahrenheit - 32); }

// Convert celsius to fahrenheit.
double to_fahrenheit(float celsius) { return celsius * (9.0 / 5.0) + 32; }

int get_string(char char_array[], int max_chars)
{
    int i;

    for (i = 0; (char_array[i] = getchar()) != EOF && i < max_chars; ++i) {
        /* Empty block */
    }

    char_array[i] = '\0';

    return 0;
}

// Print vertical histogram.
int print_vert_histogram(char char_array[], int max_chars)
{
    return 0;
}

// Print horizontal histogram.
int print_hor_histogram(char char_array[], int max_chars)
{
    return 0;
}
