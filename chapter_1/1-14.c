/*
 * Author: Jefferson Lupac
 * Date: 19 November, 2026
 * The C programming language chapter 1 exercise 1-14. Write a program to print
 * a histogram of the frequencies of different characters in its input.
 */

#include <stdio.h>
#define MAX_CHARS 36

int main()
{
    int c, char_counts[MAX_CHARS + 1] = {0};

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        if (c >= '0' && c <= '9') {
            ++char_counts[c - '0'];
        } else if (c >= 'A' && c <= 'Z') {
            ++char_counts[c - 'A' + 10];
        } else if (c != ' ' && c != '\n' && c != '\t') {
            ++char_counts[MAX_CHARS];
        }
    }

    // Find the highest character counts.
    int highest_freq = 0;

    for (int i = 0; i <= MAX_CHARS; ++i) {
        if (char_counts[i] > highest_freq) {
            highest_freq = char_counts[i];
        }
    }
    // Print vertical histogram.
    while (highest_freq > 0) {
        printf("%3d ", highest_freq);
        for (int i = 0; i <= MAX_CHARS; ++i) {
            if (char_counts[i] >= highest_freq) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        putchar('\n');
        --highest_freq;
    }

    printf("    ");

    for (int i = 0; i <= MAX_CHARS; ++i) {
        if (i >= 0 && i <= 9) {
            printf(" %c ", i + '0');
        } else if (i >= 10 && i <= 35) {
            printf(" %c ", i - 10 + 'A');
        } else {
            printf(" !?");
        }
    }

    // Print horizontal historgram.
    /*
    for (int i = 0; i <= MAX_CHARS; ++i) {
        if (i >= 0 && i <= 9) {
            printf("\n%c     : %d ", i + '0', char_counts[i]);
        } else if (i >= 10 && i <= 35) {
            printf("\n%c     : %d ", i - 10 + 'A', char_counts[i]);
        } else {
            printf("\nOther : %d ", char_counts[i]);
        }

        for (int j = 0; j < char_counts[i]; ++j) {
            printf("#");
        }
    }
    */
    putchar('\n');

    return 0;
}
