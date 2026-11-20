/*
 * Date: 02/20/25
 * Author: Jefferson Lupac
 * Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/

int getln(char line[], int lim);
void reverse(char s[]);

int main()
{
    char line[MAXLINE]; /* current input line */

    while (getln(line, MAXLINE)) {
        reverse(line);
        printf("%s", line);
    }

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

/* reverse: reverses the character string s. */
void reverse(char s[])
{
    char tmp;
    int i, j;

    for (i = 0; s[i] != '\n' && s[i] != '\0'; ++i)
        ;
    for (--i, j = 0; j < i; ++j, --i) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
}
