#include <stdio.h>

/* Count the number of characters and newlines */

int main() {
  unsigned int nc = 0;
  unsigned int nl = 0;
  int c;

  /* Count the number of characters. */
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
  }

  // Print the number of characters and lines count.
  printf("\nNumber of characters %u", nc);
  printf("\nNumber of lines %u\n", nl);

  return 0;
}
