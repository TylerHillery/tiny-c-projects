/*
 * Note: this code is not part of the book. When I started the chapter I like to
 * try to think ahead of what the author might have the "tiny project" be. In
 * this case I thought it would fun to take a string and convert each character
 * to the NATO equivalent.
 *
 * Edit: I was right, this turned about to be the exact project the author had
 * you do.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *nato[] = {
    "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrox", "Golf",
    "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

/*
 * Returns the alpha index of the char if the char is a-z e.g. a is 0, b is 1...
 * if the char is not alpha, return -1
 */
int get_alpha_index(char c) {
  /*
   * Review:
   * - Could have used toupper instead of (c & ~32)
   * - Could have used isalpha(c) instead of checking the bounds
   */
  int i = (c & ~32) - 'A';
  return i >= 0 && i < 26 ? i : -1;
}

/*
 * Pass in a string and it will convert each character into the nato
 * representation
 * - case insensitive
 * - ignores not alpabetic characters
 * - returns array of char * pointers, NULL pointer indicates end of array
 * - caller is responsible for freeing everything
 */
char **word_to_nato(char *s) {
  size_t len = strlen(s);

  // one extra for null ptr to end the array
  char **result = (char **)malloc(sizeof(char *) * len + 1);
  if (result == NULL) {
    perror("malloc");
    return NULL;
  }

  for (int i = 0; i < len; i++) {
    // get the alpha index of the char
    int alpha_index = get_alpha_index(s[i]);
    if (alpha_index == -1) {
      result[i] = strndup(&s[i], 1);
    } else {
      result[i] = strdup(nato[alpha_index]);
    }
  }
  result[len] = NULL;
  return result;
}

int main(void) {
  char **words = word_to_nato("Hello, Tyler!");
  for (int i = 0; words[i] != NULL; i++) {
    if (i != 0 && strlen(words[i]) != 1)
      printf(" ");
    printf("%s", words[i]);
  }
  printf("\n");
}