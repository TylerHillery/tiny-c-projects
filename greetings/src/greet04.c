#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int random_number(int max) {
  if (max <= 0)
    return 0;
  return rand() % max;
}

char *get_random_phrase() {
  size_t capacity = 8;

  char line[MAX_LINE_LENGTH];
  FILE *fp = fopen("pithy.txt", "r");
  int linecount = 0;

  if (fp == NULL) {
    return "Could not open pithy.txt";
  }

  char **phrases = malloc(capacity * sizeof(char *));
  char **tmp = NULL;

  if (phrases == NULL) {
    return NULL;
  }

  while ((fgets(line, MAX_LINE_LENGTH, fp)) != NULL) {
    if ((size_t)linecount == capacity) {
      tmp = realloc(phrases, capacity * 2 * sizeof(char *));
      if (tmp == NULL) {
        for (int i = 0; i < linecount; i++) {
          free(phrases[i]);
        }
        free(phrases);
        return NULL;
      }
      capacity *= 2;
      phrases = tmp;
      tmp = NULL;
    }
    phrases[linecount] = strdup(line);
    linecount++;
  }

  fclose(fp);

  if (linecount == 0)
    return "No phrases found";

  char *result = strdup(phrases[random_number(linecount)]);

  for (int i = 0; i < linecount; i++) {
    free(phrases[i]);
  }
  free(phrases);

  return result;
}

int main() {
  srand((unsigned)time(NULL));
  char *phrase = get_random_phrase();
  printf("%s", get_random_phrase());
  free(phrase);
}