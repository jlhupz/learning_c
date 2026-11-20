/*
 * Date: 04/10/25
 * Author: Jefferson Lupac
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each character 
 * in s1 that matches any character in the string s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzz";
    char s2[] = "jeff";

    squeeze(s1, s2);
    printf("%s\n", s1); 

    return 0;

}

void squeeze(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; i++) {
        int k = 0; 
        
        for (int j = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];

        s1[k] = '\0';
    }
}
