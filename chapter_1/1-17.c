/*
 * Date: 02/19/25
 * Author: Jefferson Lupac
 * Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>

#define CHAR_LIM 1024 
#define BUF_SIZE 102400
#define LINE_LENGTH 80

int get_line(char line[], int lim);
int copy_to_buf(char to[], char from[]);

int main() 
{
    int len;                        
    char line[CHAR_LIM];            
    char outputBuf[BUF_SIZE]; 

    for (int i = 0; i < CHAR_LIM; ++i) {
        outputBuf[i] = '\0';
    }

    while ((len = get_line(line, CHAR_LIM))) {
        if (len > LINE_LENGTH) {
            if (copy_to_buf(outputBuf, line) == -1) {
                printf("\nLines that are longer than 80 characters:\n\n%s", outputBuf);
                printf("\nOutput buffer is full.\n");
                return -1;
            }
        }
    }

    printf("\nLines that are longer than 80 characters:\n\n%s", outputBuf);
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

/* copy_to_buf: concatenate 'from' into 'to'; 'to' is limited by the CHAR_LIM*/
int copy_to_buf(char to[], char from[]) 
{
    int i, j; 

    for (i = 0; to[i] != '\0'; i++) {
        // empty block
    }
    
    for (j = 0; i < BUF_SIZE - 2 && (to[i] = from[j]) != '\0'; i++, j++) {
        // empty block
    }

    if (i == BUF_SIZE - 1 && j == 0) {
        return -1;
    }

    to[i++] = '\n';
    to[i] = '\0';

    return j;
}
