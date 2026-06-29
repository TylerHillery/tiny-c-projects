#include <stdio.h>

int tohex(char c) {
  if (c >= '0' && c <= '9') {
    return (c - '0');
  }
  if (c >= 'A' && c <= 'F') {
    return (c - 'A' + 0xA);
  }
  if (c >= 'a' && c <= 'f') {
    return (c - 'a' + 0xA);
  }
  return -1;
}

int main(void) {
  while (1) {
    int ch = getchar();
    if (ch == EOF) break;
    int a = tohex(ch);
    if (a < 0) break;
    a <<=4;
    ch = getchar();
    if (ch == EOF) break;
    int b = tohex(ch);
    if (b < 0) break;
    putchar(a+b);
  }
}