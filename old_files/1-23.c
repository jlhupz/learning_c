/*
 * Date: 03/23/25
 * Author: Jefferson Lupac
 * Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle 
 * quoted strings and character constants properly. C comments do not nest. 
*/

#include <stdio.h>

#define BUFFER_SIZE 10000

char inputBuffer[BUFFER_SIZE];
int i = 0;

void remove_inline_comment(void);
void remove_block_comment(void);
void handle_quoted_string(void);
void handle_character_constant(void);

int main()
{
    int c;

    while (i < BUFFER_SIZE && (c = getchar()) != EOF) {
        if (c == '/') {
            int d = getchar();
            if (d == '/')
                remove_inline_comment();
            else if (d == '*')
                remove_block_comment();
            else {
                inputBuffer[i++] = c;
                inputBuffer[i] = d;
            }
        } else if (c == '"') {
            inputBuffer[i++] = c;
            handle_quoted_string();
        } else if (c == '\'') {
            inputBuffer[i++] = c;
            handle_character_constant();
        } else
            inputBuffer[i++] = c;
    }
    printf("%s\n", inputBuffer);
}

void remove_inline_comment(void)
{
    int c;
    while((c = getchar()) != EOF && c != '\n')
        ;
    if (c == '\n') 
        inputBuffer[i++] = c;
}

void remove_block_comment(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '*') {
            int d = getchar();
            if (d == '/')
                return;
        }
    }
}

void handle_quoted_string(void)
{
    int c;

    while (i < BUFFER_SIZE && (c = getchar()) != EOF && c != '"') {
        inputBuffer[i++] = c;
        if (c == '\\') 
            inputBuffer[i++] = getchar();
    }
    if (c == '"')
        inputBuffer[i++] = c;
}
void handle_character_constant(void)
{
    int c;

    while (i < BUFFER_SIZE && (c = getchar()) != EOF && c != '\'') {
        inputBuffer[i++] = c;
        if (c == '\\') 
            inputBuffer[i++] = getchar();
    }
    if (c == '\'')
        inputBuffer[i++] = c;
}
