#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() { 
    char ch;
    const int length = 10;

    srand((unsigned)time(NULL));

    for (int x = 0; x < length; x++){
        ch = rand() % ('~' - '!' + 1);
        putchar(ch+'!');
    }
    putchar('\n');
    return EXIT_SUCCESS;
}