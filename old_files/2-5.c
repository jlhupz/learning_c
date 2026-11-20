/*
 * Date: 04/12/25
 * Author: Jefferson Lupac
 * Exercise 2-5. Write the function any(s1, s2), which returns the first location in the string
 * s1 where any character from string s2 occurs, or -1 if s1 contains no characters from
 * s2. 
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    int index;
    char s1[] = "aaaabbbbccccddddeeeeffffggggjjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz";
    char s2[] = "hi";

    if ((index = any(s1, s2)))
        printf("The string s2 character '%c' occcurs in the string s1 and it's first location is %d\n", s1[index], index); 
    else
        printf("None of the character in the string s2 occurs in the string s1.\n");

    if (1 - 2 == index)
        printf("True\n");
    else 
        printf("False\n");
    return 0;

}

int any(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; i++)
        for (int j = 0; s1[j] != '\0'; j++)
            if (s1[j] == s2[i])
                return j;
    return -1;
}
