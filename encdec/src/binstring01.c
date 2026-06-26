#include <stdio.h>
#include <stdlib.h>

char *binstring(int i) {
  // we will only handle 1 byte
  if (i > 255)
    return NULL;

  char *result = malloc(9);
  if (result == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  for (int j = 0; j < 8; j++) {
    int divisor = (1 << (7 - j));
    result[j] = (i / divisor) + '0';
    i %= divisor;
  }
  result[8] = '\0';
  return result;
}

int main(void) {
  printf("%s\n", binstring(255));
  printf("%s\n", binstring(1));
  printf("%s\n", binstring(128));
  printf("%s\n", binstring(64));
}