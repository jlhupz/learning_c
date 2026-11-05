/*
 * Exercise 1-10. Program to copy its input to its output, replacing each tab
 * by \t, each backspace by \b and each backspace by \\.
*/

#include <stdio.h>

int main() 
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    return 0;
}
