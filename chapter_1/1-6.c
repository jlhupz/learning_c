/*
 * Author: Jefferson Lupac
 * Date: 14 November, 2026
 * The C programming language chapter 1 exercise 1-6. Verify that the expression
 * getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

int main()
{
    int c;

    while (c = getchar() != EOF)
        printf("%d", c);
        /* it prints 1 if getchar() is not EOF and end the loop if it is */

    printf("%d\n", c);
    /* getchar was EOF, condition evaluated as false and recorded in variable 
    c, confirmed it with printf */

    return 0;
}