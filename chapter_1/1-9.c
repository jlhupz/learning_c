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
    int c, prev_c;

    prev_c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            c = ' ';
        }
        if (prev_c != ' ' || c != ' ') {
            putchar(c);
        }
        prev_c = c;
    }

    return 0;
}
