#include <stdio.h>

int main(void) {
  int rows = 33;
  int cols = 4;

  const char *header =
      "Dec Oct Hex C   Dec Oct Hex C   Dec Oct Hex C   Dec Oct Hex C\n";
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (row == 0) {
        printf("%s", header);
        col += 3;
        continue;
      }
      int c = (col * 32) + row - 1;
      printf("%3d %3o %3x %c", c, c, c, c < 32 ? '-' : c);
      if (col != 3) {
        printf(" | ");
      } else {
        printf("\n");
      }
    }
  }
}