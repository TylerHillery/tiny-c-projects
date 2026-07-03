#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_LENGTH 16

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Please enter a file name, Usage: dumpfile <filename>\n");
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "rb");

  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  int capacity = 256;
  unsigned char *data = malloc(capacity);
  char buffer[ROW_LENGTH + 1];
  buffer[ROW_LENGTH] = '\0';
  int c;
  int n = 0;

  srand((unsigned)time(NULL));

  while ((c = getc(fp)) != EOF) {
    if (n == capacity) {
      capacity *= 2;
      unsigned char *tmp = realloc(data, capacity);
      if (tmp == NULL) {
        free(data);
        perror("realloc");
        return EXIT_FAILURE;
      }
      data = tmp;
    }
    data[n] = (unsigned char)c;
    n++;
  }

  int b;
  for (b = 0; b < n; b++) {
    if ((b % ROW_LENGTH) == 0) {
      printf("%05X  ", b);
    }
    printf("%02X", data[b]);
    buffer[b % ROW_LENGTH] =
        (data[b] != '\n' && isprint(data[b])) ? (char)data[b] : '.';

    if (((b + 1) % ROW_LENGTH) == 0) {
      printf(" %s\n", buffer);
    } else if (((b + 1) % (ROW_LENGTH / 2)) == 0) {
      printf("  ");
    } else {
      putchar(' ');
    }
  }
  int left_over = (b % ROW_LENGTH);
  if (left_over != 0) {
    buffer[left_over] = '\0';
    for (int i = left_over; i < ROW_LENGTH; i++) {
      printf("   ");
      if (i == ROW_LENGTH / 2 - 1) {
        printf(" ");
      }
    }
    printf(" %s\n", buffer);
  }

  fclose(fp);
  free(data);
  return EXIT_SUCCESS;
}
