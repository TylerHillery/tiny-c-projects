#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int needsEncoding(char c) { 
    if (isalpha(c)) {
        return 0;
    }
    if (c == '-' || c == '.' || c == '_' || c == '*') {
        return 0;
    }

    return 1; 
}

int main() {
  char c;

  while ((c = getchar()) != EOF) {
    // if
    if (!needsEncoding(c)) {
        printf("%c", c);
    } else {
        printf("%%%02X", c);
    } 
  }
  putchar('\n');
  return EXIT_SUCCESS;
}