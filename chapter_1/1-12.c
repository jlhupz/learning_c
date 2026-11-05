/*
 * Exercise 1-12. Program that prints its input one word per line.
*/

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');

            while ((c = getchar()) == ' ' || c == '\t') {
                // do nothing
            }

            putchar(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}

/*
 * Old version
 *


#include <stdio.h>
#define IN 1
#define OUT 0

int main() 
{
    int state = IN;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            putchar('\n');
            state = IN;
        }
        putchar(c);
    }
    return 0;
}
*/

