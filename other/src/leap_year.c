#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  char *endptr;
  long int num;

  if (argc < 2) {
    fprintf(stderr, "Please enter a year: leapyear <YYYY>\n");
    exit(EXIT_FAILURE);
  }

  num = strtol(argv[1], &endptr, 10);
  
  if (endptr == argv[1]) {
    fprintf(stderr, "Please enter a year: leapyear <YYYY>\n");
    exit(EXIT_FAILURE);
  } else if (*endptr != '\0') {
    fprintf(stderr, "Please enter a year: leapyear <YYYY>\n");
    exit(EXIT_FAILURE);
  } else if (num <= 0) {
    fprintf(stderr, "Please enter a year: leapyear <YYYY>\n");
    exit(EXIT_FAILURE);
  }

  if (num % 4 == 0 && (num % 100 != 0 || num % 400 == 0)) {
    printf("%ld is a leap year\n", num);  
  } else {
    printf("%ld is NOT a leap year\n", num);  
  }
  return EXIT_SUCCESS; 
}