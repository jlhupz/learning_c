#include <stdio.h>

int power(int base, int n);

int main()
{
    for (int i = 0; i < 8; ++i) {
        printf("%d %d\n", i, power(2, i));
    }
}

int power(int base, int n)
{
    int p;

    p = 1;
    for (int i = 0; i <= n; ++i) {
        p = p * base;
    }

    return p;
}
