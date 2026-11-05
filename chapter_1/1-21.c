/*
 * Date: 02/28/25
 * Author: Jefferson Lupac
 * Exercise 1-21. Write a program entab that replaces strings
 * of blanks by the minimum number of tabs and blanks to achieve
 * the same spacing. Use the same tab stops, which should be
 * given preference?
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/
#define TABSTOP 8

int getln(char line[], int lim);
int entab(char out[], char in[], int ts);

int main()
{
    char line[MAXLINE];   /* current input line */
    char output[MAXLINE]; /* store the output lines here */

    printf("Tab\t|\t|\t|\t|\t|\t|\n");
    printf("stops\t!\t!\t!\t!\t!\t!\n\n");
    printf("~ %d\n\n", getln(line, MAXLINE));
    printf("%s~ %d\n", output, entab(output, line, TABSTOP));

    return 0;
}

/* getln: read a line and return length */
int getln(char line[], int lim)
{
    int c, i, len = 0;

    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c != '\n') {
        while ((c = getchar()) != '\n' && c != EOF) {
            ++len;
        }
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i + len;
}

/* entab: replace strings of blanks by the minimum number of tabs and blanks */
int entab(char out[], char in[], int ts)
{
    int i, j, numSpaces, pos;

    for (i = 0, j = 0, numSpaces = 0, pos = 1; in[i] != '\0'; ++i, ++pos) {
        if (in[i] == ' ') {
            ++numSpaces;
            if ((pos % ts) == 0) {
                if (numSpaces > 1) {
                    out[j++] = '\t';
                    numSpaces = 0;
                } else {
                    out[j++] = ' ';
                    numSpaces = 0;
                }
            }
        } else if (numSpaces) {
            while (numSpaces > 0) {
                out[j++] = ' ';
                --numSpaces;
            }
            if (in[i] == '\t') {
                out[j++] = in[i];
                pos += ts - (pos % ts);
            } else
            out[j++] = in[i];
        } else {
            out[j++] = in[i];
        }
    }
    out[j] = '\0';
    return j;
}
