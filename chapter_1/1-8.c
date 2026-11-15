/*
 * Author: Jefferson Lupac
 * Date: 15 November, 2026
 * The C programming language chapter 1 exercise 1-8.  Write a program to count
 * blanks, tabs, and newlines.
 */

#include <stdio.h>

int main()
{
    int c, blanks = 0, tabs = 0, lines = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++lines;
        }
        else if (c == '\t') {
            ++tabs;
        } 
        else if (c == ' ') {
            ++blanks;
        }
    }

    printf("Number of blanks: %d\n", blanks);
    printf("Number of lines: %d\n", lines);
    printf("Number of tabs: %d\n", tabs);

    return 0;
}