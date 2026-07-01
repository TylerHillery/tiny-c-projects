#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

#define MAX_PASSWORD_LENGTH 8

int run(void *arg) {
  for (int i = 'a'; i <= 'z'; i++) {
    if (i == *(char *)arg) {
      return i;
    }
  }
  return -1;
}

int main(void) {

  char buffer[MAX_PASSWORD_LENGTH + 1];
  int password_found = 1;

  printf("Please enter you password: ");
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    fprintf(stderr, "Didn't enter in a password, exiting...\n");
    return EXIT_FAILURE;
  }

  int line_length = strlen(buffer);

  if (buffer[line_length - 1] == '\n') {
    buffer[line_length - 1] = '\0';
    line_length--;
  }

  thrd_t threads[line_length];
  char guess[line_length + 1];
  guess[line_length] = '\0';

  for (int i = 0; i < line_length; i++) {
    thrd_create(threads + i, run, buffer + i);
  }

  for (int i = 0; i < line_length; i++) {
    int rc;
    thrd_join(threads[i], &rc);

    if (rc == -1) {
      password_found = 0;
      break;
    } else {
      guess[i] = (char)rc;
    }
  }

  if (password_found) {
    printf("We cracked you password: %s\n", (char *)guess);
  } else {
    printf("We couldn't crack you password\n");
  }

  return EXIT_SUCCESS;
}