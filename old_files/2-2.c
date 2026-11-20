/*
 * Date: 04/04/25
 * Author: Jefferson Lupac
 * Exercise 2-2. Write a loop equivalent to the for loop below without using && or ||.
 * for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
*/

#include <stdio.h>

#define MAXLINE 1000

enum boolean { NO, YES };

int get_line(char line[], int lim);

int main()
{
    char line[MAXLINE];
    
    get_line(line, MAXLINE);
    printf("%s", line);

    return 0;
}

int get_line(char line[], int lim)
{
    int c;
    int i = 0;
    int check = YES;

/* Uses the same conditions in the loop. */
    while (check) {
        if (i < lim - 1) 
            if ((c = getchar()) != '\n')
                if (c != EOF)
                    line[i++] = c;
                else
                    check = NO;
            else
                check = NO;
        else
            check = NO;
    }

/* better code, I think, as it uses negation of the conditions. 
    while (check) {
        if (i >= lim - 1)
            check = NO;
        else if ((c = getchar()) == '\n')
            check = NO;
        else if (c == EOF)
            check = NO;
        else 
            line[i++] = c;
    }
*/

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}
