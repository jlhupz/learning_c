/*
 * test, this is a block comment
 */

#include <stdio.h>

int htoi(char *s);
int string_length(char *s);
int is_leap_year(int year);
int atoi(char *s);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    /*
     * 00011000
     * 00000110
     * */

    char c = 0b10001101;
    unsigned int i;

    i = getbits(c, 4, 3);

    printf("%o\n", i);
    return 0;
}

int atoi(char *s)
{
    int n = 0;

    for (int i = 0; *(s + i) >= '0' && *(s + i) <= '9'; i++)
        n = n * 10 + (*s - '0');

    return n;
}

int htoi(char s[])
{
    int n = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
    }
    return n;
}

int string_length(char *s)
{
    int i = 0;
    while (*(s + i) != '\0')
        ++i;
    return i;
}

int is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return year;
    else
        return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
