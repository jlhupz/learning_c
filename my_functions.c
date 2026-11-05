/*
   Author: Jefferson Lupac
   Date: October 31, 2026
   My functions definition
*/

/* Own header to ensure consistency */
#include "my_functions.h"

/* Convert fahrenheit to celsius  */
float to_celsius(float fahrenheit) { return (5.0 / 9.0) * (fahrenheit - 32); }

/* Convert celsius to fahrenheit  */
float to_fahrenheit(float celsius) { return celsius * (9.0 / 5.0) + 32; }
