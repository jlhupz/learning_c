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