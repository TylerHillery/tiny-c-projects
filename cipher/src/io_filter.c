#include <stdio.h>

int main() {
    // have to use int because EOF is an integer type.
    int ch;

    while( (ch = getchar()) != EOF) {
        // do nothing filter
        putchar(ch);
    }

    return(0);

}