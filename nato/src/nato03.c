#include "word_parse01.h"
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[64];
  char *match;
  char ch;
  printf("NATO word or phrase: ");
  fgets(phrase, 64, stdin);

  match = strtok(phrase, " ");

  /*
   * Question: I assume strtok is not thread safe because it must keep some
   * internal state to be able to continue to work on the original char * that
   * was passed in
   */
  while (match) {
    if ((ch = isterm(match)) != '\0') {
      putchar(ch);
    }
    match = strtok(NULL, " ");
  }
  putchar('\n');
  return 0;
}
