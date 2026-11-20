/*
 * Date: 03/23/25
 * Author: Jefferson Lupac
 * Exercise 1-24. Write a program to chck a C program for rudimentary syntax errors like 
 * unbalanced parentheses, bracket and braces. Don't forget about quotes, both single 
 * and double, escape sequences, and comments. (This program is hard if you do it in 
 * full generality.)
*/

#include <stdio.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int stackPos = 0;

void push(char c);
int pop(void);
void skip_block_comment(void);
void skip_inline_comment(void);
void skip_quoted_string(void);
void skip_character_constant(void);

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            c = getchar();
            if (c == '*')
                skip_block_comment();
            else if (c == '/')
                skip_inline_comment();
        } else if (c == '"')
            skip_quoted_string();
        else if (c == '\'')
            skip_character_constant();
        else if (c == '[' || c == '{' || c == '(')
            push(c);
        else if (c == ']' || c == '}' || c == ')') {
            char d = pop();
            if (d == '[' && c != ']') {
                printf("Error: expected ']'\n"); 
                return 1;
            } else if (d == '{' && c != '}') {
                printf("Error: expected '}'\n"); 
                return 1;
            } else if (d == '(' && c != ')') {
                printf("Error: expected ')'\n"); 
                return 1;
            } else if (d == 0) {
                printf("Error: extraneous '%c'\n", c);
                return 1;
            }
        }
    }
    if (stackPos != 0) {
        char d = pop();
        if (d == '[') {
            printf("Error: expected ']'\n");
            return 1;
        } else if (d == '{') {
            printf("Error: expected '}'\n");
            return 1;
        } else if (d == '(') {
            printf("Error: expected ')'\n");
            return 1;
        }
    }
}

void push(char c)
{
    if (stackPos < STACK_SIZE)
        stack[stackPos++] = c;
    else
        printf("Error: stack is full, unable to push '%c'.\n", c);
}

int pop(void)
{
    if (stackPos > 0)
        return stack[--stackPos]; 
    else
        return 0; 
}

void skip_block_comment(void)
{
    for (int c = getchar(); c != EOF; c = getchar()) {
        if (c == '*') {
            c = getchar();
            if (c == '/') 
                return;
        }
    }
}
void skip_inline_comment(void)
{
    for (int c = getchar(); c != EOF && c != '\n'; c = getchar())
        ;
}
void skip_quoted_string(void)
{
    for (int c = getchar(); c != EOF && c != '"'; c = getchar()) {
        if (c == '\\')
            getchar();
    }
}
void skip_character_constant(void)
{
    for (int c = getchar(); c != EOF && c != '\''; c = getchar()) {
        if (c == '\\')
            getchar();
    }
}
