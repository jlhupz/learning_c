#include <stdio.h>

void reverse(char s[]);
int str_len(char s[]);

int main()
{
    char string[100];
    int c, i;

    for (i = 0; (c = getchar()) != '\n' && c != EOF && i < 100 - 1; ++i) {
        string[i] = c;
    }
    string[i] = '\0';
    printf("String length: %d\n", str_len(string));
    reverse(string);
    printf("Reversed: %s\n", string);

    return 0;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    for (j = 0; s[j]; ++j)
        ;
    for (i = 0, --j; i < j; --j, ++i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
int str_len(char s[])
{
    int i;
    for (i = 0; s[i]; ++i)
        ;
    return i;
}
