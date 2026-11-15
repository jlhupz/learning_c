/*
 * Author: Jefferson Lupac
 * Date: 15 November, 2026
 * The C programming language chapter 1 exercise 1-9.  Write a program to copy 
 * its input to its output, replacing each string of one or more blanks by a 
 * single blank.
 */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c);

            while ((c = getchar()) == ' ') {
                ;
                /* Do nothing */
            }
        }

        putchar(c);
    }

    return 0;
}