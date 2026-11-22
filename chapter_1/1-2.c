/*
 * Author: Jefferson Lupac
 * Date: 07 November, 2026
 * The C programming language chapter 1 exercise 1-2. Experiment to find out
 * what happens when printf’s argument string contains \c, where c is some
 * character not listed above.
 */

#include <stdio.h>

int main()
{

    printf("Hello, world!\n");
    printf("\nHello, world!\a\a");
    printf("\nHello, world!\b\b");
    printf("\nHello, world!\c\c");
    printf("\nHeddo, wordd!\d\d");
    printf("\nHeeeo, wored!\e\e");
    printf("\nHeffo, worfd!\f\f");
    printf("\nHeggo, worgd!\g\g");
    printf("\nHehho, worhd!\h\h");

    return 0;
}
