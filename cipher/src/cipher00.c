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

int cipher(int c) {
  if (!isalpha(c))
    return c;
  int base_index = toupper(c) - 'A';
  int new_index = (base_index + 13) % 26;
  int conversion = toupper(c) == c ? new_index + 'A' : new_index + 'a';
  return conversion;
}

int main(int argc, char *argv[]) {
  int c;

  while ((c = getchar()) != EOF) {
    printf("%c", cipher(c));
  }
  return EXIT_SUCCESS;
}