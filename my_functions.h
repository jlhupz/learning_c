/*
    Author: Jefferson Lupac
    Date: October 31, 2026
    My functions header
*/

#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

// Convert fahrenheit to celsius.
double to_celsius(float fahrenheit);

// Convert celsius to fahrenheit.
double to_fahrenheit(float celsius);

// Capture input string.
int get_string(char char_array[], int max_chars);

// Print horizontal histogram.
int print_vert_histogram(char char_array[], int max_chars);

// Print horizontal histogram.
int print_hor_histogram(char char_array[], int max_chars);

#endif
