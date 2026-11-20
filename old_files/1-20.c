/*
 * Date: 02/27/25
 * Author: Jefferson Lupac
 * Exercise 1-20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed set
 * of tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/
#define TABSTOP 8

int getln(char line[], int lim);
int detab(char out[], char in[], int ts);

int main()
{
    char line[MAXLINE];   /* current input line */
    char output[MAXLINE]; /* store the output lines here */

    printf("Tab\t|\t|\t|\t|\t|\t|\n");
    printf("stops\t!\t!\t!\t!\t!\t!\n\n");
    printf("~ %d\n\n", getln(line, MAXLINE));
    printf("%s~ %d\n", output, detab(output, line, TABSTOP));

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

/* detab: replace tabs with proper number of blanks to the next tab stop. */
int detab(char out[], char in[], int ts)
{
    int i, j;

    for (i = 0, j = 0; (out[j] = in[i]) != '\0'; ++i) {
        if (in[i] == '\t') {
            out[j++] = ' ';
            while (j % ts)
                out[j++] = ' ';
        } else
        ++j;
    }
    return j;
}
