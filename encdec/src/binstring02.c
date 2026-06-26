#include <stdio.h>

char *binstring(char a) {
  static char b[9];
  int i = 0;
  while (i < 8) {
    b[i] = a & 0x80 ? '1' : '0';
    a <<= 1;
    i++;
  }
  b[i] = '\0';
  return b;
}

int main(void) {
    printf("%s\n", binstring(255));
    printf("%s\n", binstring(1));
    printf("%s\n", binstring(64));
}