#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 8

int main(void) {

  char buffer[MAX_PASSWORD_LENGTH + 1];

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

  char guess[line_length+1];

  unsigned long long total_guesses = 1;

  for (int i = 0; i < line_length; i++) {
    guess[i] = 'a';
    total_guesses *= 26;
  }

  guess[line_length] = '\0';

  for (int i = 0; i < total_guesses; i++) {
    unsigned long long divisor = 1ULL;
    // TODO Parallize
    for (int j = 0; j < line_length; j++) {
      guess[j] = 'a' + (i / divisor) % 26;
      divisor *= 26;
    }

    printf("\rCracking password: %s", guess);
    fflush(stdout);
    if (strncmp(buffer, guess, line_length) == 0) {
      printf("Found password!\n");
      return EXIT_SUCCESS;
    }
  }

  printf("Password not found :(\n");
  return EXIT_SUCCESS;
}