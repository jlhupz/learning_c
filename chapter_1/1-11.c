/*
 * Author: Jefferson Lupac
 * Date: 15 November, 2026
 * The C programming language chapter 1 exercise 1-11.  How would you test the
 * word count program? What kinds of input are most likely to uncover bugs if
 * there are any?
 */

#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
    int c, state, line_count, word_count;

    state = OUT;
    line_count = word_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (c == '\n') {
                ++line_count;
            }
        } else if (state == OUT) {
            ++word_count;
            state = IN;
        }
    }

    printf("\nNumber of lines: %d\n", line_count);
    printf("Number of words: %d\n\n", word_count);

    return 0;
}