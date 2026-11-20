/*
 * Date: 02/18/25
 * Author: Jefferson Lupac
 * Exercise 1-16. Revise the main routine of the longest-line program so it
 * will correctly print the length of arbitrarily long input lines, and as much
 * as possible of the text.
*/

#include <stdio.h>

#define CHAR_LIM 1024 /* maximum input line size*/

int get_line(char line[], int lim);
void copy(char to[], char from[]);

/* print longest input line */
int main() 
{
    int c;
    int len;               /* current line length */
    int max = 0;           /* maximum length seen so far */
    char line[CHAR_LIM];    /* current input line */
    char longest[CHAR_LIM]; /* longest line saved here */

    while ((len = get_line(line, CHAR_LIM))) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max) {
        printf("\nLength: %4d\n", max);
        printf("Longest line: \"%s", longest);
        
        if (max > CHAR_LIM) {
            printf("...\"\n");
        }           
        else {
            printf("\"\n");
        }
    }
    return 0;
}

/* get_line: read a line and return length */
int get_line(char line[], int lim) 
{
    int c; 
    int i = 0;
    int len = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }

    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != '\n' && c != EOF) {
            ++len;
        }
    }
    
    line[i] = '\0';
    return i + len;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i) {
        // empty block
    }
}
