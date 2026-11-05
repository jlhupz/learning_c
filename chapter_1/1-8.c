/*
 * Exercise 1-8. Program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main() {
  unsigned int nBlanks, nTabs, nLines;
  int c;

  nBlanks = nTabs = 0;
  nLines = 1;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++nBlanks;
    } else if (c == '\t') {
      ++nTabs;
    } else if (c == '\n') {
      ++nLines;
    }
  }

  printf("\nBlanks: \t%u\n", nBlanks);
  printf("Tabs: \t%u\n", nTabs);
  printf("Lines: \t%u\n", nLines);
  return 0;
}
