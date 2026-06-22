#include <stdio.h>

int main() {
  int a, b;

  /*
   * This illustrates common mistake with streams. When you type a letter for this
   * first char, a, and hit "enter", enter counts as the next char so the program
   * is going to finish. If you type xy in the get first "Type a letter" a = x 
   * and b = y
   */
  printf("Type a letter: ");
  a = getchar();
  printf("Type a letter: ");
  b = getchar();

  printf("a='%c', b='%c'", a, b);
  return (0);
}