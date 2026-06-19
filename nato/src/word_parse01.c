#include <stdio.h>
#include <string.h>

int main() {

  char sometext[64];
  char *match;

  printf("Type some text: ");
  fgets(sometext, 64, stdin);


  /*
   * Question: I assume strtok is not thread safe because it must keep some
   * internal state to be able to continue to work on the original char * that 
   * was passed in
   */
  match = strtok(sometext, " ");
  while (match) {
    printf("%s\n", match);
    match = strtok(NULL, " ");
  }

  return 0;
}