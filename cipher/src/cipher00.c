#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Note: My attempt at writing this cipher with only reading the intro part of
 * this chapter. Sounds like this cipher just rotates each character 13 spaces.
 * I will write a function that takes in a char *, iterates over each character
 * and moves them 13 spaces returning a new char *.
 */

char *cipher(char *s) {
  char *result = strdup(s);
  for (int i = 0; s[i] != '\0'; i++) {
    // for now lets not convert nonalpha chars
    if (!isalpha(s[i])) {
      result[i] = s[i];
      continue;
    }
    int base_index = toupper(s[i]) - 'A';
    // can overflow so we mod 26 to wrap around
    int new_index = (base_index + 13) % 26;
    int conversion =
        toupper(s[i]) == (int)s[i] ? new_index + 'A' : new_index + 'a';
    // debug
    // printf("%c: %02i -> %c, %i\n", s[i], base_index, conversion, new_index);
    result[i] = conversion;
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr,
            "Please enter a string to encode. Usage: cipher <string>\n");
    return EXIT_FAILURE;
  }

  char *encoded_message = cipher(argv[1]);
  printf("%s -> %s\n", argv[1], encoded_message);
  free(encoded_message);
  encoded_message = NULL;
  return EXIT_SUCCESS;
}