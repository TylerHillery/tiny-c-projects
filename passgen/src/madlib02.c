#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 32

struct term {
  char filename[24];
  FILE *fp;
  int items;
  char **list_base;
};

void build_vocabulary(struct term *t) {
  char buffer[BSIZE];
  char *r, *entry;

  int capacity = 100;

  t->fp = fopen(t->filename, "r");
  if (t->fp == NULL) {
    fprintf(stderr, "Unable to open file %s\n", t->filename);
    exit(EXIT_FAILURE);
  }

  t->list_base = malloc(sizeof(char *) * capacity);
  if (t->list_base == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  t->items = 0;
  while ((r = fgets(buffer, BSIZE, t->fp)) != NULL) {
    entry = strdup(buffer);
    if (entry == NULL) {
      free(t->list_base);
      perror("strdup");
      exit(EXIT_FAILURE);
    }

    r = entry;
    while (*r) {
      if (*r == '\n') {
        *r = '\0';
        break;
      }
      r++;
    }

    t->list_base[t->items] = entry;
    t->items++;
    if (t->items % capacity) {
      char **tmp = realloc(t->list_base, sizeof(char *) * capacity * 2);
      if (tmp == NULL) {
        perror("realloc");
        free(t->list_base);
        exit(EXIT_FAILURE);
      }
      t->list_base = tmp;
      capacity *= 2;
    }
  }
  fclose(t->fp);
}

char *add_word(struct term t) {
  int word;
  word = rand() % t.items;
  return t.list_base[word];
}

int main(void) {
  struct term noun = {"src/noun.txt", NULL, 0, NULL};
  struct term verb = {"src/verb.txt", NULL, 0, NULL};
  struct term adj = {"src/adjective.txt", NULL, 0, NULL};

  build_vocabulary(&noun);
  build_vocabulary(&verb);
  build_vocabulary(&adj);

  srand((unsigned)time(NULL));

  printf("Will you please take the %s %s ", add_word(adj), add_word(noun));
  printf("and %s the %s?\n", add_word(verb), add_word(noun));
}