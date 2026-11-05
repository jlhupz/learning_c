/*
 * Date: 02/19/25
 * Author: Jefferson Lupac
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blanks lines
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/
#define MAX_OUTPUT_BUFFER 10000

int getln(char line[], int lim);
void rmMultiBlanks(char s[]);
void stcat(char to[], char from[]);
int isNotBlank(char s[]);

int main()
{
    char line[MAXLINE];             /* current input line */
    char output[MAX_OUTPUT_BUFFER]; /* store the output lines here */

    while (getln(line, MAXLINE)) {
        rmMultiBlanks(line);
        if (isNotBlank(line))
            stcat(output, line);
    }
    printf("%s", output);
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

/* rmMultiBlanks: remove trailing blanks and replace one or more blanks with
 * one. */
void rmMultiBlanks(char s[])
{
    int i, j, state = 1;

    for (i = 0; s[i] == ' ' || s[i] == '\t'; ++i)
        ;
    for (j = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' || s[i] == '\t')
            state = 0;
        else if (state == 0) {
            if (s[i] != '\n')
                s[j++] = ' ';
            s[j++] = s[i];
            state = 1;
        } else
        s[j++] = s[i];
    }
    s[j] = '\0';
}

/* stcat: concatenate 'from' into 'to'; 'to' is limited by the MAXLINE*/
void stcat(char to[], char from[])
{
    int i, j;
    for (i = 0; to[i] != '\0'; ++i)
        ;
    for (j = 0; i < MAX_OUTPUT_BUFFER && (to[i] = from[j]) != '\0'; ++i, ++j)
        ;
}

/* isNotBlank: check if the line is not blank. */
int isNotBlank(char s[])
{
    int nc = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            ;
        else
            ++nc;
    }
    return nc;
}
