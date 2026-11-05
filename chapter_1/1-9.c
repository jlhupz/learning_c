/*
 * Copy input to output, replacing each string of one or more blanks by a
 * single blanks
 */

#include <stdio.h>

int main() 
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar(' ');

            while ((c = getchar()) == ' ' || c == '\t') {
                // do nothing. 
            }

            putchar(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}
