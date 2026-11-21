/*
 * Author: Jefferson Lupac
 * Date: 19 November, 2026
 * The C programming language chapter 1 exercise 1-13.   Write a program to
 * print a histogram of the lengths of words in its input. It is easy to draw
 * the histogram with the bars horizontal; a vertical orientation is more
 * challenging.
 * */

#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 28

int main() {
    int c, state = OUT, char_counts = 0, max_frequency = 0;
    int word_length_counts[MAX_WORD_LENGTH + 1] = {0};

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (char_counts > MAX_WORD_LENGTH) {
                    ++word_length_counts[0];
                } else {
                    ++word_length_counts[char_counts];
                }
                char_counts = 0;
            }
            state = OUT;
        } else {
            ++char_counts;
            state = IN;
        }
    }

    /* Count the word if the input ends EOF before any trailing whitespace */
    if (char_counts) {
        if (char_counts > MAX_WORD_LENGTH) {
            ++word_length_counts[0];
        } else {
            ++word_length_counts[char_counts];
        }
    }
    /* Find the most frequent word length */
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        if (word_length_counts[i] > max_frequency) {
            max_frequency = word_length_counts[i];
        }
    }

    /* print vertical histogram */
    while (max_frequency > 0) {
        printf("%3d\t", max_frequency);
        for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
            if (word_length_counts[i] >= max_frequency) {
                printf("### ");
            } else {
                printf("    ");
            }
        }
        putchar('\n');
        --max_frequency;
    }

    printf("   \t");

    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        printf(" %d  ", i);
    }

    /* print horizontal historgram */
    /*
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i) {
        if (word_length_counts[i] != 0) {
            printf("\n%d character word: %d ", i, word_length_counts[i]);
            for (int j = 0; j < word_length_counts[i]; ++j) {
                printf("#");
            }
        }
    }
    */
    putchar('\n');

    return 0;
}
