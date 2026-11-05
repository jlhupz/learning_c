/*
 * Date: 03/13/25
 * Author: Jefferson Lupac
 * Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers and by direct 
 * computation. Harder if you compute them: determine the ranges of the various floating-point types
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

long long signed_min(int bits);
long long signed_max(int bits);
unsigned long long unsigned_max(int bits);

int main()
{
    int charBits = sizeof(char) * 8;
    int shortBits = sizeof(short) * 8;
    int intBits = sizeof(int) * 8;
    int longBits = sizeof(long) * 8;

    printf("Range of Data types from standard headers:\n");
    printf("CHAR_MIN: %d\n", SCHAR_MIN);
    printf("CHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %d\n\n", UCHAR_MAX);
    printf("SHRT_MIN: %hd\n", SHRT_MIN);
    printf("SHRT_MAX: %hd\n", SHRT_MAX);
    printf("USHRT_MAX: %hu\n\n", USHRT_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n\n", UINT_MAX);
    printf("LONG_MIN: %li\n", LONG_MIN);
    printf("LONG_MAX: %li\n", LONG_MAX);
    printf("ULONG_MAX: %lu\n\n\n", ULONG_MAX);

    printf("Range of Data types in C (Computed)\n");
    printf("signed char: %lld to %lld\n", signed_min(charBits), signed_max(charBits));
    printf("unsigned char: 0 to %llu\n\n", unsigned_max(charBits));
    printf("signed short: %lld to %lld\n", signed_min(shortBits), signed_max(shortBits));
    printf("unsigned short: 0 to %llu\n\n", unsigned_max(shortBits));
    printf("signed int: %lld to %lld\n", signed_min(intBits), signed_max(intBits));
    printf("unsigned int: 0 to %llu\n\n", unsigned_max(intBits));
    printf("signed long: %lld to %lld\n", signed_min(longBits), signed_max(longBits));
    printf("unsigned long: 0 to %llu\n\n", unsigned_max(longBits));
}
long long signed_min(int bits)
{
    long long result = 1;
    for (bits -= 1; bits > 0; --bits)
        result *= 2;
    return -(result);
}

long long signed_max(int bits)
{
    long long result = 1;
    for (bits -= 1; bits > 0; --bits)
        result *= 2;
    return result - 1;
}

unsigned long long unsigned_max(int bits)
{
    unsigned long long result = 1;
    for (; bits > 0; --bits)
        result *= 2;
    return result - 1;
}
