/*
    Author: Jefferson Lupac
    Date: October 31, 2026
    Print fahrenheit to celsius table.
*/

#include "my_functions.h"
#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main() {
  /* variable declaration */
  float celsius, fahrenheit;

  /* Calculation and print the table */
  for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP) {
    // celsius = (5.0/9.0) * (fahrenheit - 32);
    printf("%.2f\t%.2f\n", fahrenheit, to_celsius(fahrenheit));
  }

  printf("\n\n");

  while (fahrenheit >= LOWER) {
    printf("%.2f\t%.2f\n", to_fahrenheit(to_celsius(fahrenheit)),
           to_celsius(fahrenheit));
    fahrenheit -= STEP;
  }

  return 0;
}
