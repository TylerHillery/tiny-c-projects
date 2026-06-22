#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
  int c;

  srand(time(NULL));

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
        printf("\n----------\n");
        continue;
    }
    if (!isalpha(c)) {
      printf("%c", c);
    }

    int conversion = rand() % 2 ? ~(0x20) & c : (0x20) | c;  
    printf("%c", conversion);
  }
}