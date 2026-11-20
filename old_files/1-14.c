/*
 * Exercise 1-14. A program to print a histogram of the frequencies of
 * different characters in its input. Horizontal and vertical histogram version.
*/

#include <stdio.h>
#define MAX_CHAR 27

void print_horizontal_histogram(int *charFreq, int maxChar);
void print_vertical_histogram(int *charFreq, int maxChar);

int main() 
{
    int c;
    int charFreq[MAX_CHAR];

    for (int i = 0; i < MAX_CHAR; ++i) {
        charFreq[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++charFreq[c - 'a'];
        } else if ( c >= 'A' && c <= 'Z') {
            ++charFreq[c - 'A'];
        } else {
            ++charFreq[MAX_CHAR - 1];
        }
    }

    /* 
    // Horizontal histogram
    for (i = 0; i < 255; ++i) {
        if (charFreq[i]) {
            printf("\n%c\t%d ", i, charFreq[i]);
            for (j = charFreq[i]; j > 0; --j) {
                putchar('+');
            }
        }
    }

    // Verital histogram
    for (int i = HIGH; i >= 0; --i) {
        printf("%3d\t", i);

        for (int j = 0; j < 255; ++j) {
            if (charFreq[j] == 0)
                ;
            else if (i == 0)
                printf(" %c  ", j);
            else if (charFreq[j] >= i)
                printf("### ");
            else
                printf("    ");
        }

        putchar('\n');
    }
    */

    print_horizontal_histogram(charFreq, MAX_CHAR);
    print_vertical_histogram(charFreq, MAX_CHAR);

    return 0;
}

void print_horizontal_histogram(int *charFreq, int maxChar)
{
    printf("\n\n+----------------------+\n");
    printf("| Horizontal Histogram |\n");
    printf("+======================+\n\n");

    for (int i = 0; i < maxChar; ++i) {
        if (charFreq[i]) {
            printf("\n%c%c - %4d ", i + 'A', i + 'a', charFreq[i]);

            for (int j = charFreq[i]; j > 0; --j) {
                putchar('#');
            }
        }
    }

    putchar('\n');
}

void print_vertical_histogram(int *charFreq, int maxChar)
{
    unsigned int max;

    printf("\n\n+--------------------+\n");
    printf("| Vertical Histogram |\n");
    printf("+====================+\n\n");

    for (int i = 0; i < maxChar; ++i) {
        if (charFreq[i] > max) {
            max = charFreq[i];
        }
    }

    for (int i = max + 3; i >= 0; --i) {
        if (i > 0) {
            printf("%2d\t", i);
        } else {
            printf("\t");
        }

        for (int j = 0; j < maxChar; ++j) {
            if (i == 0) {
                printf(" %c%c ", j + 'A', j + 'a');
            } else if (charFreq[j] >= i) {
                printf(" ## ");
            } else {
                printf("    ");
            }
        }

        putchar('\n');
    }
}
