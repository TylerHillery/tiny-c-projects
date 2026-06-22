#include <ctype.h>
#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
        printf("\n----------\n");
        continue;
    }
    if (!isalpha(c)) {
      printf("%c", c);
    }
    int upper = ~(0x20) & c;
    printf("%c", upper);
  }
}