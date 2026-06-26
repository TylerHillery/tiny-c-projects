#include <stdio.h>
#include <stdlib.h>

int main() {
    int ch;

    while ((ch = getchar()) != EOF) {
        printf("%02x", ch);
    }
    putchar('\n');
    return EXIT_SUCCESS;
}