#include <stdio.h>
#include <string.h>

char isterm(char *term) {

  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrox", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  int x;
  const char *n, *t;

  for (x = 0; x < (int)(sizeof(nato) / sizeof(nato[0])); x++) {
    n = nato[x];
    t = term;
    while (*n != '\0') {
      if ((*n | 0x20) != (*t | 0x20))
        break;
      n++;
      t++;
    }
    if (*n == '\0') {
      return *nato[x];
    }
  }
  return '\0';
}