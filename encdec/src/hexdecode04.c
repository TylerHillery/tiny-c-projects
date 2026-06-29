#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 18
#define LENGTH (BYTES_PER_LINE * 3 + 4)

int main() {
  char line[LENGTH];
  int x, ch;
  int checksum, row;
  float version;
  char *r;

  r = fgets(line, LENGTH, stdin);
  if (r == NULL || strncmp(line, "HEX ENCODE", 10) != 0) {
    fprintf(stderr, "Invalid HEX ENCODE data\n");
    exit(EXIT_FAILURE);
  }

  sscanf(line, "HEX ENCODE v%f", &version);

  x = 0;
  row = 0;
  while ((ch = getchar()) != EOF) {
    line[x] = ch;
    x++;
    if (ch == '\n' || x == LENGTH) {
      if (line[x - 1] == '\n') {
        line[x - 1] = '\0';
      } else {
        line[x] = '\0';
      }

      if (strncmp(line, "HEX ENCODE END", 13) == 0) {
        break;
      }

      checksum = 0;
      {
        unsigned int values[BYTES_PER_LINE + 1];
        int count = 0;
        char *p = line;

        while (*p != '\0') {
          while (*p == ' ' || *p == '\t') {
            p++;
          }
          if (*p == '\0') {
            break;
          }

          if (!isxdigit((unsigned char)p[0]) ||
              !isxdigit((unsigned char)p[1])) {
            fprintf(stderr, "\nInvalid hex data at Line %d\n", row + 1);
            fprintf(stderr, "Unable to decode data\n");
            exit(EXIT_FAILURE);
          }

          if (count >= BYTES_PER_LINE + 1) {
            fprintf(stderr, "\nToo many bytes at Line %d\n", row + 1);
            fprintf(stderr, "Unable to decode data\n");
            exit(EXIT_FAILURE);
          }

          {
            char byte_text[3] = {p[0], p[1], '\0'};
            sscanf(byte_text, "%2X", &values[count]);
          }

          count++;
          p += 2;
        }

        if (count < 1) {
          fprintf(stderr, "\nMissing checksum at Line %d\n", row + 1);
          fprintf(stderr, "Unable to decode data\n");
          exit(EXIT_FAILURE);
        }

        for (int i = 0; i < count - 1; i++) {
          checksum += values[i];
          putchar((char)values[i]);
        }

        if (values[count - 1] != (unsigned int)(checksum % 0x100)) {
          fprintf(stderr, "\nChecksum error at Line %d\n", row + 1);
          fprintf(stderr, "Unable to decode data\n");
          exit(EXIT_FAILURE);
        }
      }
      x = 0;
      row++;
    }
  }
  return 0;
}