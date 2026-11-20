/*
 * Date: 03/05/25
 * Author: Jefferson Lupac
 * Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column
 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8
#define LINEWIDTH 80

int fold(char line[], int lineWidth);
int main()
{
    char line[MAXLINE];

    printf("%d\n\n", fold(line, LINEWIDTH));
    printf("          1         2         3         4        5         6         "
           "7         8\n");
    printf(".....:....|....;....|....:....|....:....|...:....|....;....|....:...."
           "|....:....|\n\n");
    printf("%s\n", line);
    getchar();
    return 0;
}

int fold(char line[], int lineWidth)
{
    int c, i;
    int lastIndex = 0;
    int pos = 1;
    int lastPos;

    for (i = 0; i < MAXLINE - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
        if (pos <= LINEWIDTH) {
            if (c == ' ') {
                lastIndex = i;
                lastPos = pos;
            } else if (c == '\t') {
                lastIndex = i;
                lastPos = pos += TABSTOP - (pos % TABSTOP);
            }
        } else {
            if (lastPos == 0) {
                line[i++] = '\n';
                pos -= LINEWIDTH;
            } else {
                line[lastIndex] = '\n';
                pos -= lastPos;
                lastPos = 0;
            }
        }
        line[i] = c;
        ++pos;
    }
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
