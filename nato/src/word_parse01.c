#include <stdio.h>
#include <string.h>

char isterm(char *term) {

  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrox", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  const char *n, *t;

  /*
   * we can optimzie this, there is no need to loop through all nato words
   * instead we can just compare the word with the letter it starts with
   */
  int alpha_index = (*term | 0x20) - 'a';

  if (alpha_index < 0 || alpha_index > 25)
    return '\0';

  n = nato[alpha_index];
  t = term;
  // strcmp is not case insensitive so we compare char by char instead
  while (*n != '\0') {
    if ((*n | 0x20) != (*t | 0x20))
      return '\0';
    n++;
    t++;
  }
  return *nato[alpha_index];
}