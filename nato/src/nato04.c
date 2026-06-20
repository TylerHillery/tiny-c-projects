#include "word_parse01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *n;
  char phrase[64];
  char *match, ch;

  if (argc < 2) {
    fprintf(stderr, "Please supply a text file argument\n");
    exit(1);
  }

  n = fopen(argv[1], "r");
  if (n == NULL) {
    fprintf(stderr, "Unable to open file %s", argv[1]);
    return EXIT_FAILURE;
  }

  while (fgets(phrase, 64, n) != NULL) {
    match = strtok(phrase, " ,.!?=()[]{}'\"");
    while (match) {
      if ((ch = isterm(match)) != '\0') {
        putchar(ch);
      }
      match = strtok(NULL, " ,.!?=()[]{}'\"");
    }
  }
  putchar('\n');
  fclose(n);
}