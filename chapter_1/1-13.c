/*
 * Exercise 1-13. A program to print a histogram of the MAX_WORD_LENGTHs of words in its
 * input. Horizontal and vertical histogram version.
*/

#include <stdio.h>

#define MAX_WORD_LENGTH 20

void print_horizontal_histogram(int *wordLengthCount, int maxWordLength);
void print_vertical_histogram(int *wordLengthCount, int maxWordLength);

int main() 
{
    enum boolean { OUT, IN };
    enum boolean state = OUT;
    int charCount = 0;
    int wordLengthCount[MAX_WORD_LENGTH];
    int c;

    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        wordLengthCount[i] = 0;
    }

    while ((c = getchar()) != EOF && charCount <= MAX_WORD_LENGTH) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '.') {
            if (state == IN) {
                ++wordLengthCount[charCount - 1];
                charCount = 0;
                state = OUT;
            }
        } else if (state == OUT) {
            state = IN;
            charCount = 1;
        } else {
            ++charCount;
        }
    }

    if (charCount >= MAX_WORD_LENGTH) {
        printf("\nError: Word length is larger than MAX_WORD_LENGTH(%d) is too big.\n", MAX_WORD_LENGTH);
        return 1;
    }

    print_horizontal_histogram(wordLengthCount, MAX_WORD_LENGTH);
    print_vertical_histogram(wordLengthCount, MAX_WORD_LENGTH);

    return 0;
}

void print_horizontal_histogram(int *wordLengthCount, int maxWordLength)
{
    printf("\n\n+----------------------+\n");
    printf("| Horizontal Histogram |\n");
    printf("+======================+\n\n");

    for (int i = 0; i < maxWordLength; ++i) {
        if (wordLengthCount[i]) {
            printf("\n%3d Character(s)\t%4d ", i + 1, wordLengthCount[i]);

            for (int j = wordLengthCount[i]; j > 0; --j) {
                putchar('#');
            }
        }
    }

    putchar('\n');
}

void print_vertical_histogram(int *wordLengthCount, int maxWordLength)
{
    unsigned int max;

    printf("\n\n+--------------------+\n");
    printf("| Vertical Histogram |\n");
    printf("+====================+\n\n");

    for (int i = 0; i < maxWordLength; ++i) {
        if (wordLengthCount[i] > max) {
            max = wordLengthCount[i];
        }
    }

    for (int i = max + 3; i >= 0; --i) {
        if (i > 0) {
            printf("%2d\t", i);
        } else {
            printf("\t");
        }

        for (int j = 0; j < maxWordLength; ++j) {
            if (i == 0) {
                printf("%3d  ", j + 1);
            } else if (wordLengthCount[j] >= i) {
                printf(" ### ");
            } else {
                printf("     ");
            }
        }

        putchar('\n');
    }
}
